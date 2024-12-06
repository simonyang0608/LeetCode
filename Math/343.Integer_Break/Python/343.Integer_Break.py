class Solution(object):
    def integerBreak(self, n):
        """
        :type n: int
        :rtype: int
        """
        #=============================#
        # Math-based traversal method #
        #=============================#

        ############
        #Initialize
        ##### Record times #####
        record_times = (n // 2)

        ##### Result maximun product #####
        res_max_prod = 0


        ###########################
        #Math-based loop traversal
        for k_idx in range(1, (record_times + 1)):
            record_prod = k_idx #Record product
            record_remains = (n - k_idx) #Record remainings

            while (record_remains > 0):
                res_max_prod = max(res_max_prod, (record_prod * record_remains)) #Keep updating/overwriting

                record_prod *= k_idx #Keep updating/overwriting
                record_remains -= k_idx #Keep updating/overwriting

        return res_max_prod
