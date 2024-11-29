class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 1, num

        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current indexed-pointer matched conditions or not #####
            if ((record_mid_ptr ** 2) < num):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

            elif ((record_mid_ptr ** 2) > num):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

            else:
                return True

        return False
