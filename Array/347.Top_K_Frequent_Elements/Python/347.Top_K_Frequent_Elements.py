class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of nums array #####
        nums.append(10001)

        len_nums = len(nums)

        ##### Sorted operations #####
        nums.sort()

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record previous value, index
        record_prev_val, record_prev_idx = nums[0], 0

        ##### Record heap/priority-queue
        record_pq = []

        heapify(record_pq)

        ##### Result array #####
        res_arry = []


        ##########################################
        #Heap/Priority-queue based loop traversal
        ##### Step 1: Record indexed-value with heap/priority-queue #####
        while (record_trav_ptr < len_nums):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums[record_trav_ptr] != record_prev_val):
                heappush(record_pq, [((record_trav_ptr - record_prev_idx) * (-1)), record_prev_val]) #Keep updating/recording

                record_prev_idx = record_trav_ptr #Keep updating/overwriting
                record_prev_val = nums[record_trav_ptr] #Keep updating/overwriting

            else:
                pass

            record_trav_ptr += 1 #Keep updating/traversing

        ##### Step 2: Post-process/Final completions #####
        for k_idx in range(k):
            res_arry.append((heappop(record_pq))[1]) #Keep updating/recording

        return res_arry
