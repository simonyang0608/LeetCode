class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #=======================================#
        # Prefix-summary based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record array #####
        record_arry = [0 for _ in range((len_nums + 1))]


        #########################################################
        #Prefix-summary based loop traversal with recorded array
        ##### Step 1: Record indexed-value with array #####
        for record_idx in range(1, (len_nums + 1)):
            record_arry[record_idx] = (record_arry[(record_idx - 1)] + nums[(record_idx - 1)]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array #####
        for record_idx in range(1, (len_nums + 1)):

            ##### Check if the current differences matched conditions or not #####
            if (record_arry[(record_idx - 1)] == (record_arry[len_nums] - record_arry[record_idx])):
                return (record_idx - 1)

        return (-1)
