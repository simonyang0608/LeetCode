class Solution(object):
    def partitionArray(self, nums, k):
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

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result minimun summary counter #####
        res_min_cnter = 0


        #############################
        #Greedy-based loop traversal
        nums.sort() #Sorted operations

        while (record_trav_ptr < len_nums):
            record_val = nums[record_trav_ptr] #Record value

            res_min_cnter += 1 #Keep updating/accumulating

            while (((record_trav_ptr + 1) < len_nums) and ((nums[(record_trav_ptr + 1)] - record_val) <= k)):
                record_trav_ptr += 1 #Keep updating/traversing

            record_trav_ptr += 1 #Keep updating/traversing

        return res_min_cnter
