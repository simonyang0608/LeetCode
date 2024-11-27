class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of prices array #####
        len_prices = len(prices)

        ##### Record traversal pointers #####
        record_trav_ptr = 1

        ##### Result, Record maximun profit #####
        res_max_profit, record_max_profit = 0, 0


        #############################
        #Greedy-based loop traversal
        while (record_trav_ptr < len_prices):
            while ((record_trav_ptr < len_prices) and (prices[record_trav_ptr] >= prices[(record_trav_ptr - 1)])):
                record_max_profit += (prices[record_trav_ptr] - prices[(record_trav_ptr - 1)]) #Keep updating/accumulating

                record_trav_ptr += 1 #Keep updating/traversing

            res_max_profit += record_max_profit #Keep updating/accumulating

            ##### Check if the current profit needs to be reset or not #####
            if (record_max_profit):
                record_max_profit &= 0 #Update/Reset
            else:
                pass

            record_trav_ptr += 1 #Keep updating/traversing

        return res_max_profit
