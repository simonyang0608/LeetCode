class Solution(object):
    def change(self, amount, coins):
        """
        :type amount: int
        :type coins: List[int]
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of coins array #####
        len_coins = len(coins)

        ##### Total amounts #####
        amount += 1

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp_arry = [0 for _ in range(amount)]
        record_dp_arry[0] = 1


        ##########################################
        #Dynamic-programming based loop traversal
        for coins_idx in range(len_coins):
            record_coin = coins[coins_idx] #Record coin

            for amount_idx in range(record_coin, amount):

                ##### Check if the current combinations matched conditions or not #####
                if (record_dp_arry[(amount_idx - record_coin)]):
                    record_dp_arry[amount_idx] += record_dp_arry[(amount_idx - record_coin)] #Keep updating/accumulating
                else:
                    pass

        return record_dp_arry[(amount - 1)]
