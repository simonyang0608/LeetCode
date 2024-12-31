class Solution(object):
    def minimalKSum(self, nums, k):
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

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result minimun summary value #####
        res_min_sum = ((k * (k + 1)) // 2)


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for nums_idx in range(len_nums):
            record_dict[nums[nums_idx]] = True #Keep updating/recording
        
        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for num in sorted(record_dict.keys()):

            ##### Check if the current indexed-value is valid or not #####
            if (num > k):
                break

            res_min_sum -= num #Keep pdating/reducing

            res_min_sum += (k + 1) #Keep updating/accumulating

            k += 1 #Keep updating/accumulating

        return res_min_sum
