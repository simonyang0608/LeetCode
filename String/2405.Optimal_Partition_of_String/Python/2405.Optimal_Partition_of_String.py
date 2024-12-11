class Solution(object):
    def partitionString(self, s):
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

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 0

        ##### Record array #####
        record_arry = [0 for _ in range(26)]

        ##### Result minimun summary counter #####
        res_min_cnter = 1


        #######################################################
        #Two-pointers based loop traversal with recorded array
        while (record_right_ptr < len_s):

            ##### Check if the current indexed-char existed or not #####
            if (record_arry[(ord(s[record_right_ptr]) - 97)] < 1):
                record_arry[(ord(s[record_right_ptr]) - 97)] = 1 #Keep updating/overwriting
            else:
                while (record_left_ptr < record_right_ptr):
                    record_arry[(ord(s[record_left_ptr]) - 97)] = 0 #Keep updating/overwriting

                    record_left_ptr += 1 #Keep updating/traversing

                record_arry[ord(s[record_left_ptr]) - 97] = 1 #Keep updating/overwriting

                res_min_cnter += 1 #Keep updating/accumulating

            record_right_ptr += 1 #Keep updating/traversing

        return res_min_cnter
