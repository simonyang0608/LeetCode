class Solution(object):
    def maxSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #=================================#
        # Kadanes'-based traversal method #
        #=================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record value #####
        record_val = 0

        ##### Result maximun value #####
        res_max_val = ((-1) * (10 ** 9))


        ###############################
        #Kadanes'-based loop traversal
        for nums_idx in range(len_nums):
            record_val += nums[nums_idx] #Keep updating/accumulating

            res_max_val = max(res_max_val, record_val) #Keep updating/overwriting

            ##### Check if the current value needs to be reset or not #####
            if (record_val < 0):
                record_val &= 0 #Keep updating/reset
            else:
                pass

        return res_max_val
