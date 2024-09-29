class Solution(object):
    def sortArray(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
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

        ##### Record minimun, maximun values #####
        record_min_val, record_max_val = min(nums), max(nums)

        ##### Result array #####
        res_arry = []


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value existed or not #####
            if (nums[nums_idx] not in record_dict):
                record_dict[nums[nums_idx]] = 1 #Keep updating/recording
            else:
                record_dict[nums[nums_idx]] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with the recorded dictionary #####
        record_max_val += 1 #Update/Accumulate

        for record_idx in range(record_min_val, record_max_val):

            ##### Check if the current indexed-value esisted or not #####
            if (record_idx in record_dict):
                for times_idx in range(record_dict[record_idx]):
                    res_arry.append(record_idx) #Keep updating/recording
            else:
                pass

        return res_arry
