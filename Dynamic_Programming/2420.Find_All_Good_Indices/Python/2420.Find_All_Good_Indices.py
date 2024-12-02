class Solution(object):
    def goodIndices(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        #============================================#
        # Dynamic-programming-based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dynamic-programming array (i.e. decrease, increase) #####
        record_decr_dp, record_incr_dp = [1 for _ in range(len_nums)], [1 for _ in range(len_nums)]

        ##### Result array #####
        res_arry = []


        ##########################################
        #Dynamic-programming-based loop traversal
        len_nums -= 1 #Update/Reduce

        for decr_dp_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[(decr_dp_idx + 1)] <= nums[decr_dp_idx]):
                record_decr_dp[(decr_dp_idx + 1)] = (record_decr_dp[decr_dp_idx] + 1) #Keep updating/overwriting
            else:
                pass

        for incr_dp_idx in range(len_nums, 0, (-1)):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[(incr_dp_idx - 1)] <= nums[incr_dp_idx]):
                record_incr_dp[(incr_dp_idx - 1)] = (record_incr_dp[incr_dp_idx] + 1) #Keep updating/overwriting
            else:
                pass

        for nums_idx in range(1, len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if ((record_decr_dp[(nums_idx - 1)] >= k) and (record_incr_dp[(nums_idx + 1)] >= k)):
                res_arry.append(nums_idx) #Keep updating/recording
            else:
                pass

        return res_arry
