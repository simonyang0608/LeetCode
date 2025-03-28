class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
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
            if (nums[nums_idx] in record_dict):

                ##### Check if the current difference is less than k-th or not #####
                if ((nums_idx - record_dict[nums[nums_idx]]) <= k):
                    return True
            else:
                pass

            record_dict[nums[nums_idx]] = nums_idx #Keep updating/recording

        return False
