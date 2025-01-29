class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of strings (i.e. s, t) #####
        len_s, len_t = len(s), len(t)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record length #####
        record_length = 0

        ##### Result minimun summary counter #####
        res_min_cnter = ((10 ** 5) + 1)

        ##### Result minimun string #####
        res_min_str = ""


        #######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        for t_idx in range(len_t):

            ##### Check if the current indexed-char existed or not #####
            if (t[t_idx] not in record_dict):
                record_dict[t[t_idx]] = 1 #Keep updating/recording
            else:
                record_dict[t[t_idx]] += 1 #Keep updating/recording

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

            while (record_length >= len_t):

                ##### Check if the current indexed-char existed or not #####
                if (s[record_left_ptr] in record_dict):
                    record_dict[s[record_left_ptr]] += 1 #Keep updating/accumulating

                    ##### Check if the current indexed-char retireved or not #####
                    if (record_dict[s[record_left_ptr]] > 0):

                        ##### Check if the current window-size is smaller or not #####
                        if ((record_right_ptr - record_left_ptr + 1) < res_min_cnter):
                            res_min_cnter = (record_right_ptr - record_left_ptr + 1) #Keep updating/overwriting

                            res_min_str = s[record_left_ptr: (record_right_ptr + 1)] #Keep updating/overwriting
                        else:
                            pass

                        record_length -= 1 #Keep updating/reducing

                    else:
                        pass
                else:
                    pass

                record_left_ptr += 1 #Keep updating/traversing

            record_right_ptr += 1 #Keep updating/traversing

        return res_min_str
