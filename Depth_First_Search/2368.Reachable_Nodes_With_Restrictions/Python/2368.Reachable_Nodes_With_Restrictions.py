class Solution(object):
    def __init__(self):
        """
        :type: None, void
        :rtype: None, void
        """
        ############
        #Initialize
        ##### Result maximun summary counter #####
        self.res_max_cnter = 0


    def reachableNodes(self, n, edges, restricted):
        """
        :type n: int
        :type edges: List[List[int]]
        :type restricted: List[int]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of edges, restricted array #####
        len_edges, len_restricted = len(edges), len(restricted)

        ##### Visit array #####
        visit_arry = [0 for _ in range(n)]

        ##### Record dictionary/hashmap #####
        record_dict = {}


        ####################################
        #Recursion-based DFS loop traversal
        for restricted_idx in range(len_restricted):
            visit_arry[restricted[restricted_idx]] = 1 #Keep updating/overwriting

        for edges_idx in range(len_edges):
            first_node, second_node = (edges[edges_idx])[0], (edges[edges_idx])[1] #First, Second-node

            ##### Check if the current node value existed or not #####
            if (first_node not in record_dict):
                record_dict[first_node] = [second_node] #Keep updating/recording
            else:
                (record_dict[first_node]).append(second_node) #Keep updating/recording

            if (second_node not in record_dict):
                record_dict[second_node] = [first_node] #Keep updating/recording
            else:
                (record_dict[second_node]).append(first_node) #Keep updating/recording

        self.dfsTraversal(record_dict, visit_arry, 0) #Recursion function call

        return self.res_max_cnter


    def dfsTraversal(self, record_dict, visit_arry, record_val):
        """
        :type record_dict: dict
        :type visit_arry: List[int]
        :type record_val: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (visit_arry[record_val]): #Issue/Boundary-case handling
            return

        self.res_max_cnter += 1 #Update/Accumulate

        visit_arry[record_val] = 1 #Update/Overwrite

        
        ####################
        #Whole process/flow
        ##### Check if the current node-value existed or not #####
        if (record_val in record_dict):
            for next_val in record_dict[record_val]:
                self.dfsTraversal(record_dict, visit_arry, next_val) #Recursion function call
