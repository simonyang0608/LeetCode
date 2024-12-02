class Solution(object):
    def coinChange(self, coins, amount):
        """
        :type coins: List[int]
        :type amount: int
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#
        if (not amount): #Issue/Boundary-case handling
            return 0

        ############
        #Initialize
        ##### Length of coins array #####
        len_coins = len(coins)

        ##### Total amounts #####
        amount += 1

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp_arry = [10001 for _ in range(amount)]
        record_dp_arry[0] = 0


        #####################################################
        #Dynamic-programming (i.e. DP) based loop traversal
        for coins_idx in range(len_coins):
            record_coin = coins[coins_idx] #Record coin

            for amount_idx in range(record_coin, amount):

                ##### Check if the current indexed-value matched conditions or not #####
                if (record_dp_arry[(amount_idx - record_coin)] != 10001):
                    record_dp_arry[amount_idx] = min(record_dp_arry[amount_idx], record_dp_arry[(amount_idx - record_coin)] + 1) #Keep updating/overwriting
                else:
                    pass

        return ((-1) if (record_dp_arry[(amount - 1)] == 10001) else record_dp_arry[(amount - 1)])
