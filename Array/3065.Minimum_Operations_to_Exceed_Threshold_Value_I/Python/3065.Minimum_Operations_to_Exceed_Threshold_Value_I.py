class Solution(object):
    def minOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #=========================================#
        # One-pass compare based traversal method #
        #=========================================#
        if (min(nums) >= k): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Result summary counter #####
        res_cnter = 0


        #######################################
        #One-pass compare based loop traversal
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[nums_idx] < k):
                res_cnter += 1 #Keep updating/accumulating
            else:
                pass

        return res_cnter
