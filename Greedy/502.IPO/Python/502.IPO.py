class Solution(object):
    def findMaximizedCapital(self, k, w, profits, capital):
        """
        :type k: int
        :type w: int
        :type profits: List[int]
        :type capital: List[int]
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of profits array #####
        len_profits = len(profits)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record array #####
        record_arry = []

        ##### Record heap/priority-queue #####
        record_pq = []


        ##############################################################
        #Heap/Priority-queue based loop traversal with recorded array
        ##### Step 1: Record capital-profits informations with array #####
        for profits_idx in range(len_profits):
            record_arry.append((capital[profits_idx], profits[profits_idx])) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array #####
        record_arry.sort() #Sorted operations

        heapify(record_pq) #Update/Heapify

        for k_idx in range(k):
            while ((record_trav_ptr < len_profits) and (record_arry[record_trav_ptr])[0] <= w):
                heappush(record_pq, ((-1) * (record_arry[record_trav_ptr])[1])) #Keep updating/recording

                record_trav_ptr += 1 #Keep updating/traversing

            ##### Check if the current size is empty or not #####
            if (not record_pq):
                break

            w += ((-1) * heappop(record_pq)) #Keep updating/accumulating

        return w
