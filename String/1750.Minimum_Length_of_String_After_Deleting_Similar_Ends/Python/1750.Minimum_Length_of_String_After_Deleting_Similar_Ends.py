class Solution(object):
    def minimumLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        #############
        #Iniitialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_s - 1)


        ###################################
        #Two-pointers based loop traversal
        while (record_left_ptr < record_right_ptr):

            ##### Check if the current indexed-char is the same or not #####
            if (s[record_left_ptr] == s[record_right_ptr]):
                while (((record_left_ptr + 1) < len_s) and (s[record_left_ptr] == s[(record_left_ptr + 1)])):
                    record_left_ptr += 1 #Keep updating/traversing
                
                while (((record_right_ptr - 1) >= 0) and (s[record_right_ptr] == s[(record_right_ptr - 1)])):
                    record_right_ptr -= 1 #Keep updating/traversing

                record_left_ptr += 1 #Keep updating/traversing
                record_right_ptr -= 1 #Keep updating/traversing

            else:
                break

        return (0 if (record_left_ptr > record_right_ptr) else (record_right_ptr - record_left_ptr + 1))
