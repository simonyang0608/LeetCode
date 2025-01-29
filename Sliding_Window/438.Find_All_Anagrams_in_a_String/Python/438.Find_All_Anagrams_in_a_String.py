class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of strings (i.e. s, p) #####
        len_s, len_p = len(s), len(p)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record length #####
        record_length = 0

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Result array #####
        res_arry = []


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-char with dictionary/hashmap
        if (len_p > len_s): #Issue/Boundary-case handling
            return res_arry

        for p_idx in range(len_p):

            ##### Check if the current indexed-char existed or not #####
            if (p[p_idx] not in record_dict):
                record_dict[p[p_idx]] = 1 #Keep updating/recording
            else:
                record_dict[p[p_idx]] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        while (record_right_ptr < len_s):

            ##### Check if the current indexed-char existed or not #####
            if (s[record_right_ptr] in record_dict):
                record_dict[s[record_right_ptr]] -= 1 #Keep updating/reducing

                ##### Check if the current indexed-char existed or not #####
                if (record_dict[s[record_right_ptr]] >= 0):
                    record_length += 1 #Keep updating/accumulating
                else:
                    pass
            else:
                pass

            while (record_length >= len_p):

                ##### Check if the current indexed-char existed or not #####
                if (s[record_left_ptr] in record_dict):
                    record_dict[s[record_left_ptr]] += 1 #Keep updating/accumulating

                    ##### Check if the current indexed-char retrieved or not #####
                    if (record_dict[s[record_left_ptr]] > 0):

                        ##### Check if the current window-size matched conditions or not #####
                        if ((record_right_ptr - record_left_ptr + 1) == len_p):
                            res_arry.append(record_left_ptr) #Keep updating/recording
                        else:
                            pass

                        record_length -= 1 #Keep updating/reducing
                    else:
                        pass
                else:
                    pass

                record_left_ptr += 1 #Keep updating/traversing

            record_right_ptr += 1 #Keep updating/traversing

        return res_arry
