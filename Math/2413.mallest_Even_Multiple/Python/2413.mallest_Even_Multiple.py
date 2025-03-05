class Solution(object):
    def smallestEvenMultiple(self, n):
        """
        :type n: int
        :rtype: int
        """
        #=======================#
        # Math-GCD based method #
        #=======================#

        return ((n * 2) if ((n % 2)) else n)
