class Solution(object):
    def minimizeSum(self, nums):
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

        ####################################################
        #Greedy-based loop traversal with sorted-operations
        nums.sort() #Sorted-operations

        right_most1, right_most2, right_most3 = (nums[(-1)] - nums[2]), (nums[(-2)] - nums[1]), (nums[(-3)] - nums[0]) #Right-most values (i.e. 1, 2, 3)

        return min(right_most1, right_most2, right_most3)
