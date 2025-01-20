class Solution(object):
    def getSneakyNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        #================================#
        # Hashmap based traversal method #
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
        #Hashmap based loop traversal
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[nums_idx] in record_dict):
                res_arry.append(nums[nums_idx]) #Keep updating/recording

                continue

            record_dict[nums[nums_idx]] = True #Keep updating/overwriting

        return res_arry
