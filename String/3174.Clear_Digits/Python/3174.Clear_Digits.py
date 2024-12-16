class Solution(object):
    def clearDigits(self, s):
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

        ##### Record stack #####
        record_stack = []


        ############################
        #Stack-based loop traversal
        for s_idx in range(len_s):

            ##### Check if the current indexed-char matched conditions or not #####
            if (not (s[s_idx]).isdigit()):
                record_stack.append(s[s_idx]) #Keep updating/recording
            else:
                record_stack.pop() #Keep updating/popped

        return ''.join(record_stack)
