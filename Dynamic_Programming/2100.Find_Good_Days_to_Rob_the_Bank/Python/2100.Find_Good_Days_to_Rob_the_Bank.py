class Solution(object):
    def goodDaysToRobBank(self, security, time):
        """
        :type security: List[int]
        :type time: int
        :rtype: List[int]
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of security array #####
        len_security = len(security)

        ##### Record dynamic-programming (i.e. DP) array #####
        record_incr_dp, record_decr_dp = [1 for _ in range(len_security)], [1 for _ in range(len_security)]

        ##### Result array #####
        res_arry = []


        ##########################################
        #Dynamic-programming based loop traversal
        len_security -= 1 #Update/Reduce

        for decr_dp_idx in range(len_security):

            ##### Check if the current indexed-value matched conditions or not #####
            if (security[decr_dp_idx] >= security[(decr_dp_idx + 1)]):
                record_decr_dp[(decr_dp_idx + 1)] = (record_decr_dp[decr_dp_idx] + 1) #Keep updating/overwriting
            else:
                pass

        for incr_dp_idx in range(len_security, 0, (-1)):

            ##### Check if the current indexed-value matched conditions or not #####
            if (security[incr_dp_idx] >= security[(incr_dp_idx - 1)]):
                record_incr_dp[(incr_dp_idx - 1)] = (record_incr_dp[incr_dp_idx] + 1) #Keep updating/overwriting
            else:
                pass

        len_security += 1 #Update/Increase

        for security_idx in range(len_security):

            ##### Check if the current indexed-value matched conditions or not #####
            if ((record_decr_dp[security_idx] > time) and (record_incr_dp[security_idx] > time)):
                res_arry.append(security_idx) #Keep updating/recording
            else:
                pass

        return res_arry
