class Solution(object):
    def numberOfEmployeesWhoMetTarget(self, hours, target):
        """
        :type hours: List[int]
        :type target: int
        :rtype: int
        """
        #=========================================#
        # One-pass compare based traversal method #
        #=========================================#

        ############
        #Initialize
        ##### length of hours array #####
        len_hours = len(hours)

        ##### Result summary counter #####
        res_cnter = 0


        #######################################
        #One-pass compare based loop traversal
        for hours_idx in range(len_hours):

            ##### Check if the current indexed-value matched conditions or not #####
            if (hours[hours_idx] >= target):
                res_cnter += 1 #Keep updating/accumulating
            else:
                pass

        return res_cnter
