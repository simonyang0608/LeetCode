class Solution(object):
    def canJump(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record steps #####
        record_steps = nums[0]


        #############################
        #Greedy-based loop traversal
        for nums_idx in range(1, len_nums):
            
            ##### Check if the current steps matched conditions or not #####
            if (record_steps > 0):
                record_steps -= 1 #Keep updating/reducing

                record_steps = max(record_steps, nums[nums_idx]) #Keep updating/overwriting
            else:
                return False

        return True
