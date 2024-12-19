class Solution(object):
    def lastStoneWeight(self, stones):
        """
        :type stones: List[int]
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of stones array #####
        len_stones = len(stones)

        ##### Record heap/priority-queue #####
        record_pq = []

        for stones_idx in range(len_stones):
            record_pq.append((stones[stones_idx] * (-1)))

        heapify(record_pq)


        ##########################################
        #Heap/Priority-queue based loop traversal
        while (len(record_pq) >= 2):
            record_scnd_val = record_pq[0] #Record second value

            heappop(record_pq) #Keep updating/popped

            record_fst_val = record_pq[0] #Record first value

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current indexed-value matched conditions or not #####
            if (record_fst_val == record_scnd_val):
                pass
            else:
                heappush(record_pq, (abs(record_fst_val - record_scnd_val) * (-1))) #Keep updating/pushed

        return (0 if (not record_pq) else (record_pq[0] * (-1)))
