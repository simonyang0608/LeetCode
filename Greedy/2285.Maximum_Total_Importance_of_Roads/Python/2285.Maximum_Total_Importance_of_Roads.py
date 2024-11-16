class Solution(object):
    def maximumImportance(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of roads #####
        len_roads = len(roads)

        ##### Record array #####
        record_arry = [0 for _ in range(n)]

        ##### Result maximun summary importance #####
        res_max_sum = 0


        ########################################################
        #Greedy-based loop traversal with recorded sorted array
        ##### Step 1: Record indexed-value counter with array #####
        for roads_idx in range(len_roads):
            (record_arry[(roads[roads_idx])[0]]) += 1 #Keep updating/overwriting
            (record_arry[(roads[roads_idx])[1]]) += 1 #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded sorted array #####
        record_arry.sort() #Sorted operations

        for n_idx in range(n):
            res_max_sum += (record_arry[n_idx] * (n_idx + 1)) #Keep updating/accumulating

        return res_max_sum
