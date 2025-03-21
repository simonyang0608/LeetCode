class Solution(object):
    def minOperationsToMakeMedianK(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = (len_nums // 2), (len_nums // 2)

        ##### Result minimun summary counter #####
        res_min_cnter = 0


        ####################################################
        #Greedy-based loop traversal with sorted-operations
        nums.sort() #Sorted-operations
        
        ##### Check if the current indexed-value is less than k-th or not #####
        if (nums[record_left_ptr] >= k):
            res_min_cnter += (nums[record_left_ptr] - k) #Update/Accumulate
        else:
            res_min_cnter += (k - nums[record_left_ptr]) #Update/Accumulate

        nums[record_left_ptr] = k #Update/Overwrite

        while ((record_left_ptr - 1) >= 0):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[(record_left_ptr - 1)] <= nums[record_left_ptr]):
                pass
            else:
                res_min_cnter += (nums[(record_left_ptr - 1)] - nums[record_left_ptr]) #Keep updating/accumulating

                nums[(record_left_ptr - 1)] = nums[record_left_ptr] #Keep updating/overwriting

            record_left_ptr -= 1 #Keep updating/traversing

        while ((record_right_ptr + 1) < len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[(record_right_ptr + 1)] >= nums[record_right_ptr]):
                pass
            else:
                res_min_cnter += (nums[record_right_ptr] - nums[(record_right_ptr + 1)]) #Keep updating/accumulating

                nums[(record_right_ptr + 1)] = nums[record_right_ptr] #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/traversing

        return res_min_cnter
