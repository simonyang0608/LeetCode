class Solution(object):
    def maximumProduct(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Priority-queue heapify #####
        heapify(nums)

        ##### Result maximun product #####
        res_max_prod = 1


        ##########################################
        #Heap/Priority-queue based loop traversal
        ##### Step 1: Looped-traversal/Update for priority-queue #####
        for k_idx in range(k):
            record_num = heappop(nums) #Record num

            heappush(nums, (record_num + 1)) #Keep updating/insert

        ##### Step 2: Post-process/Final completions #####
        for nums_idx in range(len_nums):
            res_max_prod = ((res_max_prod * nums[nums_idx]) % ((10 ** 9) + 7)) #Keep updating/overwriting

        return res_max_prod
