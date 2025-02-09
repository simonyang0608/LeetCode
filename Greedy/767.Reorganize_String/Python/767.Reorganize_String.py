class Solution(object):
    def reorganizeString(self, s):
        """
        :type s: str
        :rtype: str
        """
        #==============================#
        # Greed-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record traversal pointer #####
        record_trav_ptr = 1

        ##### Record array #####
        record_arry = []

        ##### Result array #####
        res_arry = ['1' for _ in range(len_s)]

        ##### Result string #####
        res_str = ""


        ####################################################################
        #Greed-based loop traversal with recorded dictionary/hashmap, array
        ##### Step 1: Record indexed-char with dictionary/hashmap, array #####
        for s_idx in range(len_s):

            ##### Check if the current indexed-char existed or not #####
            if (s[s_idx] not in record_dict):
                record_dict[s[s_idx]] = 1 #Keep updating/recording
            else:
                record_dict[s[s_idx]] += 1 #Keep updating/recording

        for record_key in record_dict:
            record_arry.append((record_dict[record_key], record_key)) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap, array #####
        record_arry.sort() #Sorted operations

        for (record_cnter, record_chr) in record_arry:
            if ((record_cnter - 1) > (len_s - record_cnter)): #Issue/Boundary-case handling
                return res_str
            
            for record_idx in range(record_cnter):

                ##### Check if the current traversal pointer exceed boundary or not #####
                if (record_trav_ptr >= len_s):
                    record_trav_ptr &= 0 #Keep updating/reset
                else:
                    pass

                res_arry[record_trav_ptr] = record_chr #Keep updating/overwriting

                record_trav_ptr += 2 #Keep updating/traversing

        for s_idx in range(len_s):
            res_str += res_arry[s_idx] #Keep updating/recording

        return res_str
