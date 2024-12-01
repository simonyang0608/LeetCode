class Solution(object):
    def maxResult(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record dynamic-programming array #####
        record_dp = [0 for _ in range(len_nums)]

        record_dp[0] = nums[0]

        ##### Record priority-queue #####
        record_pq = [[(record_dp[0] * (-1)), 0]]

        heapify(record_pq)


        ##########################################
        #Dynamic-programming based loop traversal
        for nums_idx in range(1, len_nums):
            while (record_pq and ((nums_idx - (record_pq[0])[1]) > k)):
                heappop(record_pq) #Keep updating/popped
            
            record_dp[nums_idx] += (((record_pq[0])[0] * (-1)) + nums[nums_idx]) #Keep updating/overwriting

            heappush(record_pq, [(record_dp[nums_idx] * (-1)), nums_idx]) #Keep updating/recording

        return record_dp[(len_nums - 1)]
