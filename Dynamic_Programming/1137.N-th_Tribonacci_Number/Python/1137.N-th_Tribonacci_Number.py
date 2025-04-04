class Solution(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#
        if (not n): #Issue/Boundary-case handling
            return 0
        
        if (n <= 2): #Issue/Boundary-case handling
            return 1


        ############
        #Initialize
        ##### Record dynamic-programming array #####
        record_dp = [0 for _ in range((n + 1))]

        ####################
        #Whole process/flow
        record_dp[0] = 0 #Update/Overwrite
        record_dp[1] = 1 #Update/Overwrite
        record_dp[2] = 1 #Update/Overwrite

        for n_idx in range(3, (n + 1)):
            record_dp[n_idx] = (record_dp[(n_idx - 1)] + record_dp[(n_idx - 2)] + record_dp[n_idx - 3]) #Keep updating/overwriting

        return record_dp[n]
