class Solution(object):
    def countVowels(self, word):
        """
        :type word: str
        :rtype: int
        """
        #========================================#
        # One-pass update based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of word #####
        len_word = len(word)

        ##### Record dictionary/hashmap #####
        record_dict = {'a': True, 'e': True, 'i': True, 'o': True, 'u': True}

        ##### Result summary value #####
        res_sum_val = 0


        #######################################################################
        #One-pass update based loop traversal with recorded dictionary/hashmap
        for word_idx in range(len_word):

            #### Check if the current indexed-char existed or not #####
            if (word[word_idx] in record_dict):
                res_sum_val += ((word_idx + 1) * (len_word - word_idx)) #Keep updating/accumulating
            else:
                pass

        return res_sum_val
