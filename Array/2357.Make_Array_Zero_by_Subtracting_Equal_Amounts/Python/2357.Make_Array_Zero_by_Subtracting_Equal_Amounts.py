class Solution(object):
    def minimumOperations(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #=================================#
        # Hash-set based traversal method #
        #=================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result summary counter #####
        res_cnter = 0


        ###############################
        #Hash-set based loop traversal
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value is 0 or not #####
            if (not nums[nums_idx]):
                continue

            ##### Check if the current indexed-value existed or not #####
            if (nums[nums_idx] in record_dict):
                continue

            record_dict[nums[nums_idx]] = True #Keep updating/recording

            res_cnter += 1 #Keep updating/accumulating

        return res_cnter
