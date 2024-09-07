class Solution(object):
    def maxTaxiEarnings(self, n, rides):
        """
        :type n: int
        :type rides: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of rides #####
        len_rides = len(rides)

        ##### N-th points #####
        n += 1

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record dynamic-programming array #####
        record_dp = [0 for _ in range(n)]

        ##### Record maximun summary counter #####
        record_max_cnter = 0


        ###########################################################################
        #Dynamic-programming based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for rides_idx in range(len_rides):
            curr_ride = rides[rides_idx] #Current rided position

            ##### Check if the current indexed-value existed or not #####
            if (curr_ride[1] not in record_dict):
                record_dict[curr_ride[1]] = [[curr_ride[0], ((curr_ride[1] - curr_ride[0]) + curr_ride[2])]] #Keep updating/recording
            else:
                record_dict[curr_ride[1]].append([curr_ride[0], ((curr_ride[1] - curr_ride[0]) + curr_ride[2])]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary #####
        for n_idx in range(1, n):
            record_dp[n_idx] = record_dp[(n_idx - 1)] #Keep updating/overwriting

            ##### Check if the current indexed-value existed or not #####
            if (n_idx in record_dict):
                for ([start_pos, total_earns]) in record_dict[n_idx]:
                    record_max_cnter = max(record_max_cnter, (total_earns + record_dp[start_pos])) #Keep updating/overwriting

                record_dp[n_idx] = max(record_dp[n_idx], record_max_cnter) #Keep updating/overwriting

            else:
                pass

            ##### Check if the current summary counter need to be reset or not #####
            if (record_max_cnter):
                record_max_cnter &= 0 #Keep updating/overwriting
            else:
                pass

        return record_dp[(-1)]
