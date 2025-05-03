class Solution(object):
    def shortestSubarray(self, nums, k):
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

        ##### Record summary value #####
        record_sum_val = 0

        ##### Result minimun length #####
        res_min_length = float("inf")


        ##########################################
        #Heap/Priority-queue based loop traversal
        heapify(record_pq) #Update/Record

        for nums_idx in range(len_nums):
            record_sum_val += nums[nums_idx] #Keep updating/accumulating

            ##### Check if the current summary value matched conditions or not #####
            if (record_sum_val >= k):
                res_min_length = ((nums_idx + 1) if ((nums_idx + 1) < res_min_length) else res_min_length) #Keep updating/overwriting
            else:
                pass

            while (record_pq and ((record_sum_val - (record_pq[0])[0]) >= k)):
                res_min_length = min((nums_idx - (record_pq[0])[1]), res_min_length) #Keep updating/overwriting

                heappop(record_pq) #Keep updating/popped

            heappush(record_pq, [record_sum_val, nums_idx]) #Keep updating/recording

        return ((-1) if (res_min_length == float("inf")) else res_min_length)
