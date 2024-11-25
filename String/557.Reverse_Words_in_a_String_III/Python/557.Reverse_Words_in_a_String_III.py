class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)
        
        ##### Record s array #####
        record_s = list(s)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0


        ###################################
        #Two-pointers based loop traversal
        while (record_right_ptr < len_s):

            ##### Check if the current indexed-char matched conditions or not #####
            if (((record_right_ptr + 1) >= len_s) or (s[(record_right_ptr + 1)] == ' ')):
                record_wdw = (((record_right_ptr + 1) - record_left_ptr) // 2) #Record window

                for record_idx in range(record_wdw):
                    record_s[record_left_ptr], record_s[(record_right_ptr - record_idx)] = record_s[(record_right_ptr - record_idx)], record_s[record_left_ptr] #Keep updating/swap
                
                    record_left_ptr += 1 #Keep updating/traversing

                record_right_ptr += 2 #Keep updating/traversing
                record_left_ptr = record_right_ptr #Keep updating/traversing

            else:
                record_right_ptr += 1 #Keep updating/traversing

        return ''.join(record_s)
