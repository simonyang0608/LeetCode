class Solution(object):
    def maxScore(self, nums, x):
        """
        :type nums: List[int]
        :type x: int
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dynamic-programming (i.e. odd, even) #####
        record_dp_odd = (nums[0] - (0 if (nums[0] % 2) else x))
        record_dp_even = (nums[0] - (0 if (not (nums[0] % 2)) else x))


        ##########################################
        #Dynamic-programming based loop traversal
        for nums_idx in range(1, len_nums):

            ##### Check if the current indexed-value is odd or even #####
            if ((nums[nums_idx] % 2)):
                record_dp_odd = max((record_dp_odd + nums[nums_idx]), ((record_dp_even + nums[nums_idx]) - x)) #Keep updating/overwriting
            else:
                record_dp_even = max((record_dp_even + nums[nums_idx]), ((record_dp_odd + nums[nums_idx]) - x)) #Keep updating/overwriting

        return max(record_dp_odd, record_dp_even)
