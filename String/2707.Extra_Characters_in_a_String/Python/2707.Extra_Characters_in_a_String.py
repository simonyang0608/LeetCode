class Solution(object):
    def minExtraChar(self, s, dictionary):
        """
        :type s: str
        :type dictionary: List[str]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record dynamic-programming array #####
        record_dp = [0 for s_idx in range((len_s + 1))]

        ##### Record set #####
        record_set = set(dictionary)


        ##########################################
        #Dynamic-programming based loop traversal
        for s_idx in range(1, (len_s + 1)):
            record_dp[s_idx] = (record_dp[(s_idx - 1)] + 1) #Keep updating/overwriting

            for record_idx in range((s_idx - 1), (-1), (-1)):

                ##### Check if the current indexed-string existed or not #####
                if (s[record_idx: s_idx] in record_set):
                    record_dp[s_idx] = min(record_dp[record_idx], record_dp[s_idx]) #Keep updating/overwriting
                else:
                    pass

        return record_dp[len_s]
