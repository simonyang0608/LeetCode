class Solution(object):
    def findMaxForm(self, strs, m, n):
        """
        :type strs: List[str]
        :type m: int
        :type n: int
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of strs array #####
        len_strs = len(strs)

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [[0 for _ in range(n + 1)] for _ in range (m + 1)]


        ##########################################
        #Dynamic-programming based loop traversal
        for strs_idx in range(len_strs):
            len_str = len(strs[strs_idx]) #Length of str string

            zeros_cnter, ones_cnter = 0, 0 #Zeros, Ones summary counter

            for str_idx in range(len_str):

                ##### Check if the current char is zeros or not #####
                if ((strs[strs_idx])[str_idx] == '0'):
                    zeros_cnter += 1 #Keep updating/accumulating
                else:
                    ones_cnter += 1 #Keep updating/accumulating

            for zeros_idx in range(m, (zeros_cnter - 1), (-1)):
                for ones_idx in range(n, (ones_cnter - 1), (-1)):
                    (record_dp[zeros_idx])[ones_idx] = max((record_dp[zeros_idx])[ones_idx], ((record_dp[(zeros_idx - zeros_cnter)])[(ones_idx - ones_cnter)] + 1)) #Keep updating/overwriting

        return (record_dp[m])[n]
