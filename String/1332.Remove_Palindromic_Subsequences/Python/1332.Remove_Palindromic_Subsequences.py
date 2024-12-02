class Solution(object):
    def removePalindromeSub(self, s):
        """
        :type s: str
        :rtype: int
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len(s) - 1)

        ###################################
        #Two-pointers based loop traversal
        while (record_left_ptr <= record_right_ptr):

            ##### Check if the current indexed-char matched conditions or not #####
            if (s[record_left_ptr] != s[record_right_ptr]):
                return 2

            record_left_ptr += 1 #Keep updating/traversing
            record_right_ptr -= 1 #Keep updating/traversing

        return 1
