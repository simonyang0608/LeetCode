class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
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

        ##### Result array #####
        res_arry = []


        ##############################
        #Hashmap-based loop traversal
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[nums_idx] not in record_dict):
                record_dict[nums[nums_idx]] = 1 #Keep updating/recording
            else:
                record_dict[nums[nums_idx]] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal for the recorded dictionary/hashmap #####
        for record_key in record_dict:

            ##### Check if the current value matched conditions or not #####
            if (record_dict[record_key] == 1):
                res_arry.append(record_key) #Keep updating/recording
            else:
                pass

            ##### Check if the current length matched conditions or not #####
            if (len(res_arry) == 2):
                break

        return res_arry
