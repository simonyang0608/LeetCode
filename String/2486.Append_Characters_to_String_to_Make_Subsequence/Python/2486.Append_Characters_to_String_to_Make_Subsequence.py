class Solution(object):
    def appendCharacters(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of strings (i.e. s, t) #####
        len_s, len_t = len(s), len(t)

        ##### Record traversal pointers (i.e. s, t) #####
        record_trav_ptrs, record_trav_ptrt = 0, 0


        ###################################
        #Two-pointers based loop traversal
        while (record_trav_ptrs < len_s):

            ##### Check if the current indexed-char is the same or not #####
            if ((record_trav_ptrt < len_t) and (s[record_trav_ptrs] == t[record_trav_ptrt])):
                record_trav_ptrt += 1 #Keep updating/traversing
            else:
                pass

            record_trav_ptrs += 1 #Keep updating/traversing

        return (len_t - record_trav_ptrt)
