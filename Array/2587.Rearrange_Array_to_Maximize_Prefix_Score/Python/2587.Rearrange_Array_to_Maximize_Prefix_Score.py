class Solution(object):
    def maxScore(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #========================================#
        # One-pass update based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Sorted operations #####
        nums.sort(reverse = True)

        ##### Record prefix-summary value #####
        record_prefix_sum = 0

        ##### Result maximun score #####
        res_max_score = 0


        ##########################################################################
        #One-pass update based loop traversal with recorded prefix-summary value
        for nums_idx in range(len_nums):
            record_prefix_sum += nums[nums_idx] #Keep updating/accumulating

            ##### Check if the current prefix-summary value matched conditions or not #####
            if (record_prefix_sum > 0):
                res_max_score += 1 #Keep updating/accumulating
            else:
                break

        return res_max_score
