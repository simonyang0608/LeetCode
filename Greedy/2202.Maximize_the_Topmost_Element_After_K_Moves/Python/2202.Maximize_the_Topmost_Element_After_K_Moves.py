class Solution(object):
    def maximumTop(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        if ((len_nums == 1) and ((k % 2))): #Issue/Boundary-case handling
            return (-1)

        if (k > len_nums): #Issue/Boundary-case handling
            return max(nums)

        ##### Result maximun value #####
        res_max_val = (-1)


        #############################
        #Greedy-based loop traversal
        for nums_idx in range((k - 1)):
            res_max_val = max(res_max_val, nums[nums_idx]) #Keep updating/overwriting

        ##### Check if the current operations times matched conditions or not #####
        if (k < len_nums):
            res_max_val = max(res_max_val, nums[k]) #Keep updating/overwriting
        else:
            pass

        return res_max_val
