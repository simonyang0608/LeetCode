class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        #############
        #Initiialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record stack #####
        record_stack = []

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ############################
        #Stack-based loop traversal
        for s_idx in range(len_s):

            ##### Check if the current char matched conditions or not #####
            if (s[s_idx] == "("):
                record_stack.append(s_idx) #Keep updating/recording
            else:
                ##### Check if the current stack is empty or not #####
                if (not record_stack):
                    record_trav_ptr = (s_idx + 1) #Keep updating/overwriting
                else:
                    record_stack.pop() #Keep updating/popped

                    res_max_cnter = (max(res_max_cnter, ((s_idx - record_trav_ptr) + 1)) if (not record_stack) else (max(res_max_cnter, (s_idx - record_stack[(-1)])))) #Keep updating/overwriting

        return res_max_cnter
