class Solution(object):
    def longestCycle(self, edges):
        """
        :type edges: List[int]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Visit array #####
        visit_arry = [False for _ in range(len_edges)]

        ##### Length array #####
        length_arry = [(-1) for _ in range(len_edges)]

        ##### Result maximun length #####
        res_max_length = [(-1)]


        #########################################################
        #Recursion-based DFS loop traversal with recorded arrays
        for edges_idx in range(len_edges):

            ##### Check if the current node is visited or not #####
            if (visit_arry[edges_idx]):
                continue

            record_length = [0] #Keep updating/overwriting

            self.dfsTraversal(edges, edges_idx, visit_arry, length_arry, record_length, res_max_length) #Recursion function call

        return res_max_length[0]


    def dfsTraversal(self, edges, record_node, visit_arry, length_arry, record_length, res_max_length):
        """
        :type edges: List[int]
        :type record_node: int
        :type visit_arry: List[bool]
        :type length_arry: List[int]
        :type record_length: List[int]
        :type res_max_length: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (record_node == (-1)): #Issue/Boundary-case handling
            return

        ####################
        #Whole process/flow
        ##### Check if the current node is visited or not #####
        if (not visit_arry[record_node]):
            visit_arry[record_node] = True #Update/Record

            length_arry[record_node] = record_length[0] #Update/Overwrite

            record_length[0] += 1 #Update/Accumulate

            self.dfsTraversal(edges, edges[record_node], visit_arry, length_arry, record_length, res_max_length) #Recursion function call

        else:
            ##### Check if the length counter of current node matched conditions or not #####
            if (length_arry[record_node] != (-1)):
                res_max_length[0] = max(res_max_length[0], (record_length[0] - length_arry[record_node])) #Update/Overwrite
            else:
                pass

            return

        length_arry[record_node] = (-1) #Update/Overwrite

        return
