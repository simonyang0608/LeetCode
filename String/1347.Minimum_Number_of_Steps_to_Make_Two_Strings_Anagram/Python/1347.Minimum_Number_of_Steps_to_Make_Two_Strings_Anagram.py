class Solution(object):
    def minSteps(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        #========================================#
        # String counting-based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record array #####
        record_arry = [0 for _ in range(26)]

        ##### Result minimun operations #####
        res_min_oprs = 0


        ##########################################################
        #String counting-based loop traversal with recorded array
        ##### Step 1: Record indexed-char informations with array #####
        for s_idx in range(len_s):
            record_arry[(ord(s[s_idx]) - 97)] += 1 #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array #####
        for t_idx in range(len_s):
            record_arry[(ord(t[t_idx]) - 97)] -= 1 #Keep updating/reducing

            ##### Check if the current summary counter matched conditions or not #####
            if (record_arry[(ord(t[t_idx]) - 97)] < 0):
                res_min_oprs += 1 #Keep updating/accumulating
            else:
                pass

        return res_min_oprs
