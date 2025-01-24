class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of s string, wordDict vector #####
        len_s, len_wordDict = len(s), len(wordDict)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record dynamic-programming array #####
        record_dp = [0 for _ in range((len_s + 1))]


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for record_idx in range(len_wordDict):
            record_dict[wordDict[record_idx]] = True #Keep updating/recording

        for record_idx in range(1, (len_s + 1)):
            record_dp[record_idx] = (record_dp[(record_idx - 1)] + 1) #Keep updating/overwriting

            for sub_idx in range((record_idx - 1), (-1), (-1)):
                record_str = s[sub_idx: record_idx] #Record string

                ##### Check if the current string existed or not #####
                if (record_str in record_dict):

                    ##### Check if the current status matched conditions or not #####
                    if (not record_dp[sub_idx]):
                        record_dp[record_idx] = 0 #Keep updating/overwriting

                        break

                    record_dp[record_idx] = min(record_dp[record_idx], record_dp[sub_idx]) #Keep updating/overwriting
                else:
                    pass

        return (True if (not record_dp[len_s]) else False)
