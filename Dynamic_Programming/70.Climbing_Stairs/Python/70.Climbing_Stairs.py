class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#
        if ((n == 1) or (n == 2)): #Issue/Boundary-case handling
            return n

        ############
        #Initialize
        ##### N-th length #####
        n += 1

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [0 for _ in range(n)]

        record_dp[1] = 1
        record_dp[2] = 2


        ##########################################
        #Dynamic-programming based loop traversal
        for dp_idx in range(3, n):
            record_dp[dp_idx] = (record_dp[(dp_idx - 1)] + record_dp[(dp_idx - 2)]) #Keep updating/overwriting

        return record_dp[(n - 1)]
