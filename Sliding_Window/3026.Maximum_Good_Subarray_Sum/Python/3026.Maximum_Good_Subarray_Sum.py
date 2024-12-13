class Solution(object):
    def maximumSubarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #========================================#
        # One-pass record based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [0 for _ in range((len_nums + 1))]

        for nums_idx in range(1, (len_nums + 1)):
            record_dp[nums_idx] = (record_dp[(nums_idx - 1)] + nums[nums_idx - 1])

        ##### Result maximun summary value #####
        res_max_sum = (((-1) * (10 ** 14)) - 1)


        #######################################################################
        #One-pass record based loop traversal with recorded dictionary/hashmap
        for nums_idx in range(len_nums):

            ##### Check if the current differenced-value existed or not #####
            if ((nums[nums_idx] - k) in record_dict):

                ##### Check if the current summary value is larger or not #####
                if ((record_dp[(nums_idx + 1)] - record_dp[record_dict[(nums[nums_idx] - k)]]) > res_max_sum):
                    res_max_sum = (record_dp[(nums_idx + 1)] - record_dp[record_dict[(nums[nums_idx] - k)]]) #Keep updating/overwriting
                else:
                    pass
            else:
                pass

            ##### Check if the current differenced-value existed or not #####
            if ((nums[nums_idx] + k) in record_dict):

                ##### Check if the current summary value is larger or not #####
                if ((record_dp[(nums_idx + 1)] - record_dp[record_dict[(nums[nums_idx] + k)]]) > res_max_sum):
                    res_max_sum = (record_dp[(nums_idx + 1)] - record_dp[record_dict[(nums[nums_idx] + k)]]) #Keep updating/overwriting
                else:
                    pass
            else:
                pass
        
            ##### Check if the current indexed-value existed or not #####
            if (nums[nums_idx] in record_dict):

                ##### Check if the current summary value is larger or not #####
                if (record_dp[(record_dict[nums[nums_idx]] + 1)] < record_dp[(nums_idx + 1)]):
                    pass
                else:
                    record_dict[nums[nums_idx]] = nums_idx #Keep updating/recording
            else:
                record_dict[nums[nums_idx]] = nums_idx #Keep updating/recording

        return (res_max_sum if ((res_max_sum != (((-1) * (10 ** 14)) - 1))) else 0)
