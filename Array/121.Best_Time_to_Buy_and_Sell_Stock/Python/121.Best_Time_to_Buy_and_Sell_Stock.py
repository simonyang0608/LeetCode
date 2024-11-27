class Solution(object):
    def maxProfit(self, prices):
        """
        :type prices: List[int]
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of prices array #####
        len_prices = len(prices)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 1

        ##### Result maximun profit #####
        res_max_profit = 0


        ###################################
        #Two-pointers based loop traversal
        while (record_right_ptr < len_prices):
            curr_left_val = prices[record_left_ptr] #Current left-part value

            while ((record_right_ptr < len_prices) and (prices[record_right_ptr] >= curr_left_val)):

                ##### Check if the current difference/window matched conditions or not #####
                if ((prices[record_right_ptr] - curr_left_val) > res_max_profit):
                    res_max_profit = (prices[record_right_ptr] - curr_left_val) #Keep updating/overwriting
                else:
                    pass

                record_right_ptr += 1 #Keep updating/traversing

            record_left_ptr = record_right_ptr #Keep updating/overwriting

            record_right_ptr += 1 #Keep updating/traversing

        return  res_max_profit
