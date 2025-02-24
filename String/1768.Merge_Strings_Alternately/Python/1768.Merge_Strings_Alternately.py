class Solution(object):
    def mergeAlternately(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: str
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of strings (i.e. word1, word2) #####
        len_word1, len_word2 = len(word1), len(word2)

        ##### Record pointers (i.e. word1, word2) #####
        record_ptr_word1, record_ptr_word2 = 0, 0

        ##### Result string #####
        res_str = ""


        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Looped-traversal for the fixed-intervals #####
        while ((record_ptr_word1 < len_word1) and (record_ptr_word2 < len_word2)):
            res_str += word1[record_ptr_word1] #Keep updating/recording

            res_str += word2[record_ptr_word2] #Keep updating/recording

            record_ptr_word1 += 1 #Keep updating/traversing
            record_ptr_word2 += 1 #Keep updating/traversing

        ##### Step 2: Looped-traversal for the remainings #####
        while (record_ptr_word1 < len_word1):
            res_str += word1[record_ptr_word1] #Keep updating/recording

            record_ptr_word1 += 1 #Keep updating/traversing

        while (record_ptr_word2 < len_word2):
            res_str += word2[record_ptr_word2] #Keep updating/recording

            record_ptr_word2 += 1 #Keep updating/traversing

        return res_str
