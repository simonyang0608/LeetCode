class Solution(object):
    def longestCommonSubsequence(self, text1, text2):
        """
        :type text1: str
        :type text2: str
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of texts array (i.e. 1, 2) #####
        len_text1, len_text2 = len(text1), len(text2)

        ##### Record dynamic-programming array #####
        record_dp = [[0 for _ in range((len_text2 + 1))] for _ in range((len_text1 + 1))]


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for text1_idx in range(1, (len_text1 + 1)):
            for text2_idx in range(1, (len_text2 + 1)):

                ##### Check if thhe current indexed-char matched conditions or not #####
                if ((text1[(text1_idx - 1)] == text2[(text2_idx - 1)])):
                    (record_dp[text1_idx])[text2_idx] = ((record_dp[(text1_idx - 1)])[(text2_idx - 1)] + 1) #Keep updating, overwriting
                else:
                    (record_dp[text1_idx])[text2_idx] = max((record_dp[(text1_idx - 1)])[text2_idx], (record_dp[text1_idx])[(text2_idx - 1)]) #Keep updating, overwriting

        return (record_dp[len_text1])[len_text2]
