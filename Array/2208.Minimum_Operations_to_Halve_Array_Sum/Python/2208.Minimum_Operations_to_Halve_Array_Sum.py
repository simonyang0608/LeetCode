class Solution(object):
    def halveArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)
        
        ##### Record target half-summary value #####
        record_half_sum = (sum(nums) / (2.))

        ##### Update/Heapify nums array #####
        for nums_idx in range(len_nums):
            nums[nums_idx] *= (-1)

        heapify(nums)

        ##### Record summary value #####
        record_sum_val = 0

        ##### Result minimun operations #####
        res_min_oprs = 0


        ##########################################
        #Heap/Priority-queue based loop traversal
        while (record_sum_val < record_half_sum):
            curr_min_val_half = (heappop(nums) / (2.)) #Half of current minimun value

            heappush(nums, curr_min_val_half) #Keep updating/recording

            record_sum_val -= curr_min_val_half #Keep updating/reducing

            res_min_oprs += 1 #Keep updating/accumulating

        return res_min_oprs
