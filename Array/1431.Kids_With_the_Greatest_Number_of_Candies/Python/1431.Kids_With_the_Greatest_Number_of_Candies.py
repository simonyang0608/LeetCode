class Solution(object):
    def kidsWithCandies(self, candies, extraCandies):
        """
        :type candies: List[int]
        :type extraCandies: int
        :rtype: List[bool]
        """
        #========================================#
        # One-pass update based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length, Maximun of candies array #####
        len_candies, max_candies = len(candies), max(candies)

        ##### Result array #####
        res_arry = [False for _ in range(len_candies)]


        ######################################
        #One-pass update based loop traversal
        for candies_idx in range(len_candies):

            ##### Check if the current summary value matched conditions or not #####
            if ((candies[candies_idx] + extraCandies) >= max_candies):
                res_arry[candies_idx] = True #Keep updating/overwriting
            else:
                pass

        return res_arry
