class Solution(object):
    def findMin(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len(nums) - 1)

        ##### Result minimun value #####
        res_min_val = 5001

        
        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current sub-array is sorted or not #####
            if (nums[record_mid_ptr] >= nums[record_left_ptr]):
                res_min_val = min(res_min_val, nums[record_left_ptr]) #Keep updating/overwriting

                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

            else:
                res_min_val = min(res_min_val, nums[record_mid_ptr]) #Keep updating/overwriting

                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return res_min_val
