class Solution(object):
    def maxRunTime(self, n, batteries):
        """
        :type n: int
        :type batteries: List[int]
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of batteries array #####
        len_batteries = len(batteries)

        ##### Record summary value #####
        record_sum_val = sum(batteries)


        #############################
        #Greedy-based loop traversal
        batteries.sort(reverse = True) #Sorted operations

        for batteries_idx in range(len_batteries):

            ##### Check if the current indexed-value matched conditions or not #####
            if (batteries[batteries_idx] <= (record_sum_val // n)):
                break

            record_sum_val -= batteries[batteries_idx] #Keep updating/reducing

            n -= 1 #Keep updating/reducing

        return (record_sum_val // n)
