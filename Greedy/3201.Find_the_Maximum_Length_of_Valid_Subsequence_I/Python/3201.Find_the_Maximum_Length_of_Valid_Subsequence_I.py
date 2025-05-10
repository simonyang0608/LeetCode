class Solution(object):
    def maximumLength(self, nums):
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

        ##### Record summary counters (i.e. all-even, odd, even-odd, odd-even) #####
        all_even_cnter, all_odd_cnter, even_odd_cnter, odd_even_cnter = 0, 0, 0, 0

        ##### Record sign #####
        record_sign = (-1)


        #############################
        #Greedy-based loop traversal
        ##### Step 1: Looped-traversal for all-even, odd conditions #####
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (not (nums[nums_idx] % 2)):
                all_even_cnter += 1 #Keep updating/accumulating
            else:
                all_odd_cnter += 1 #Keep updating/accumulating

        ##### Step 2: Looped-traversal for even-odd conditions #####
        record_sign = 0 #Update, Reset

        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if ((nums[nums_idx] % 2) == record_sign):
                even_odd_cnter += 1 #Keep updating/accumulating

                record_sign = (1 - record_sign) #Keep updating, overwriting
            else:
                pass

        ##### Step 3: Looped-traversal for odd-even conditions #####
        record_sign = 1 #Update, Reset

        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if ((nums[nums_idx] % 2) == record_sign):
                odd_even_cnter += 1 #Keep updating/accumulating

                record_sign = (1 - record_sign) #Keep updating, overwriting
            else:
                pass

        return max(all_even_cnter, all_odd_cnter, even_odd_cnter, odd_even_cnter)
