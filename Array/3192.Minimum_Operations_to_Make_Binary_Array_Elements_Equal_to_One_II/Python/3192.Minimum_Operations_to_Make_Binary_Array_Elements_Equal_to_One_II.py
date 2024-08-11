class Solution(object):
    def minOperations(self, nums):
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

        ##### Record indexed-bit #####
        record_bit = 1

        ##### Result minimun operations #####
        res_min_oprs = 0


        #######################################################
        #Greedy-based loop traversal with recorded indexed-bit
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-bit matched conditions or not #####
            if (nums[nums_idx] != record_bit):
                res_min_oprs += 1 #Keep updating/accumulating

                record_bit = nums[nums_idx] #Keep updating/overwriting

            else:
                pass

        return res_min_oprs
