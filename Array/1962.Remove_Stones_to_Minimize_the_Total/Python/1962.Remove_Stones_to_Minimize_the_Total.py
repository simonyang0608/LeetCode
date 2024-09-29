class Solution(object):
    def minStoneSum(self, piles, k):
        """
        :type piles: List[int]
        :type k: int
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of piles array #####
        len_piles = len(piles)

        ##### Updated/Heapify piles array #####
        for piles_idx in range(len_piles):
            piles[piles_idx] *= (-1)

        heapify(piles)

        
        ##########################################
        #Heap/Priority-queue based loop traversal
        for k_idx in range(k):
            curr_min_val = heappop(piles) #Current minimun value

            ##### Check if the current indexed-value is divisable by 2 or not #####
            if (not (curr_min_val % 2)):
                heappush(piles, (curr_min_val - (curr_min_val // 2))) #Keep updating/recording
            else:
                heappush(piles, (curr_min_val - ((curr_min_val // 2) + 1))) #Keep updating/recording

        return (sum(piles) * (-1))
