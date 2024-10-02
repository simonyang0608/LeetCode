class Solution(object):
    def pickGifts(self, gifts, k):
        """
        :type gifts: List[int]
        :type k: int
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of gifts array #####
        len_gifts = len(gifts)

        ##### Record summary value #####
        record_sum_val = sum(gifts)

        ##### Record oprations counter #####
        record_oprs_cnter = 0

        ##### Update/Heapify gifts array #####
        for gifts_idx in range(len_gifts):
            gifts[gifts_idx] *= (-1)

        heapify(gifts)


        ##########################################
        #Heap/Priority-queue based loop traversal
        while (record_oprs_cnter < k):
            curr_min_val = heappop(gifts) #Current minimun value
            curr_sqrt_max_val = int(sqrt((curr_min_val * (-1)))) #Current squart-of minimun value

            record_sum_val += (curr_min_val + curr_sqrt_max_val) #Keep updating/reducing

            heappush(gifts, (curr_sqrt_max_val * (-1))) #Keep updating/recording

            record_oprs_cnter += 1 #Keep updating/accumulating

        return record_sum_val
