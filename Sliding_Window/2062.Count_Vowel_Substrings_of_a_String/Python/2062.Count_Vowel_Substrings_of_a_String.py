class Solution(object):
    def countVowelSubstrings(self, word):
        """
        :type word: str
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#
        if (len(word) < 5): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Length of word string #####
        len_word = len(word)

        ##### Record dictionary/hashmap (i.e. vowels, summary counter) #####
        record_vowel_dict, record_cnter_dict = {}, {}

        record_vowel_dict['a'] = True
        record_vowel_dict['e'] = True
        record_vowel_dict['i'] = True
        record_vowel_dict['o'] = True
        record_vowel_dict['u'] = True

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Result summary counter #####
        res_cnter = 0


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        while (record_right_ptr < len_word):

            ##### Check if the current indexed-char is vewel or not #####
            if (word[record_right_ptr] in record_vowel_dict):
                record_lbound = record_left_ptr #Record left boundary

                while ((record_right_ptr < len_word) and (word[record_right_ptr] in record_vowel_dict)):

                    ##### Check if the current indexed-char existed or not #####
                    if (word[record_right_ptr] not in record_cnter_dict):
                        record_cnter_dict[word[record_right_ptr]] = 1 #Keep updating/recording
                    else:
                        record_cnter_dict[word[record_right_ptr]] += 1 #Keep updating/recording

                    while (len(record_cnter_dict) >= 5):
                        record_cnter_dict[word[record_left_ptr]] -= 1 #Keep updating/reducing

                        ##### Check if the current indexed-char matched conditions or not #####
                        if (not record_cnter_dict[word[record_left_ptr]]):
                            del record_cnter_dict[word[record_left_ptr]]
                        else:
                            pass

                        record_left_ptr += 1 #Keep updating/traversing

                    res_cnter += (record_left_ptr - record_lbound) #Keep updating/accumulating

                    record_right_ptr += 1 #Keep updating/traversing

                record_cnter_dict.clear() #Keep updating/delete

                record_left_ptr = record_right_ptr #Keep updating/overwriting

            else:
                record_left_ptr += 1 #Keep updating/traversing
                record_right_ptr += 1 #Keep updating/traversing

        return res_cnter
