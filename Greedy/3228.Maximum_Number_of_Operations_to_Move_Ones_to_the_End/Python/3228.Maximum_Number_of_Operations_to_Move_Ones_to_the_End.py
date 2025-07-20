class Solution(object):
    def maxOperations(self, s):
        """
        :type s: str
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record summary ones #####
        record_sum_ones = 0

        ##### Result maximun operations #####
        res_max_oprs = 0


        #############################
        #Greedy-based loop traversal
        while (record_trav_ptr < len_s):

            ##### Check if the current indexed-char is ones or not #####
            if (s[record_trav_ptr] == '0'):
                res_max_oprs += record_sum_ones #Keep updating/accumulating

                while (((record_trav_ptr + 1) < len_s) and (s[(record_trav_ptr + 1)] == '0')):
                    record_trav_ptr += 1 #Keep updating/traversing
            else:
                record_sum_ones += 1 #Keep updating/accumulating

            record_trav_ptr += 1 #Keep updating/traversing

        return res_max_oprs
