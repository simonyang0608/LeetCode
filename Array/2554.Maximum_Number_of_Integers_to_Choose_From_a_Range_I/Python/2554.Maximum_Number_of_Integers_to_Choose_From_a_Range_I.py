class Solution(object):
    def maxCount(self, banned, n, maxSum):
        """
        :type banned: List[int]
        :type n: int
        :type maxSum: int
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Record set #####
        record_set = set(banned)

        ##### Record dynamic-programming array #####
        record_dp = [0 for _ in range((n + 1))]

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ######################################################################
        #Dynamic-programming (i.e. DP) based loop traversal with recorded set
        for record_idx in range(1, (n + 1)):

            ##### Check if the current indexed-value existed or not #####
            if (record_idx in record_set):
                record_dp[record_idx] = record_dp[(record_idx - 1)] #Keep updating/overwriting

                continue

            record_dp[record_idx] = (record_dp[(record_idx - 1)] + record_idx) #Keep updating/overwriting

            ##### Check if the current summary value exceed boundary or not #####
            if (record_dp[record_idx] > maxSum):
                break

            res_max_cnter += 1 #Keep updating/accumulating

        return res_max_cnter
