class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = (len_nums - 1), (len_nums - 1)


        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Looped-trraversal for the swapped-stage #####
        while (record_left_ptr >= 0):

            ##### Check if the current indexed-value is target or not #####
            if (nums[record_left_ptr] == val):
                nums[record_left_ptr], nums[record_right_ptr] = nums[record_right_ptr], nums[record_left_ptr] #Keep updating/swapped

                record_right_ptr -= 1 #Keep updating/traversing
            else:
                pass

            record_left_ptr -= 1 #Keep updating/traversing

        ##### Step 2: Post-process/Final completions #####
        while (nums and (nums[(-1)] == val)):
            nums.pop() #Keep updating/popped

        return len(nums)
