class Solution(object):
    def longestSubsequence(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        #====================================#
        # Bit-wise based manipulation method #
        #====================================#

        ############
        #Initialize
        ##### Reversed operations #####
        reversed_s = reversed(s)

        ##### Record summary values #####
        record_sum_val = 0

        ##### Result summary counter #####
        res_cnter = s.count("0")


        ##########################################################
        #Bit-wise based manipulation with recorded summary values
        for (s_idx, s_char) in enumerate(reversed_s):

            ##### Check if the current indexed-char matched conditions or not #####
            if (s_char == "1"):
                record_sum_val += (1 << s_idx) #Keep updating/accumulating

                ##### Check if the current summary values exceed boundary or not #####
                if (record_sum_val > k):
                    return res_cnter
                else:
                    res_cnter += 1 #Keep updating/accumualting
            else:
                pass

        return res_cnter
