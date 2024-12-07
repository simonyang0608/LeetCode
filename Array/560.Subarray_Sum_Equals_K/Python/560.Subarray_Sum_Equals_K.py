class Solution(object):
    def subarraySum(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #========================================#
        # One-pass record based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dictionary/hashmap #####
        record_dict = {0: 1}

        ##### Record prefix-summary value #####
        record_prefix_sum = 0

        ##### Result summary counter #####
        res_cnter = 0


        ########################################################################
        #One-pass record based loop traversal with recorded dictionary/hashmap
        for nums_idx in range(len_nums):
            record_prefix_sum += nums[nums_idx] #Keep updating/accumulating

            ##### Check if the current previous summary existed or not #####
            if ((record_prefix_sum - k) in record_dict):
                res_cnter += record_dict[(record_prefix_sum - k)] #Keep updating/accumulating
            else:
                pass

            ##### Check if the current summary existed or not #####
            if (record_prefix_sum in record_dict):
                record_dict[record_prefix_sum] += 1 #Keep updating/recording
            else:
                record_dict[record_prefix_sum] = 1 #Keep updating/recording

        return res_cnter
