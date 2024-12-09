class Solution(object):
    def isNStraightHand(self, hand, groupSize):
        """
        :type hand: List[int]
        :type groupSize: int
        :rtype: bool
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of hand array #####
        len_hand = len(hand)

        ##### Sorted operations #####
        hand.sort()

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record heap/priority-queue #####
        record_pq = []

        heapify(record_pq)


        ##########################################
        #Heap/Priority-queue based loop traversal
        ##### Step 1: Record indexed-values, summary counters with heap/priority-queue #####
        while (record_trav_ptr < len_hand):
            while (record_pq and (((record_pq[0])[0] + 1) < hand[record_trav_ptr])):

                ##### Check if the current summary counter matched conditions or not #####
                if ((record_pq[0])[1] < groupSize):
                    return False

                heappop(record_pq) #Keep updating/popped

            ##### Check if the current indexed-value matched conditions or not #####
            if (record_pq and (((record_pq[0])[0] + 1) == hand[record_trav_ptr])):

                ##### Check if the current summary counter matched conditions or not #####
                if ((record_pq[0])[1] < groupSize):
                    heappush(record_pq, [hand[record_trav_ptr], ((record_pq[0])[1] + 1)]) #Keep updating/pushed

                    heappop(record_pq) #Keep updating/popped

                else:
                    heappush(record_pq, [hand[record_trav_ptr], 1]) #Keep updating/pushed

            else:
                heappush(record_pq, [hand[record_trav_ptr], 1]) #Keep updating/pushed

            record_trav_ptr += 1 #Keep updating/traversing

        ##### Step 2: Looped-traversal with recorded heap/priority-queue #####
        while (record_pq):

            ##### Check if the current summary counter matched conditions or not #####
            if ((record_pq[0])[1] != groupSize):
                return False

            heappop(record_pq) #Keep updating/popped

        return True
