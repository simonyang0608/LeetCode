class Solution(object):
    def singleNumber(self, nums):
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

        ##### Record traversal pointer #####
        record_trav_ptr = 0


        #############################
        #Greedy-based loop traversal
        nums.sort() #Sorted operations

        while (record_trav_ptr < len_nums):
            record_cnter = 1 #Record summary counter

            while (((record_trav_ptr + 1) < len_nums) and ((nums[record_trav_ptr] == nums[(record_trav_ptr + 1)]))):
                record_cnter += 1 #Keep updating/accumulating
 
                record_trav_ptr += 1 #Keep updating/traversing

            ##### Check if the current summary counter is less than 3 or not #####
            if (record_cnter != 3):
                return nums[record_trav_ptr]

            record_trav_ptr += 1 #Keep updating/traversing

        return (-1)
