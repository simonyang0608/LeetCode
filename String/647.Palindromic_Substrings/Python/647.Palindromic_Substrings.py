class Solution(object):
    def countSubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Result summary counter #####
        res_cnter = [len_s]


        ###################################
        #Two-pointers based loop traversal
        for s_idx in range((len_s - 1)):

            ##### Check if the previous index exceed boundary or not #####
            if ((s_idx - 1) >= 0):
                self.isPalindrome(len_s, s, (s_idx - 1), (s_idx + 1), res_cnter) #Function call (odd sub-string)
            else:
                pass

            self.isPalindrome(len_s, s, s_idx, (s_idx + 1), res_cnter) #Function call (even sub-string)

        return res_cnter[0]


    def isPalindrome(self, len_s, s, prev_idx, post_idx, res_cnter):
        """
        :type len_s: int
        :type s: str
        :type prev_idx: int
        :type post_idx: int
        :type res_cnter: List[int]
        :rtype: None, void
        """
        #=======================================#
        # Two-pointers based traversal function #
        #=======================================#

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = prev_idx, post_idx

        ####################
        #Whole process/flow
        while (((record_left_ptr >= 0) and (record_right_ptr < len_s)) and (s[record_left_ptr] == s[record_right_ptr])):
            res_cnter[0] += 1 #Keep updating/accumulating

            record_left_ptr -= 1 #Keep updating/traversing
            record_right_ptr += 1 #Keep updating/traversing
