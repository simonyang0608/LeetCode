class Solution(object):
    def passThePillow(self, n, time):
        """
        :type n: int
        :type time: int
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Record times, remainings #####
        record_times, record_remains = (time // (n - 1)), (time % (n - 1))

        #############################################################
        #Greedy-based loop traversal with recorded times, remainings
        ##### Check if the current times is odd or even #####
        if (not (record_times % 2)):
            return (1 + record_remains)

        return (n - record_remains)
