class Solution(object):
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#
        
        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_nums - 1)

        ##### Result array #####
        res_arry = [(-1), (-1)]


        ####################################
        #Binary-search based loop traversal
        ##### Step 1: Looped-traversal for finding the target index #####
        if (not len_nums): #Issue/Boundary-case handling
            return res_arry

        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            ##### Check if the current indexed-value is smaller than target or not #####
            if (nums[record_mid_ptr] >= target):
                record_right_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        ##### Step 2: Post-process/Final completions #####
        if (nums[record_left_ptr] != target): #Issue/Boundary-case handling
            return res_arry

        res_arry[0] = record_left_ptr #Update/Overwrite

        while (((record_left_ptr + 1) < len_nums) and (nums[(record_left_ptr + 1)] == target)):
            record_left_ptr += 1 #Keep updating/traversing

        res_arry[1] = record_left_ptr #Update/Overwrite

        return res_arry
