class Solution(object):
    def minimumDeletions(self, s):
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

        ##### Record summary counter #####
        record_cnter = 0

        ##### Result summary counter #####
        res_cnter = 0


        #############################
        #Greedy-based loop traversal
        for s_idx in range(len_s):

            ##### Check if the current indexed-char matched conditions or not #####
            if (s[s_idx] == 'b'):
                record_cnter += 1 #Keep updating/accumulating
            else:
                ##### Check if the current summary counter matched conditions or not #####
                if (record_cnter):
                    res_cnter += 1 #Keep updating/accumulating

                    record_cnter -= 1 #Keep updating/reducing
                else:
                    pass

        return res_cnter
