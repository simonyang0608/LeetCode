class Solution(object):
    def minFallingPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record dynamic-programming array #####
        record_dp = deepcopy(grid)

        ##### Result minimun summary value #####
        res_min_sum = float("inf")


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for rows_idx in range((len_rows - 2), (-1), (-1)):
            record_pq = [] #Record heap/priority-queue

            heapify(record_pq) #Keep updating/heapify

            next_minor_min = (10 ** 7) #Next minor minimun value

            for cols_idx in range(len_cols):

                ##### Check if the current heap/priority-queue is empty or not #####
                if (record_pq):

                    ##### Check if the current indexed-values informations matched conditions or not #####
                    if ((record_dp[(rows_idx + 1)])[cols_idx] < (record_pq[0])[0]):
                        next_minor_min = (record_pq[0])[0] #Keep updating/overwriting

                        heappop(record_pq) #Keep updating/popped

                        heappush(record_pq, ((record_dp[(rows_idx + 1)])[cols_idx], cols_idx)) #Keep updating/recording

                    elif ((record_dp[(rows_idx + 1)])[cols_idx] < next_minor_min):
                        next_minor_min = (record_dp[(rows_idx + 1)])[cols_idx] #Keep updating/overwriting
                    else:
                        pass
                else:
                    heappush(record_pq, ((record_dp[(rows_idx + 1)])[cols_idx], cols_idx)) #Keep updating/recording

            next_major_min, next_idx = (record_pq[0])[0], (record_pq[0])[1] #Next major minimun value, index

            (record_dp[rows_idx])[next_idx] += next_minor_min #Keep updating/accumulating

            ##### Check if the current rows index matched conditions or not #####
            if (not rows_idx):
                res_min_sum = min(res_min_sum, (record_dp[rows_idx])[next_idx]) #Keep updating/overwriting
            else:
                pass

            for cols_idx in range(len_cols):

                ##### Check if the current columns index matched conditions or not #####
                if (cols_idx == next_idx):
                    continue

                (record_dp[rows_idx])[cols_idx] += next_major_min #Keep updating/accumulating

                ##### Check if the current rows index matched conditions or not #####
                if (not rows_idx):
                    res_min_sum = min(res_min_sum, (record_dp[rows_idx])[cols_idx]) #Keep updating/overwriting
                else:
                    pass

        return ((grid[0])[0] if (res_min_sum == float("inf")) else res_min_sum)
