class Solution(object):
    def findIndices(self, nums, indexDifference, valueDifference):
        """
        :type nums: List[int]
        :type indexDifference: int
        :type valueDifference: int
        :rtype: List[int]
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, indexDifference

        ##### Record minimun, maximun-value #####
        record_max_val, record_min_val = (-1), ((10 ** 9) + 1)


        ###################################
        #Two-pointers based loop traversal
        while (record_right_ptr < len_nums):

            ##### Check if the current indexed-value is larger or not #####
            if (nums[record_left_ptr] > record_max_val):
                record_max_val, record_max_idx = nums[record_left_ptr], record_left_ptr #Keep updating/overwriting
            else:
                pass

            ##### Check if the current indexed-value is smaller or not #####
            if (nums[record_left_ptr] < record_min_val):
                record_min_val, record_min_idx = nums[record_left_ptr], record_left_ptr #Keep updating/overwriting
            else:
                pass

            ##### Check if the current differences matched conditions or not #####
            if (abs((nums[record_right_ptr] - record_max_val)) >= valueDifference):
                return [record_max_idx, record_right_ptr]
            else:
                pass

            if (abs((nums[record_right_ptr] - record_min_val)) >= valueDifference):
                return [record_min_idx, record_right_ptr]
            else:
                pass

            record_left_ptr += 1 #Keep updating/traversing
            record_right_ptr += 1 #Keep updating/traversing

        return [(-1), (-1)]
