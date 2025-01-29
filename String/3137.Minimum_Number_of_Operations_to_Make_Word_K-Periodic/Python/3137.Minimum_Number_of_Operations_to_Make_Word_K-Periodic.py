class Solution(object):
    def minimumOperationsToMakeKPeriodic(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of word string #####
        len_word = len(word)

        ##### Total summary counter #####
        total_cnter = (len_word // k)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        while (record_trav_ptr < len_word):
            record_str = word[record_trav_ptr: (record_trav_ptr + k)] #Record string

            ##### Check if the current indexed-string existed or not #####
            if (record_str not in record_dict):
                record_dict[record_str] = 1 #Keep updating/recording
            else:
                record_dict[record_str] += 1 #Keep updating/recording

            res_max_cnter = max(res_max_cnter, record_dict[record_str]) #Keep updating/overwriting

            record_trav_ptr += k #Keep updating/traversing

        return (total_cnter - res_max_cnter)
