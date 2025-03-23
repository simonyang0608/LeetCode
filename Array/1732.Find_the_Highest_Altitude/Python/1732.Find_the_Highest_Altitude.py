class Solution(object):
    def largestAltitude(self, gain):
        """
        :type gain: List[int]
        :rtype: int
        """
        #=======================================#
        # Prefix-summary based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of gain array #####
        len_gain = len(gain)

        ##### Record array #####
        record_arry = [0 for _ in range((len_gain + 1))]

        ##### Result maximun value #####
        res_max_val = 0


        #########################################################
        #Prefix-summary based loop traversal with recorded array
        for record_idx in range(1, (len_gain + 1)):
            record_arry[record_idx] = (record_arry[(record_idx - 1)] + gain[(record_idx - 1)]) #Keep updating/overwriting

            res_max_val = max(res_max_val, record_arry[record_idx]) #Keep updating/overwriting

        return res_max_val
