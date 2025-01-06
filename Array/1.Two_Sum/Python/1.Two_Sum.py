class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of nums #####
        len_nums = len(nums)

        ##### Record dictionary/hashmap #####
        record_dict = {}


        ###############################################################
        #Hashmap-based loop traversal with recorded dictionary/hashmap
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value existed or not #####
            if ((target - nums[nums_idx]) in record_dict):
                return [record_dict[(target - nums[nums_idx])], nums_idx]
            else:
                pass
            
            record_dict[nums[nums_idx]] = nums_idx #Keep updating/recording

        return [(-1), (-1)]
