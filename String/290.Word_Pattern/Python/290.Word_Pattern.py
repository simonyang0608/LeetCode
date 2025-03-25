class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of strings (i.e. pattern, s) #####
        len_pattern, len_s = len(pattern), len(s)

        ##### Record traversal pointers (i.e. pattern, s) #####
        record_trav_ptrp, record_trav_ptrs = 0, 0

        ##### Record dictionary, hashmaps (i.e. char-string, string-char) #####
        record_dict_cs, record_dict_sc = {}, {}


        ##############################
        #Hashmap-based loop traversal
        while (record_trav_ptrs < len_s):
            record_str = "" #Record string

            while ((record_trav_ptrs < len_s) and (s[record_trav_ptrs] != ' ')):
                record_str += s[record_trav_ptrs] #Keep updating/recording

                record_trav_ptrs += 1 #Keep updating/traversing

            ##### Check if the current pointer exceed boundary or not #####
            if (record_trav_ptrp < len_pattern):

                ##### Check if the current char existed or not #####
                if (pattern[record_trav_ptrp] in record_dict_cs):

                    ##### Check if the current key-value is matched or not #####
                    if (record_dict_cs[pattern[record_trav_ptrp]] != record_str):
                        return False
                else:
                    record_dict_cs[pattern[record_trav_ptrp]] = record_str #Keep updating/recording

                ##### Check if the current string existed or not #####
                if (record_str in record_dict_sc):

                    ##### Check if the current key-value is matched or not #####
                    if (record_dict_sc[record_str] != pattern[record_trav_ptrp]):
                        return False
                else:
                    record_dict_sc[record_str] = pattern[record_trav_ptrp] #Keep updating/recording

                record_trav_ptrp += 1 #Keep updating/traversing
            else:
                return False

            record_trav_ptrs += 1 #Keep updating/traversing

        return (True if (record_trav_ptrp >= len_pattern) else False)
