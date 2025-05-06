class Solution(object):
    def edgeScore(self, edges):
        """
        :type edges: List[int]
        :rtype: int
        """
        #==============================#
        # Greed-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of edges array #####
        len_edges = len(edges)

        ##### Record array #####
        record_arry = [0 for _ in range(len_edges)]

        ##### Record maximun score #####
        record_max_score = (-1)

        ##### Result minimun index #####
        res_min_idx = (-1)


        #################################################
        #Greedy-based loop traversal with recorded array
        ##### Step 1: Record indexed-nodes informations with array #####
        for edges_idx in range(len_edges):
            record_arry[edges[edges_idx]] += edges_idx #Keep updating/accumulating

        ##### Step 2: Looped-traversal with recorded array #####
        for edges_idx in range(len_edges):

            ##### Check if the current summary value matched conditions or not #####
            if (record_arry[edges_idx] > record_max_score):
                record_max_score = record_arry[edges_idx] #Keep updating/overwriting

                res_min_idx = edges_idx #Keep updating/overwriting
            else:
                pass

        return res_min_idx
