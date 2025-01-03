class Solution(object):
    def countCompleteComponents(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Visit array #####
        visit_arry = [0 for _ in range(n)]

        ##### Vertes, Edge #####
        vertex, edge = [0], [0]

        ##### Result summary counter #####
        res_cnter = 0


        #####################################################################
        #Recursion-based DFS loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record neighbors informations with dictionary/hashmap #####
        for edges_idx in range(len_edges):

            ##### Check if the current node existed or not #####
            if ((edges[edges_idx])[0] not in record_dict):
                (record_dict[(edges[edges_idx])[0]]) = [(edges[edges_idx])[1]] #Keep updating/recording
            else:
                (record_dict[(edges[edges_idx])[0]]).append((edges[edges_idx])[1]) #Keep updating/recording

            if ((edges[edges_idx])[1] not in record_dict):
                (record_dict[(edges[edges_idx])[1]]) = [(edges[edges_idx])[0]] #Keep updating/recording
            else:
                (record_dict[(edges[edges_idx])[1]]).append((edges[edges_idx])[0]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for n_idx in range(n):

            ##### Check if the current node is visited or not #####
            if (not visit_arry[n_idx]):
                self.dfsTraversal(record_dict, visit_arry, n_idx, vertex, edge) #Recursion function call

                ##### Check if the current condition is correct or not #####
                if ((vertex[0] * (vertex[0] - 1)) == edge[0]):
                    res_cnter += 1 #Keep updating/accumulating
                else:
                    pass

                vertex[0] = 0 #Keep updating/reset
                edge[0] = 0 #Keep updating/reset

            else:
                pass

        return res_cnter


    def dfsTraversal(self, record_dict, visit_arry, record_val, vertex, edge):
        """
        :type record_dict: dict
        :type visit_arry: List[int]
        :type edges: List[List[int]]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if (visit_arry[record_val]):
            return

        vertex[0] += 1

        visit_arry[record_val] = 1

        if (record_val in record_dict):
            for next_val in record_dict[record_val]:
                edge[0] += 1
            
                self.dfsTraversal(record_dict, visit_arry, next_val, vertex, edge)
