class Solution(object):
    def rotateString(self, s, goal):
        """
        :type s: str
        :type goal: str
        :rtype: bool
        """
        #=====================================#
        # Simple comparisons traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record traversal pointer #####
        record_trav_ptr = 0


        #########################################################
        #Simple comparisons loop traversal with recorded pointer
        while (record_trav_ptr < len_s):
            s += s[record_trav_ptr] #Keep updating/accumulating

            ##### Check if the current indexed-string matched conditions or not #####
            if (s[(record_trav_ptr + 1):] == goal):
                return True
            else:
                pass

            record_trav_ptr += 1 #Keep updating, accumulating

        return False
