class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 1


        ###################################
        #Two-pointers based loop traversal
        while (record_right_ptr < len_nums):

            ##### Check if the current pointer matched conditions or not #####
            if (not nums[record_left_ptr]):
                if (not nums[record_right_ptr]):
                    record_right_ptr += 1 #Keep updating/traversing

                else:
                    nums[record_left_ptr], nums[record_right_ptr] = nums[record_right_ptr], nums[record_left_ptr] #Keep updating/swap

                    while ((record_left_ptr < record_right_ptr) and (nums[record_left_ptr])):
                        record_left_ptr += 1 #Keep updating/traversing

            else:
                record_left_ptr += 1 #Keep updating/traversing
                record_right_ptr += 1 #Keep updating/traversing
