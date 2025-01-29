class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of strings (i.e. s1, s2) #####
        len_s1, len_s2 = len(s1), len(s2)

        if (len_s1 > len_s2): #Issue/Boundary-case handling
            return False

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record length #####
        record_length = 0

        ##### Result minimun summary counter #####
        res_min_cnter = ((10 ** 4) + 1)


        ######################################################################
        #Sliding-window based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-char with dictionary/hashmap
        for s1_idx in range(len_s1):

            ##### Check if the current indexed-char existed or not #####
            if (s1[s1_idx] not in record_dict):
                record_dict[s1[s1_idx]] = 1 #Keep updating/recording
            else:
                record_dict[s1[s1_idx]] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap
        while (record_right_ptr < len_s2):

            ##### Check if the current indexed-char existed or not #####
            if (s2[record_right_ptr] in record_dict):
                record_dict[s2[record_right_ptr]] -= 1 #Keep updating/reducing

                ##### Check if the current indexed-char existed or not #####
                if (record_dict[s2[record_right_ptr]] >= 0):
                    record_length += 1 #Keep updating/accumulating
                else:
                    pass
            else:
                pass

            while (record_length >= len_s1):

                ##### Check if the current indexed-char existed or not #####
                if (s2[record_left_ptr] in record_dict):
                    record_dict[s2[record_left_ptr]] += 1 #Keep updating/accumulating

                    ##### Check if the current indexed-char retrieved or not #####
                    if (record_dict[s2[record_left_ptr]] > 0):

                        ##### Check if the current window-size is smaller or not #####
                        if ((record_right_ptr - record_left_ptr + 1) < res_min_cnter):
                            res_min_cnter = (record_right_ptr - record_left_ptr + 1) #Keep updating/overwriting
                        else:
                            pass

                        record_length -= 1 #Keep updating/reducing
                    else:
                        pass
                else:
                    pass

                record_left_ptr += 1 #Keep updating/traversing

            record_right_ptr += 1 #Keep updating/traversing

        return (True if (res_min_cnter == len_s1) else False)
