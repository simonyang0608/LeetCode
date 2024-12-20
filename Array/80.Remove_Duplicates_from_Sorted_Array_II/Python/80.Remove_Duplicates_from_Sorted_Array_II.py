class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        if (len_nums <= 2): #Issue/Boundary-case handling
            return len_nums

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 2, 2


        ###################################
        #Two-pointers based loop traversal
        while (record_right_ptr < len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[(record_right_ptr)] != nums[(record_left_ptr - 2)]):
                nums[record_left_ptr], nums[record_right_ptr] = nums[record_right_ptr], nums[record_left_ptr] #Keep updating/swapped

                record_left_ptr += 1 #Keep updating/traversing

            else:
                pass

            record_right_ptr += 1 #Keep updating/traversing

        return record_left_ptr
