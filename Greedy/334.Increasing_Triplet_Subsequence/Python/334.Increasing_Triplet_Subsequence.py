class Solution(object):
    def increasingTriplet(self, nums):
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

        ##### Record minimun values (i.e. 1, 2) #####
        record_min_val1, record_min_val2 = float('inf'), float('inf')


        #############################
        #Greedy-based loop traversal
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value is smaller than minimun values or not #####
            if (nums[nums_idx] <= record_min_val1):
                record_min_val1 = nums[nums_idx] #Keep updating/overwriting

            elif (nums[nums_idx] <= record_min_val2):
                record_min_val2 = nums[nums_idx] #Keep updating/overwriting
            else:
                return True

        return False
