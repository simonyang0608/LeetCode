class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of prices array #####
        len_prices = len(prices)

        ##### Record dynamic-programming arrays (i.e. cost, earn) #####
        record_dp_earn, record_dp_cost = [0 for _ in range(3)], [float("-inf") for _ in range(3)]

        ##### Result maximun value #####
        res_max_val = 0


        ##########################################
        #Dynamic-programming based loop traversal
        for prices_idx in range(len_prices):
            for record_idx in range(1, 3):
                record_dp_cost[record_idx] = max(record_dp_cost[record_idx], 
                                                (record_dp_earn[(record_idx - 1)] - prices[prices_idx])) #Keep updating/overwriting

                record_dp_earn[record_idx] = max(record_dp_earn[record_idx], 
                                                (record_dp_cost[record_idx] + prices[prices_idx])) #Keep updating/overwriting

                res_max_val = max(res_max_val, record_dp_earn[record_idx]) #Keep updating/overwriting

        return res_max_val
