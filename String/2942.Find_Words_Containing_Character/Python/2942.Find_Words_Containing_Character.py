class Solution(object):
    def findWordsContaining(self, words, x):
        """
        :type words: List[str]
        :type x: str
        :rtype: List[int]
        """
        #========================================#
        # One-pass record based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of words array #####
        len_words = len(words)

        ##### Result array #####
        res_arry = []


        ######################################
        #One-pass record based loop traversal
        for words_idx in range(len_words):

            ##### Check if the current indexed-char existed or not #####
            if (x not in words[words_idx]):
                continue

            res_arry.append(words_idx) #Keep updating/recording

        return res_arry
