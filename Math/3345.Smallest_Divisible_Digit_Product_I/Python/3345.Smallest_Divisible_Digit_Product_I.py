class Solution(object):
    def smallestNumber(self, n, t):
        """
        :type n: int
        :type t: int
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        #############################
        #Greedy-based loop traversal
        while (n):

            ##### Check if the current product matched conditions or not #####
            if (not (self.digit2prod(n) % t)):
                return n

            n += 1 #Keep updating/accumulating

        return (-1)


    def digit2prod(self, n):
        """
        :type n: int
        :rtype: int
        """

        ############
        #Initialize
        ##### Record s string #####
        record_s = str(n)

        ##### Result product #####
        res_prod = 1


        ####################
        #Whole process/flow
        for s_idx in range(len(record_s)):
            res_prod *= int(record_s[s_idx]) #Keep updating/product

        return res_prod
