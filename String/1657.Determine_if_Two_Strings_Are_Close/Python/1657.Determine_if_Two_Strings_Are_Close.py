class Solution(object):
    def closeStrings(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: bool
        """
        #========================================#
        # String counting-based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. word1, word2) #####
        len_word1, len_word2 = len(word1), len(word2)

        ##### Record arrays (i.e. word1, word2) #####
        record_arry_word1, record_arry_word2 = [0 for _ in range(26)], [0 for _ in range(26)]


        ##########################################################
        #String counting-based loop traversal with recorded array
        ##### Step 1: Record indexed-char informations with array #####
        for word1_idx in range(len_word1):
            record_arry_word1[(ord(word1[word1_idx]) - 97)] += 1 #Keep updating/recording

        for word2_idx in range(len_word2):

            ##### Check if the current indexed-char existed in word1 or not #####
            if (not record_arry_word1[(ord(word2[word2_idx]) - 97)]):
                return False

            record_arry_word2[(ord(word2[word2_idx]) - 97)] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array
        record_arry_word1.sort() #Sorted operations
        record_arry_word2.sort() #Sorted operations

        for record_idx in range(26):

            ##### Check if the current summary counter matched conditions or not #####
            if (record_arry_word1[record_idx] != record_arry_word2[record_idx]):
                return False

        return True
