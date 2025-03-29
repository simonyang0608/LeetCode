class Solution(object):
    def minimumTotal(self, triangle):
        """
        :type triangle: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of triangle array #####
        len_triangle = len(triangle)

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = deepcopy(triangle[(-1)]) 


        ##########################################
        #Dynamic-programming based loop traversal
        for triangle_idx in range((len_triangle - 2), (-1), (-1)):
            for record_idx in range((triangle_idx + 1)):
                record_dp[record_idx] = (min(record_dp[record_idx], record_dp[(record_idx + 1)]) + (triangle[triangle_idx])[record_idx]) #Keep updating/overwriting

        return record_dp[0]
