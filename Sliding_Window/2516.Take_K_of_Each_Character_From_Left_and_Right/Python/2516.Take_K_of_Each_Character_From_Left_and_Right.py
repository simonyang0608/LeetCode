class Solution(object):
    def takeCharacters(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#
        if (not k): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record arrays (i.e. summary counter, visited) #####
        record_arry, record_arry_cnter = [False for _ in range(3)], [0 for _ in range(3)]

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0 

        ##### Record length #####
        record_length = 0

        ##### Result maximun length #####
        res_max_length = 0


        ##########################################################
        #Sliding-window based loop traversal with recorded arrays
        for s_idx in range(len_s):
            record_symb = (ord(s[s_idx]) - 97) #Record symbol

            record_arry_cnter[record_symb] += 1 #Keep updating/accumulating

            ##### Check if the current summary counter matched conditions or not #####
            if (record_arry_cnter[record_symb] >= k):

                ##### Check if the current indexed-char is visited or not #####
                if (not record_arry[record_symb]):
                    record_arry[record_symb] = True #Keep updating/recording

                    record_length += 1
                else:
                    pass
            else:
                pass

        if (record_length < 3):
            return (-1)

        while (record_right_ptr < len_s):
            record_symb = (ord(s[record_right_ptr]) - 97) #Record symbol

            record_arry_cnter[record_symb] -= 1 #Keep updating/reducing

            ##### Check if the current summary counter matched conditions or not #####
            if (record_arry_cnter[record_symb] < k):

                ##### Check if the current indexed-char is visited or not #####
                if (record_arry[record_symb]):
                    record_arry[record_symb] = False #Keep updating/recording

                    record_length -= 1 #Keep updating/reducing
                else:
                    pass
            else:
                pass

            ##### Check if the current length matched conditions or not #####
            if (record_length >= 3):
                res_max_length = max(res_max_length, (record_right_ptr - record_left_ptr + 1)) #Keep updating/overwriting
            else:
                while ((record_left_ptr <= record_right_ptr) and (record_length < 3)):
                    record_symb = (ord(s[record_left_ptr]) - 97) #Record symbol

                    record_arry_cnter[record_symb] += 1 #Keep updating/accumulating

                    ##### Check if the current summary counter matched conditions or not #####
                    if (record_arry_cnter[record_symb] >= k):

                        ##### Check if the current indexed-char is visited or not #####
                        if (not record_arry[record_symb]):
                            record_arry[record_symb] = True #Keep updating/recording

                            record_length += 1 #Keep updating/accumulating
                        else:
                            pass
                    else:
                        pass

                    record_left_ptr += 1 #Keep updating/traversing
            
            record_right_ptr += 1 #Keep updating/traversing

        return (len_s - res_max_length)
