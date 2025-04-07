class Solution(object):
    def minTime(self, n, edges, hasApple):
        """
        :type n: int
        :type edges: List[List[int]]
        :type hasApple: List[bool]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Visit array #####
        visit_arry = [False for _ in range(n)]


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        visit_arry[0] = True #Update/Overwrite

        for edges_idx in range(len_edges):
            curr_node, next_node = (edges[edges_idx])[0], (edges[edges_idx])[1] #Current, Next node

            ##### Check if the current node existed or not #####
            if (curr_node not in root_child_dict):
                root_child_dict[curr_node] = [next_node] #Keep updating/recording
            else:
                (root_child_dict[curr_node]).append(next_node) #Keep updating/recording

            ##### Check if the next node existed or not #####
            if (next_node not in root_child_dict):
                root_child_dict[next_node] = [curr_node] #Keep updating/recording
            else:
                (root_child_dict[next_node]).append(curr_node) #Keep updating/recording

        return self.dfsTraversal(root_child_dict, 0, visit_arry, hasApple)

        
    def dfsTraversal(self, root_child_dict, record_node, visit_arry, hasApple):
        """
        :type root_child_dict: dict
        :type record_node: int
        :type visit_arry: List[bool]
        :type hasApple: List[bool]
        :rtype: int
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#

        ############
        #Initialize
        ##### Result summary counter #####
        res_cnter = 0

        ####################
        #Whole process/flow
        if (record_node in root_child_dict):
            for next_node in root_child_dict[record_node]:

                ##### Check if the next node is visited or not #####
                if (not visit_arry[next_node]):
                    visit_arry[next_node] = True #Keep updating/overwriting

                    record_cnter = self.dfsTraversal(root_child_dict, next_node, visit_arry, hasApple) #Record summary counter

                    ##### Check if the current status matched conditions or not #####
                    if (record_cnter or hasApple[next_node]):
                        res_cnter += (record_cnter + 2) #Keep updating/accumulating

        return res_cnter
