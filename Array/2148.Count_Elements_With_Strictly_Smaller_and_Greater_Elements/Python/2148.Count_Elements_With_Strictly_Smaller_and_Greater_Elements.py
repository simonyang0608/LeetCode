class Solution(object):
    def countElements(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #========================================#
        # One-pass record based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Sorted operations #####
        nums.sort()

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record summary counter #####
        record_cnter = 0

        ##### Result summary counter #####
        res_cnter = 0


        ######################################
        #One-pass record based loop traversal
        ##### Step 1: Looped-traversal for the prefix-part/half #####
        while (((record_trav_ptr + 1) < len_nums) and (nums[record_trav_ptr] == nums[record_trav_ptr + 1])):
            record_trav_ptr += 1 #Keep updating/traversing

        record_trav_ptr += 1 #Update/Traverse

        ##### Step 2: Looped-traversal for the suffix-part/half #####
        while (record_trav_ptr < len_nums):
            record_cnter += 1 #Keep updating/accumulating

            while (((record_trav_ptr + 1) < len_nums) and (nums[record_trav_ptr] == nums[(record_trav_ptr + 1)])):
                record_cnter += 1 #Keep updating/accumulating
                record_trav_ptr += 1 #Keep updating/traversing

            ##### Check if the current indexed-pointer matched conditions or not #####
            if ((record_trav_ptr + 1) < len_nums):
                res_cnter += record_cnter #Keep updating/accumulating
            else:
                pass

            ##### Check if the current summary counter needs to be reset or not #####
            if (record_cnter):
                record_cnter &= 0 #Update/Reset
            else:
                pass

            record_trav_ptr += 1 #Keep updating/traversing

        return res_cnter
