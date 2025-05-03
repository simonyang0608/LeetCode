class Solution(object):
    def mostPoints(self, questions):
        """
        :type questions: List[List[int]]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of questions array #####
        len_questions = len(questions)

        ##### Record dynamic-programming array #####
        record_dp = [0 for _ in range(len_questions)]


        ####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for questions_idx in range((len_questions - 1), (-1), (-1)):
            record_dp[questions_idx] += (questions[questions_idx])[0] #Keep updating/accumulating

            next_idx = (questions_idx + (questions[questions_idx])[1] + 1) #Next index

            ##### Check if the next index exceed boundary or not #####
            if (next_idx >= len_questions):
                pass
            else:
                record_dp[questions_idx] += record_dp[next_idx] #Keep updating/accumulating

            ##### Check if the current index matched conditions or not #####
            if (questions_idx < (len_questions - 1)):
                record_dp[questions_idx] = max(record_dp[questions_idx], record_dp[(questions_idx + 1)]) #Keep updating/overwriting
            else:
                pass

        return record_dp[0]
