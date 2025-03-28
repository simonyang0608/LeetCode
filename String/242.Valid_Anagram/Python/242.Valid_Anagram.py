class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        #========================================#
        # Two-pass record based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of strings (i.e. s, t) #####
        len_s, len_ts = len(s), len(t)

        ##### Record arrays (i.e. s, t) #####
        record_arry_s, record_arry_ts = [0 for _ in range(26)], [0 for _ in range(26)]


        ######################################
        #Two-pass record based loop traversal
        for s_idx in range(len_s):
            record_arry_s[(ord(s[s_idx]) - 97)] += 1 #Keep updating/recording

        for t_idx in range(len_ts):
            record_arry_ts[(ord(t[t_idx]) - 97)] += 1 #Keep updating/recording

        return (True if (record_arry_s == record_arry_ts) else False)
