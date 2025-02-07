class Solution(object):
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        #========================================#
        # Two-pass update based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record mod #####
        record_mod = (k % len_nums)

        if (not record_mod): #Issue/Boundary-case handling
            return

        ##### Result nums array #####
        res_nums = [0 for _ in range(len_nums)]


        ######################################
        #Two-pass update based loop traversal
        for nums_idx in range(len_nums):
            res_nums[((nums_idx + record_mod) % len_nums)] = nums[nums_idx] #Keep updating/overwriting

        for nums_idx in range(len_nums):
            nums[nums_idx] = res_nums[nums_idx] #Keep updating/overwriting
