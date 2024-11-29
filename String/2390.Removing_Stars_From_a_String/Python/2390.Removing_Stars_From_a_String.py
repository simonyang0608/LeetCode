class Solution(object):
    def removeStars(self, s):
        """
        :type s: str
        :rtype: str
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record stack array #####
        record_stack = []


        ############################
        #Stack-based loop traversal
        for s_idx in range(len_s):

            ##### Check if the current indexed-char matched conditions or not #####
            if (s[s_idx] == "*"):
                record_stack.pop((-1)) #Keep updating/popped

                continue

            record_stack.append(s[s_idx]) #Keep udating/recording

        return ''.join(record_stack)
