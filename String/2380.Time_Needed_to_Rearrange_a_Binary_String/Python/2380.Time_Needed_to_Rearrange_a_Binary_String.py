class Solution(object):
    def secondsToRemoveOccurrences(self, s):
        """
        :type s: str
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of s array #####
        len_s = len(s)

        ##### Record traversal index #####
        record_trav_idx = 0

        ##### Result operations #####
        res_oprs = 0


        #############################
        #Greedy-based loop traversal
        for s_idx in range(len_s):

            ##### Check if the current indexed-char matched conditions or not #####
            if (s[s_idx] == '0'):
                continue

            else:
                ##### Check if the current operations matched conditions or not #####
                if (not res_oprs):
                    res_oprs = (s_idx - record_trav_idx) #Keep updating/overwriting

                else:
                    if (res_oprs >= (s_idx - record_trav_idx)):
                        res_oprs += 1 #Keep updating/accumulating
                    else:
                        res_oprs = (s_idx - record_trav_idx) #Keep updating/overwriting

            record_trav_idx += 1 #Keep updating/accumulating

        return res_oprs
