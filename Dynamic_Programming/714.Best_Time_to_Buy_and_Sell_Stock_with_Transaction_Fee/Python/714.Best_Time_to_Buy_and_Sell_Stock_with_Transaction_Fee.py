class Solution(object):
    def maxProfit(self, prices, fee):
        """
        :type prices: List[int]
        :type fee: int
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of prices array #####
        len_prices = len(prices)

        ##### Record dynamic-programming arrays (i.e. earned, cost) #####
        record_dp_earned, record_dp_cost = [0 for _ in range(len_prices)], [0 for _ in range(len_prices)]


        ##########################################
        #Dynamic-programming based loop traversal
        record_dp_cost[0] = ((-1) * prices[0]) #Update/Overwrite

        for prices_idx in range(1, len_prices):
            record_dp_earned[prices_idx] = max(record_dp_earned[(prices_idx - 1)], 
                                               (prices[prices_idx] + record_dp_cost[(prices_idx - 1)] - fee)) #Keep updating/overwriting

            record_dp_cost[prices_idx] = max(record_dp_cost[(prices_idx - 1)], 
                                             record_dp_earned[prices_idx] - prices[prices_idx]) #Keep updating/overwriting

        return record_dp_earned[(-1)]
