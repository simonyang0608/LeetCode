class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Result two-pointers (i.e. left, right) #####
        res_left_ptr, res_right_ptr = [0], [0]


        ###################################
        #Two-pointers based loop traversal
        for s_idx in range(len_s):
            fst_max_str = self.mid2edge(len_s, s, s_idx, s_idx, res_left_ptr, res_right_ptr) #First sub-string
            scnd_max_str = self.mid2edge(len_s, s, s_idx, (s_idx + 1), res_left_ptr, res_right_ptr) #Second sub-string

        return s[res_left_ptr[0]: (res_right_ptr[0] + 1)]


    def mid2edge(self, len_s, s, record_left_ptr, record_right_ptr, res_left_ptr, res_right_ptr):
        """
        :type len_s: int
        :type s: str
        :type record_left_ptr: int
        :type record_right_ptr: int
        :type res_left_ptr: List[int]
        :type res_right_ptr: List[int]
        :rtype: None, void
        """
        #=======================================#
        # Two-pointers based traversal function #
        #=======================================#

        ####################
        #Whole process/flow
        while (((record_left_ptr >= 0) and (record_right_ptr < len_s)) and (s[record_left_ptr] == s[record_right_ptr])):
            if ((record_right_ptr - record_left_ptr) > (res_right_ptr[0] - res_left_ptr[0])):
                res_left_ptr[0] = record_left_ptr
                res_right_ptr[0] = record_right_ptr
            else:
                pass

            record_left_ptr -= 1 #Keep updating/traversing
            record_right_ptr += 1 #Keep updating/traversing
