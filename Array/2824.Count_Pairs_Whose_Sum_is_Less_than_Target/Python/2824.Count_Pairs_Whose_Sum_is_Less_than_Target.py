class Solution(object):
    def countPairs(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Sorted operations #####
        nums.sort()

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_nums - 1)

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        #####################################################
        #Two-pointers based loop traversal with sorted array
        while (record_left_ptr < record_right_ptr):

            ##### Check if the current summary-pairs matched conditions or not #####
            if ((nums[record_right_ptr] + nums[record_left_ptr]) < target):
                res_max_cnter += (record_right_ptr - record_left_ptr) #Keep updating/accumulating

                record_left_ptr += 1 #Keep updating/accumulating

            else:
                record_right_ptr -= 1 #Keep updating/reducing

        return res_max_cnter
