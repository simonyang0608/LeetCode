class Solution(object):
    def maxScore(self, cardPoints, k):
        """
        :type cardPoints: List[int]
        :type k: int
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#
        if (len(cardPoints) == k): #Issue/Boundary-case handling
            return sum(cardPoints)
        
        ############
        #Initialize
        ##### Length, Summary of cardPoints array #####
        len_cardPoints, sum_cardPoints = len(cardPoints), sum(cardPoints)

        ##### Record window-size #####
        record_winsize = (len_cardPoints - k)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record score #####
        record_score = 0

        ##### Result minimun score#####
        res_min_score = ((10 ** 9) + 1)


        #####################################
        #Sliding-window based loop traversal
        while (record_right_ptr < len_cardPoints):
            record_score += cardPoints[record_right_ptr] #Keep updating/accumulating

            ##### Check if the current window-size matched conditions or not #####
            if (((record_right_ptr - record_left_ptr) + 1) >= record_winsize):
                res_min_score = min(res_min_score, record_score) #Keep updating/overwriting

                while (((record_right_ptr - record_left_ptr) + 1) >= record_winsize):
                    record_score -= cardPoints[record_left_ptr] #Keep updating/reducing

                    record_left_ptr += 1 #Keep updating/traversing
            else:
                pass

            record_right_ptr += 1 #Keep updating/traversing

        return (sum_cardPoints - res_min_score)
