class Solution(object):
    def summaryRanges(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result array #####
        res_arry = []


        #############################
        #Greedy-based loop traversal
        while (record_trav_ptr < len_nums):
            start_str = str(nums[record_trav_ptr]) #Start-string

            while (((record_trav_ptr + 1) < len_nums) and ((nums[record_trav_ptr] + 1) == nums[(record_trav_ptr + 1)])):
                record_trav_ptr += 1 #Keep updating/traversing

            end_str = str(nums[record_trav_ptr]) #End-string

            ##### Check if the start is the same as end-string or not #####
            if (start_str == end_str):
                res_arry.append(start_str) #Keep updating/recording
            else:
                res_arry.append((start_str + "->" + end_str)) #Keep updating/recording

            record_trav_ptr += 1 #Keep updating/traversing

        return res_arry
