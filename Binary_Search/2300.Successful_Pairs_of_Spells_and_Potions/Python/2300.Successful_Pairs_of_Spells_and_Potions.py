class Solution(object):
    def successfulPairs(self, spells, potions, success):
        """
        :type spells: List[int]
        :type potions: List[int]
        :type success: int
        :rtype: List[int]
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. spells, potions) #####
        len_spells, len_potions = len(spells), len(potions)

        ##### Result array #####
        res_arry = []


        ###########################################################
        #Binary-search based loop traversal with sorted-operations
        potions.sort() #Sorted-operations

        for spells_idx in range(len_spells):
            record_idx = self.binarySearch(len_potions, potions, spells[spells_idx], success) #Record index

            res_arry.append((len_potions - record_idx)) #Keep updating/recording

        return res_arry


    def binarySearch(self, len_potions, potions, spells_val, success_val):
        """
        :type len_potions: int
        :type potions: List[int]
        :type spells_val: int
        :type success_val: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_potions - 1)

        ####################
        #Whole process/flow
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) // 2)) #Record middle pointer

            record_prod = (potions[record_mid_ptr] * spells_val) #Record product value

            ##### Check if the current product value matched conditions or not #####
            if (record_prod < success_val):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return record_left_ptr
