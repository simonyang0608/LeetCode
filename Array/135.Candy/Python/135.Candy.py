class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of ratings array #####
        len_ratings = len(ratings)

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [1 for _ in range(len_ratings)]

        ##### Record priority-queue #####
        record_pq = []

        heapify(record_pq)


        ##################################################################################
        #Heap/Priority-queue based loop traversal with recorded dynamic-programming array
        ##### Step 1: Record indexed-value with dynamic-programming array
        for ratings_idx in range(len_ratings):
            heappush(record_pq, [ratings[ratings_idx], ratings_idx]) #Keep updating, recording

        ##### Step 2: Looped-traversal with recorded dynamic-programming array #####
        while (record_pq):
            record_idx = (heappop(record_pq)[1]) #Record index

            ##### Check if the current edges boundary exceed or not #####
            if ((record_idx - 1) >= 0):

                ##### Check if the current indexed-value matched conditions or not #####
                if (ratings[record_idx] > ratings[(record_idx - 1)]):
                    record_dp[record_idx] = max(record_dp[record_idx], (record_dp[(record_idx - 1)] + 1)) #Keep updating/overwriting
                else:
                    pass
            else:
                pass

            if ((record_idx + 1) < len_ratings):

                ##### Check if the current indexed-value matched conditions or not #####
                if (ratings[record_idx] > ratings[(record_idx + 1)]):
                    record_dp[record_idx] = max(record_dp[record_idx], (record_dp[(record_idx + 1)] + 1)) #Keep updating/overwriting
                else:
                    pass
            else:
                pass

        return sum(record_dp)
