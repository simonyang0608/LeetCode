class Solution(object):
    def countHousePlacements(self, n):
        """
        :type n: int
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### N-th amount #####
        n += 1

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp_arry = [0 for _ in range(n)]

        record_dp_arry[0] = 1
        record_dp_arry[1] = 2

        ##### Record module ######
        record_module = ((10 ** 9) + 7)


        ##########################################
        #Dynamic-programming based loop traversal
        for n_idx in range(2, n):
            record_dp_arry[n_idx] += ((record_dp_arry[(n_idx - 1)] + record_dp_arry[(n_idx - 2)]) % record_module) #Keep updating/overwriting

        return ((record_dp_arry[(n - 1)] ** 2) % record_module)
