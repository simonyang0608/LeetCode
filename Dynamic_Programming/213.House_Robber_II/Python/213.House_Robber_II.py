class Solution(object):
    def rob(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #========================================================#
        # Dynnamic-proogramming (i.e. DP) based traversal method #
        #========================================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        if (len_nums == 1): #Issue/Boundary-case handling
            return nums[0]

        ##### Record dynamic-programming arrays (i.e. left, right) #####
        record_dp_left, record_dp_right = [0 for _ in range(len_nums)], [0 for _ in range(len_nums)]


        ######################################################
        #Dynnamic-proogramming (i.e. DP) based loop traversal
        record_dp_left[1] = nums[0] #Update/Overwrite
        record_dp_right[1] = nums[1] #Update/Overwrite

        for nums_idx in range(2, len_nums):
            record_dp_left[nums_idx] = record_dp_left[(nums_idx - 1)] #Keep updating/transferring

            record_dp_left[nums_idx] = max(record_dp_left[nums_idx], (record_dp_left[(nums_idx - 2)] + nums[(nums_idx - 1)])) #Keep updating/overwriting

        for nums_idx in range(2, len_nums):
            record_dp_right[nums_idx] = record_dp_right[(nums_idx - 1)] #Keep updating/transferring

            record_dp_right[nums_idx] = max(record_dp_right[nums_idx], (record_dp_right[(nums_idx - 2)] + nums[nums_idx])) #Keep updating/overwriting

        return (record_dp_left[(len_nums - 1)] if (record_dp_left[(len_nums - 1)] > record_dp_right[(len_nums - 1)]) else record_dp_right[(len_nums - 1)])
