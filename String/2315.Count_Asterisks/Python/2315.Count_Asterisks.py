class Solution(object):
    def countAsterisks(self, s):
        """
        :type s: str
        :rtype: int
        """
        #========================================#
        # One-pass record based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result summary counter #####
        res_cnter = 0


        ######################################
        #One-pass record based loop traversal
        while (record_trav_ptr < len_s):

            ##### Check if the current indexed-char matched conditions or not #####
            if (s[record_trav_ptr] == "|"):
                while (((record_trav_ptr + 1) < len_s) and (s[(record_trav_ptr + 1)] != "|")):
                    record_trav_ptr += 1 #Keep updating/traversing

                record_trav_ptr += 2 #Keep updating/traversing

            else:
                ##### Check if the current indexed-char matched conditions or not #####
                if (s[record_trav_ptr] == "*"):
                    res_cnter += 1 #Keep updating/accumulating
                else:
                    pass

                record_trav_ptr += 1 #Keep updating/traversing

        return res_cnter
