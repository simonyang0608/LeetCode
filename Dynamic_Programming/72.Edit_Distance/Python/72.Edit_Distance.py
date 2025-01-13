class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. word1, word2) #####
        len_word1, len_word2 = len(word1), len(word2)

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [[0 for _ in range((len_word2 + 1))] for _ in range((len_word1 + 1))]


        ##########################################
        #Dynamic-programming based loop traversal
        ##### Step 1: Record rows, columns informations with dynamic-programming array #####
        for rows_idx in range(1, (len_word1 + 1)):
            (record_dp[rows_idx])[0] = rows_idx #Keep updating/overwriting

        for cols_idx in range(1, (len_word2 + 1)):
            (record_dp[0])[cols_idx] = cols_idx #Keep updating/overwriting

        ##### Step 2: Looped-traversal with recorded dynamic-programming array #####
        for rows_idx in range(1, (len_word1 + 1)):
            for cols_idx in range(1, (len_word2 + 1)):

                ##### Check if the current indexed-char is the same or not #####
                if (word1[(rows_idx - 1)] == word2[(cols_idx - 1)]):
                    (record_dp[rows_idx])[cols_idx] = (record_dp[(rows_idx - 1)])[(cols_idx - 1)] #Keep updating/overwriting
                else:
                    (record_dp[rows_idx])[cols_idx] = (min((record_dp[(rows_idx - 1)])[(cols_idx - 1)], (record_dp[(rows_idx - 1)])[cols_idx], (record_dp[rows_idx])[(cols_idx - 1)]) + 1) #Keep updating/overwriting

        return (record_dp[len_word1])[len_word2]
