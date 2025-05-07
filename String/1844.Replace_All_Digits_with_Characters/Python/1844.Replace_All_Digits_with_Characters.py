class Solution(object):
    def replaceDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        #========================================#
        # One-pass record based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Result string #####
        res_str = ""


        ######################################
        #One-pass record based loop traversal
        for s_idx in range(0, len_s, 2):
            res_str += s[s_idx] #Keep updating/recording

            ##### Check if the next index exceed boundary or not #####
            if ((s_idx + 1) >= len_s):
                continue

            res_str += chr(((ord(s[s_idx]) - 97) + int(s[(s_idx + 1)]) + 97)) #Keep updating/recording

        return res_str
