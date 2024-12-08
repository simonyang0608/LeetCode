class Solution(object):
    def numDecodings(self, s):
        """
        :type s: str
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        len_s += 1

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp_arry = [0 for _ in range(len_s + 1)]

        record_dp_arry[0] = 1


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for s_idx in range(1, len_s):

            ##### Check if the current indexed-value matched conditions or not #####
            if (int(s[(s_idx - 1)]) != 0):
                record_dp_arry[s_idx] = record_dp_arry[(s_idx - 1)] #Keep updating/overwriting
            else:
                pass

            ##### Check if the current indexed-value matched conditions or not #####
            if ((s_idx > 1) and (int(s[s_idx - 2]) != 0) and (int(s[(s_idx - 2): s_idx]) <= 26)):
                record_dp_arry[s_idx] += record_dp_arry[(s_idx - 2)] #Keep updating/overwriting
            else:
                pass

        return record_dp_arry[(len_s - 1)]
