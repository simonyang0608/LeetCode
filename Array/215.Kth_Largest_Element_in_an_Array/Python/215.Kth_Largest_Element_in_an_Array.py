class Solution(object):
    def findKthLargest(self, nums, k):
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

        ##### Record heap/priority-queue #####
        record_pq = []

        heapify(record_pq)


        ##########################################
        #Heap/Priority-queue based loop traversal
        for nums_idx in range(len_nums):
            heappush(record_pq, (nums[nums_idx] * (-1))) #Keep updating/recording

        while (k):
            res_val = heappop(record_pq) #Keep updating/popped

            k -= 1 #Keep updating/reducing

        return (res_val * (-1))
