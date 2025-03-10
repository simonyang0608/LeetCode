class Solution(object):
    def mincostToHireWorkers(self, quality, wage, k):
        """
        :type quality: List[int]
        :type wage: List[int]
        :type k: int
        :rtype: float
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. quality, wage) #####
        len_total = len(quality)

        ##### Record array #####
        record_arry = []

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Record summary value #####
        record_sum_val = 0.0

        ##### Result minimun summary value #####
        res_min_sum = float("inf")


        ##############################################################
        #Heap/Priority-queue based loop traversal with recorded array
        ##### Step 1: Record indexed-informations with array #####
        heapify(record_pq) #Update/Heapify

        for record_idx in range(len_total):
            record_arry.append(((float(wage[record_idx]) / quality[record_idx]), quality[record_idx])) #Keep updating/recording

        ##### Looped-traversal with recorded array #####
        record_arry.sort() #Sorted-operations

        for (record_ratio, record_quality) in record_arry:
            record_sum_val += record_quality #Keep updating/accumulating

            heappush(record_pq, (record_quality * (-1))) #Keep updating/recording

            ##### Check if the current size exceed k-th or not #####
            if (len(record_pq) > k):
                record_sum_val -= ((-1) * record_pq[0]) #Keep updating/reducing

                heappop(record_pq) #Keep updating/popped

            if (len(record_pq) == k):
                res_min_sum = min(res_min_sum, (record_sum_val * record_ratio)) #Keep updating/overwriting
            else:
                pass

        return res_min_sum
