class Solution(object):
    def maxKelements(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #=======================================#
        # Priority-queue based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Updated nums array #####
        for nums_idx in range(len_nums):
            nums[nums_idx] *= (-1)

        heapify(nums)

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        #####################################
        #Priority-queue based loop traversal
        for k_idx in range(k):
            curr_min_val = heappop(nums) #Current minimun value

            res_max_cnter -= curr_min_val #Keep updating/accumulating

            heappush(nums, int(floor(curr_min_val / 3))) #Keep updating/recording

        return res_max_cnter
