class Solution(object):
    def getMaximumConsecutive(self, coins):
        """
        :type coins: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of coins array #####
        len_coins = len(coins)

        ##### Record summary counter #####
        record_cnter = 1


        ####################################################
        #Greedy-based loop traversal with sorted-operations
        coins.sort() #Sorted-operations

        for coins_idx in range(len_coins):

            ##### Check if the current indexed-value matched conditions or not #####
            if (coins[coins_idx] <= record_cnter):
                record_cnter += coins[coins_idx] #Keep updating/accumulating
            else:
                return record_cnter

        return record_cnter
