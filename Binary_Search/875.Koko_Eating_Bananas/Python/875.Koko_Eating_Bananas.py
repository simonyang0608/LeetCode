class Solution(object):
    def minEatingSpeed(self, piles, h):
        """
        :type piles: List[int]
        :type h: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of piles array #####
        len_piles = len(piles)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 1, max(piles)


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            record_flag = self.canEatAll(len_piles, piles, record_mid_ptr, h) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (record_flag):
                record_right_ptr = record_mid_ptr #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        return record_left_ptr


    def canEatAll(self, len_piles, piles, record_val, h):
        """
        :type len_piles: int
        :type piles: List[int]
        :type record_val: int
        :type h: int
        :rtype: bool
        """
        #========================================#
        # Binary-search based traversal function #
        #========================================#

        ############
        #Initialize
        ##### Result summary value #####
        res_sum_val = 0

        #####################
        #Whole process/flow
        for piles_idx in range(len_piles):
            record_quot, record_mod = (piles[piles_idx] // record_val), (piles[piles_idx] % record_val) #Record quotient, module

            ##### Check if the current module matched conditions or not #####
            if (record_mod):
                res_sum_val += (record_quot + 1) #Keep updating/accumulating
            else:
                res_sum_val += record_quot #Keep updating/accumulating

            ##### Check if the current summary value matched conditions or not #####
            if (res_sum_val > h):
                return False

        return True
