class Solution(object):
    def largestSumAfterKNegations(self, nums, k):
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
        record_pq = deepcopy(nums)

        heapify(record_pq)

        ##### Result summary value #####
        res_sum_val = sum(nums)


        ##########################################
        #Heap/Priority-queue based loop traversal
        while (k):
            record_val = (heappop(record_pq) * (-1)) #Record value

            res_sum_val += (record_val * 2) #Keep updating/accumulating

            heappush(record_pq, record_val) #Keep updating/pushed

            k -= 1 #Keep updating/traversing

        return res_sum_val
