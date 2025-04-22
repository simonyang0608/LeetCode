class Solution(object):
    def bestTeamScore(self, scores, ages):
        """
        :type scores: List[int]
        :type ages: List[int]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of totals #####
        len_total = len(scores)

        ##### Record array #####
        record_arry = []

        ##### Record dynamic-programming array #####
        record_dp = [0 for _ in range(len_total)]

        ##### Result maximun score #####
        res_max_score = 0


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        ##### Step 1: Record personal informations with array #####
        for total_idx in range(len_total):
            record_arry.append((ages[total_idx], scores[total_idx])) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded array #####
        record_arry.sort() #Sorted-operations

        for total_idx in range(len_total):
            record_dp[total_idx] = (record_arry[total_idx])[1] #Keep updating/overwriting

            for sub_idx in range(total_idx):

                ##### Check if the current indexed-score matched conditions or not #####
                if ((record_arry[sub_idx])[1] <= (record_arry[total_idx])[1]):
                    record_dp[total_idx] = max(record_dp[total_idx], (record_dp[sub_idx] + (record_arry[total_idx])[1])) #Keep updating/overwriting
                else:
                    pass

            res_max_score = max(res_max_score, record_dp[total_idx]) #Keep updating/overwriting

        return res_max_score
