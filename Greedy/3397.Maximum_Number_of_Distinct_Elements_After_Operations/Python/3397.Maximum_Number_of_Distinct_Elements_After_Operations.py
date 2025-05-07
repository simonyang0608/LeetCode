class Solution(object):
    def maxDistinctElements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #==============================#
        # Greed-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record maximun value #####
        record_max_val = float("-inf")

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ############################
        #Greed-based loop traversal
        nums.sort() #Sorted operations

        for nums_idx in range(len_nums):

            ##### Check if the current difference matched conditions or not ##### 
            if ((nums[nums_idx] + k) <= record_max_val):
                continue

            res_max_cnter += 1 #Keep updating/accumulating

            record_max_val = max((record_max_val + 1), (nums[nums_idx] - k)) #Keep updating/overwriting

        return res_max_cnter
