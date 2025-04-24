class Solution(object):
    def findSmallestSetOfVertices(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### In-degree array #####
        in_degree = [0 for _ in range(n)]

        ##### Result array #####
        res_arry = []


        #############################
        #Greedy-based loop traversal
        ##### Step 1: Record indexed-nodes informations with array #####
        for edges_idx in range(len_edges):
            in_degree[(edges[edges_idx])[1]] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array #####
        for n_idx in range(n):

            ##### Check if the current nodes' in-degree matched conditions or not #####
            if (not in_degree[n_idx]):
                res_arry.append(n_idx) #Keep updating/recording
            else:
                pass

        return res_arry
