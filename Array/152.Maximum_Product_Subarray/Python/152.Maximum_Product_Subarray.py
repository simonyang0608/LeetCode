class Solution(object):
    def maxProduct(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#
        if (len(nums) <= 1): #Issue/Boundary-case handling
            return nums[0]

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record minimun, maximun product values #####
        record_min_prod, record_max_prod = nums[0], nums[0]

        ##### Result maximun product values #####
        res_max_prod = record_max_prod


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for nums_idx in range(1, len_nums):
            curr_max_prod = max((nums[nums_idx] * record_max_prod), nums[nums_idx], (nums[nums_idx] * record_min_prod)) #Current maximun product values

            record_min_prod = min((nums[nums_idx] * record_max_prod), nums[nums_idx], (nums[nums_idx] * record_min_prod)) #Keep updating/overwriting

            record_max_prod = curr_max_prod #Keep updating/overwriting

            res_max_prod = max(res_max_prod, record_max_prod) #Keep updating/overwriting

        return res_max_prod
