class Solution(object):
    def minFlips(self, target):
        """
        :type target: str
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of target string #####
        len_target = len(target)

        ##### Record indexed-char #####
        record_char = '0'

        ##### Result minimun operations #####
        res_min_oprs = 0


        ###################################################
        #Greedy-based traversal with recorded indexed-char
        for target_idx in range(len_target):

            ##### Check if the current indexed-char matched conditions or not #####
            if (target[target_idx] != record_char):
                res_min_oprs += 1 #Keep updating/accumulating

                record_char = target[target_idx] #Keep updating/overwriting

            else:
                pass

        return res_min_oprs
