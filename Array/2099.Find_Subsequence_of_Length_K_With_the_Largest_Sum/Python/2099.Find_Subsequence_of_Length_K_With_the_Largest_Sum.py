class Solution(object):
    def maxSubsequence(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        #===========================================#
        # Heap/Priorit-queue based traversal method #
        #===========================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record heap/priority-queue #####
        record_pq = []

        heapify(record_pq)

        ##### Record array #####
        record_arry = [((-1) * ((10 **6))) for _ in range(len_nums)]

        ##### Result array #####
        res_arry = []


        #########################################
        #Heap/Priorit-queue based loop traversal
        ##### Step 1: Record indexed-value with heap/priority-queue #####
        for nums_idx in range(len_nums):
            heappush(record_pq, [nums[nums_idx], nums_idx]) #Keep updating/recording

            ##### Check if the current size is larger than k-th or not #####
            if (len(record_pq) > k):
                heappop(record_pq) #Keep updating/popped
            else:
                pass

        ##### Step 2: Looped-traversal with recorded heap/priority-queue #####
        while (record_pq):
            record_arry[(record_pq[0])[1]] = (record_pq[0])[0] #Keep updating/overwriting

            heappop(record_pq) #Keep updating/popped

        ##### Step 3: Post-process/Final completions #####
        for nums_idx in range(len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (record_arry[nums_idx] != ((-1) * ((10 **6)))):
                res_arry.append(record_arry[nums_idx]) #Keep updating/recording
            else:
                pass

        return res_arry
