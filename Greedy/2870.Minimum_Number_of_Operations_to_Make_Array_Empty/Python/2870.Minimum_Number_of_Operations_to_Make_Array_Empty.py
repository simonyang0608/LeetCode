class Solution(object):
    def minOperations(self, nums):
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

        ##### Result summary counter #####
        res_cnter = 0


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[nums_idx] not in record_dict):
                record_dict[nums[nums_idx]] = 1 #Keep updating/recording
            else:
                record_dict[nums[nums_idx]] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for record_key in record_dict:

            ##### Check if the current summary counter is less than 2 or not #####
            if (record_dict[record_key] < 2):
                return (-1)

            if (not (record_dict[record_key] % 3)):
                res_cnter += (record_dict[record_key] // 3) #Keep updating/accumulating
            else:
                res_cnter += ((record_dict[record_key] // 3) + 1) #Keep updating/accumulating

        return res_cnter
