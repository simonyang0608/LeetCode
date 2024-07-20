class Solution(object):
    def countBinarySubstrings(self, s):
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

        ##### Record summary counter (i.e. 0s, 1s) #####
        record_cnter_zeros, record_cnter_ones = 0, 0

        ##### Result summary counter #####
        res_cnter = 0


        ###########################################################
        #Greedy-based loop traversal with recorded summary counter
        while (record_trav_ptr < len_s):

            ##### Check if the current indexed-char is 0 or 1 #####
            if (s[record_trav_ptr] == '0'):

                ##### Check if the current summary counter is reset or not #####
                if (record_cnter_zeros):
                    record_cnter_zeros &= 0 #Update/Reset
                else:
                    pass

                while ((record_trav_ptr < len_s) and (s[record_trav_ptr] == '0')):
                    record_cnter_zeros += 1 #Keep updating/accumulating

                    ##### Check if the current summary counter matched conditions or not #####
                    if (record_cnter_ones):
                        record_cnter_ones -= 1 #Keep updating/reducing

                        res_cnter += 1 #Keep updating/accumulating

                    else:
                        pass

                    record_trav_ptr += 1 #Keep updating/accumulating

            else:
                ##### Check if the current summary counter is reset or not #####
                if (record_cnter_ones):
                    record_cnter_ones &= 0 #Update/Reset
                else:
                    pass

                while ((record_trav_ptr < len_s) and (s[record_trav_ptr] == '1')):
                    record_cnter_ones += 1 #Keep updating/accumulating

                    ##### Check if the current summary counter matched conditions or not #####
                    if (record_cnter_zeros):
                        record_cnter_zeros -= 1 #Keep updating/reducing

                        res_cnter += 1 #Keep updating/accumulating

                    else:
                        pass

                    record_trav_ptr += 1 #Keep updating/accumulating

        return res_cnter
