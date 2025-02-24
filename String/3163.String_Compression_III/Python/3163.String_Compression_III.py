class Solution(object):
    def compressedString(self, word):
        """
        :type word: str
        :rtype: str
        """
        #================================#
        # Pointer-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of word array #####
        len_word = len(word)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result string #####
        res_str = ""


        ##############################
        #Pointer-based loop traversal
        while (record_trav_ptr < len_word):
            record_cnter = 1 #Record summary counter

            while (((record_trav_ptr + 1) < len_word) and (word[record_trav_ptr] == word[(record_trav_ptr + 1)])):
                record_cnter += 1 #Keep updating/accumulating

                record_trav_ptr += 1 #Keep updating/traversing

                ##### Check if the current summary counter is larger than 9 or not #####
                if (record_cnter >= 9):
                    break

            res_str += (str(record_cnter) + word[record_trav_ptr]) #Keep updating/recording

            record_trav_ptr += 1 #Keep updating/traversing

        return res_str
