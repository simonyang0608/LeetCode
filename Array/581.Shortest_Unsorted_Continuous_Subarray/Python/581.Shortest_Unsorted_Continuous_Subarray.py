class Solution(object):
    def findUnsortedSubarray(self, nums):
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

        ##### Sort nums array #####
        sort_nums = nums[:]

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_nums - 1)

        ##### Result two-pointers (i.e. left, right) #####
        res_left_ptr, res_right_ptr = (-1), (-1)


        ###################################
        #Two-pointers based loop traversal
        sort_nums.sort() #Sorted operations

        while (record_left_ptr < record_right_ptr):

            ##### Check if the current indexed-value matched conditions or not #####
            if (sort_nums[record_left_ptr] == nums[record_left_ptr]):
                record_left_ptr += 1 #Keep updating/traversing
            else:
                res_left_ptr = record_left_ptr #Keep updating/overwriting

            if (sort_nums[record_right_ptr] == nums[record_right_ptr]):
                record_right_ptr -= 1 #Keep updating/traversing
            else:
                res_right_ptr = record_right_ptr #Keep updating/overwriting

            ##### Check if the current pointers matched conditions or not #####
            if ((res_left_ptr != (-1)) and (res_right_ptr != (-1))):
                break

        return (0 if ((res_left_ptr == (-1)) and (res_right_ptr == (-1))) else ((res_right_ptr - res_left_ptr) + 1))
