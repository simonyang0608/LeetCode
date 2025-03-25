class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
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


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[record_mid_ptr] == target):
                return record_mid_ptr

            ##### Check if the current range is left-sorted or not #####
            if (nums[record_left_ptr] <= nums[record_mid_ptr]):

                ##### Check the range status #####
                if ((nums[record_left_ptr] <= target) and (target < nums[record_mid_ptr])):
                    record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
                else:
                    record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                ##### Check the range status #####
                if ((nums[record_mid_ptr] < target) and (target <= nums[record_right_ptr])):
                    record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
                else:
                    record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
        
        return (-1)
