class Solution(object):
    def maxOperations(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_nums - 1)

        ##### Result minimun operations #####
        res_min_oprs = 0


        ##########################################################
        #Two-pointers based loop traversal with sorted-operations
        nums.sort() #Sorted-operations

        while (record_left_ptr < record_right_ptr):

            ##### Check if the current summary value is larger than target or not #####
            if ((nums[record_left_ptr] + nums[record_right_ptr]) < k):
                record_left_ptr += 1 #Keep updating/traversing
            
            elif ((nums[record_left_ptr] + nums[record_right_ptr]) == k):
                res_min_oprs += 1 #Keep updating/accumulating

                record_left_ptr += 1 #Keep updating/traversing
                record_right_ptr -= 1 #Keep updating/traversing

            else:
                record_right_ptr -= 1 #Keep updating/traversing

        return res_min_oprs
