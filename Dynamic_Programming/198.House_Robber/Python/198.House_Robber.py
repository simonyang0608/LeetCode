class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dynamic-programming array #####
        record_dp = [0 for _ in range((len_nums + 1))]


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        record_dp[1] = nums[0] #Update/Overwrite

        for nums_idx in range(2, (len_nums + 1)):
            record_dp[nums_idx] = record_dp[(nums_idx - 1)] #Keep updating/transferring

            record_dp[nums_idx] = max(record_dp[nums_idx], (record_dp[(nums_idx - 2)] + nums[(nums_idx - 1)])) #Update/Overwrite

        return record_dp[len_nums]
