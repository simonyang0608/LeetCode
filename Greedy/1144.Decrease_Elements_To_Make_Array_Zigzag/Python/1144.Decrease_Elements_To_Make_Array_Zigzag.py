class Solution(object):
    def movesToMakeZigzag(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        #############
        #Initiialize
        ##### Length of nuums array #####
        len_nums = len(nums)

        if (len_nums <= 2): #Issue/Boundary-case handling
            return 0

        ##### Record nums array #####
        record_nums = deepcopy(nums)

        ##### Result summary couunter (i.e. odd, even) #####
        res_cnter_odd, res_cnter_even = 0, 0


        #############################
        #Greedy-based loop traversal
        ##### Step 1: Looped-traversal for the odd indexed-large #####
        for nums_idx in range(1, len_nums, 2):

            ##### Check if the previous indexed-value is smaller or not #####
            if (nums[(nums_idx - 1)] <= nums[nums_idx]):
                res_cnter_odd += ((nums[nums_idx] - nums[(nums_idx - 1)]) + 1) #Keep updating/accumulating

                nums[nums_idx] = (nums[(nums_idx - 1)] - 1) #Keep updating/overwriting
            else:
                pass

            ##### Check if the next indexed exceed boundary or not #####
            if ((nums_idx + 1) < len_nums):

                ##### Check if the next indexed-value is smaller or not #####
                if (nums[(nums_idx + 1)] <= nums[nums_idx]):
                    res_cnter_odd += ((nums[nums_idx] - nums[(nums_idx + 1)]) + 1) #Keep updating/accumulating

                    nums[nums_idx] = (nums[(nums_idx + 1)] - 1) #Keep updating/overwriting
                else:
                    pass
            else:
                pass

        ##### Step 2: Looped-traversal for the even indexed-large #####
        for nums_idx in range(1, len_nums, 2):

            ##### Check if the current indexed-value is smaller or not #####
            if (record_nums[(nums_idx - 1)] >= record_nums[nums_idx]):
                res_cnter_even += ((record_nums[(nums_idx - 1)] - record_nums[nums_idx]) + 1) #Keep updating/accumulating

                record_nums[(nums_idx - 1)] = (record_nums[nums_idx] - 1) #Keep updating/overwriting
            else:
                pass

            ##### Check if the next indexed exceed boundary or not #####
            if ((nums_idx + 1) < len_nums):

                ##### Check if the current indexed-value is smaller or not #####
                if (record_nums[(nums_idx + 1)] >= record_nums[nums_idx]):
                    res_cnter_even += ((record_nums[(nums_idx + 1)] - record_nums[nums_idx]) + 1) #Keep updating/accumulating

                    record_nums[(nums_idx + 1)] = (record_nums[nums_idx] - 1) #Keep updating/overwriting
                else:
                    pass
            else:
                pass

        return (res_cnter_odd if (res_cnter_odd < res_cnter_even) else res_cnter_even)
