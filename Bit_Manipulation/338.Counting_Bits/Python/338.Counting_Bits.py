class Solution(object):
    def countBits(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        #=========================================#
        # Bit-manipulation based traversal method #
        #=========================================#

        ############
        #Initialize
        ##### Result array #####
        res_arry = [0 for _ in range((n + 1))]

        ####################
        #Whole process/flow
        for n_idx in range((n + 1)):
            record_cnter = self.countBit(n_idx) #Record summary counter

            res_arry[n_idx] = record_cnter #Keep updating/overwriting

        return res_arry


    def countBit(self, n_idx):
        """
        :type n_idx: int
        :rtype: int
        """
        #===========================================#
        # Bit-manipulation based traversal function #
        #===========================================#

        ############
        #Initialize
        ##### Result summary counter #####
        res_cnter = 0

        ####################
        #Whole process/flow
        while (n_idx):
            res_cnter += (n_idx & 1) #Keep updating/accumulating

            n_idx >>= 1 #Keep updating/bit-shifting

        return res_cnter
