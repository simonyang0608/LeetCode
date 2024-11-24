class Solution(object):
    def reverseString(self, s):
        """
        :type s: List[str]
        :rtype: None Do not return anything, modify s in-place instead.
        """
        #======================================#
        # One-pass swap based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of s array #####
        len_s = len(s)
        trav_len_s = (len_s // 2)

        ####################################
        #One-pass swap based loop traversal
        for s_idx in range(trav_len_s):
            record_s = s[s_idx] #Record s string

            s[s_idx] = s[((len_s - 1) - s_idx)] #Keep updating/swap
            s[((len_s - 1) - s_idx)] = record_s #Keep updating/swap
