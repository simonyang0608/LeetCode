class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dictionary/hashmap #####
        record_dict = {}


        ##############################
        #Hashmap-based loop traversal
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[nums_idx] not in record_dict):
                record_dict[nums[nums_idx]] = 1 #Keep updating/recording
            else:
                record_dict[nums[nums_idx]] += 1 #Keep updating/recording

            ##### Check if the current indexed-value is majority or not #####
            if (record_dict[nums[nums_idx]] > (len_nums // 2)):
                return nums[nums_idx]

        return (-1)
