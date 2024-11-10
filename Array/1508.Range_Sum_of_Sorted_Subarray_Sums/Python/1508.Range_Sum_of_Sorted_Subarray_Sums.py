class Solution(object):
    def rangeSum(self, nums, n, left, right):
        """
        :type nums: List[int]
        :type n: int
        :type left: int
        :type right: int
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, n

        ##### Record prefix-summary value #####
        record_prefix_sum = 0

        ##### Result array #####
        res_arry = []


        #######################################################
        #Two-pointers based loop traversal with recorded array
        ##### Step 1: Looped-traversal with recorded array #####
        while (record_left_ptr < record_right_ptr):
            for nums_idx in range(record_left_ptr, record_right_ptr):
                record_prefix_sum += nums[nums_idx] #Keep updating/accumulating

                res_arry.append(record_prefix_sum) #Keep updating/recording

            ##### Check if the current prefix-summary value needs to be reset or not #####
            if (record_prefix_sum):
                record_prefix_sum &= 0 #Reset
            else:
                pass

            record_left_ptr += 1 #Keep updating/accumulating

        ##### Step 2: Post-process/Final completions #####
        res_arry.sort() #Sorted-operations

        return (sum(res_arry[(left - 1): right]) % ((10 ** 9) + 7))
