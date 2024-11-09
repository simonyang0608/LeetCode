class Solution(object):
    def maxArrayValue(self, nums):
        """
        :type nums: List[int]
        :rtype: int 
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record right pointer #####
        record_right_ptr = (len_nums - 1)

        ##### Record summary value #####
        record_sum_val = 0

        ##### Result maximun summary value #####
        res_max_sum_val = 0


        #############################
        #Greedy-based loop traversal
        while (record_right_ptr >= 0):
            record_sum_val += nums[record_right_ptr] #Keep updating/accumulating

            while (((record_right_ptr - 1) >= 0) and (record_sum_val >= nums[(record_right_ptr - 1)])):
                record_sum_val += nums[(record_right_ptr - 1)] #Keep updating/accumulating

                record_right_ptr -= 1 #Keep updating/reducing

            res_max_sum_val = max(res_max_sum_val, record_sum_val) #Keep updating/overwriting

            ##### Check if the current summary value needs to be reset or not #####
            if (record_sum_val):
                record_sum_val &= 0 #Reset
            else:
                pass

            record_right_ptr -= 1 #Keep updating/reducing

        return res_max_sum_val
