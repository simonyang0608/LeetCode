class Solution(object):
    def furthestBuilding(self, heights, bricks, ladders):
        """
        :type heights: List[int]
        :type bricks: int
        :type ladders: int
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of heights array #####
        len_heights = len(heights)

        ##### Record heap/priority-queue #####
        record_pq = []

        heapify(record_pq)


        ##########################################
        #Heap/Priority-queue based loop traversal
        for heights_idx in range(1, len_heights):

            ##### Check if the current heights difference matched conditions or not #####
            if (heights[heights_idx] <= heights[(heights_idx - 1)]):
                continue

            heappush(record_pq, (heights[heights_idx] - heights[(heights_idx - 1)])) #Keep updating/recording

            ##### Check if the current used ladders enough or not #####
            if (len(record_pq) > ladders):

                ##### Check if the current used bricks enough or not #####
                if (record_pq[0] > bricks):
                    return (heights_idx - 1)
                
                bricks -= record_pq[0] #Keep updating/reducing

                heappop(record_pq) #Keep updating/popped

            else:
                pass

        return (len_heights - 1)
