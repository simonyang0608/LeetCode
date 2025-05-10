class Solution(object):
    def lengthOfLongestSubsequence(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [(-1) for _ in range((target + 1))]


        ##########################################
        #Dynamic-programming based loop traversal
        record_dp[0] = 0 #Update/Overwrite

        for nums_idx in range(len_nums):
            record_diff = (target - nums[nums_idx]) #Record difference

            for record_idx in range(record_diff, (-1), (-1)):

                ##### Check if the current summary counter matched conditions or not #####
                if (record_dp[record_idx] >= 0):
                    record_dp[(record_idx + nums[nums_idx])] = max(record_dp[(record_idx + nums[nums_idx])], 
                                                                  (record_dp[record_idx] + 1)) #Keep updating/overwriting
                else:
                    pass

        return record_dp[(-1)]
