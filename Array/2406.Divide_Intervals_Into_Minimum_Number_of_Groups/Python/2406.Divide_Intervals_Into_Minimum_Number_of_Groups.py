class Solution(object):
    def minGroups(self, intervals):
        """
        :type intervals: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of intervals array #####
        len_intervals = len(intervals)

        ##### Record heap/priority-queue #####
        record_pq = []


        #################################################################
        #Heap/Priority-queue based loop traversal with sorted-operations
        heapify(record_pq) #Update/Heapify

        intervals.sort() #Sorted-operations

        for intervals_idx in range(len_intervals):

            ##### Check if the current indexed-value matched conditions or not #####
            if (record_pq and (record_pq[0] < (intervals[intervals_idx])[0])):
                heappop(record_pq) #Keep updating/popped
            else:
                pass

            heappush(record_pq, (intervals[intervals_idx])[1]) #Keep updating/recording

        return len(record_pq)
