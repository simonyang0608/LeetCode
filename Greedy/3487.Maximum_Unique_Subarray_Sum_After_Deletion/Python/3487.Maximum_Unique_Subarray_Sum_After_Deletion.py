class Solution(object):
    def maxSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record maximun value #####
        record_max_val = (-101)

        ##### Result maximun summary value #####
        res_max_sum = 0


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        for nums_idx in range(len_nums):
            record_max_val = max(record_max_val, nums[nums_idx]) #Keep updating/overwriting

            ##### Check if the current indexed-value existed or not #####
            if (nums[nums_idx] <= 0):
                continue

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[nums_idx] in record_dict):
                continue

            record_dict[nums[nums_idx]] = True #Keep updating/recording

            res_max_sum += nums[nums_idx] #Keep updating/accumulating

        return (record_max_val if (record_max_val <= 0) else res_max_sum)
