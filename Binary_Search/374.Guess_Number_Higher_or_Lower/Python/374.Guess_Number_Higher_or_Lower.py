# The guess API is already defined for you.
# @param num, your guess
# @return -1 if num is higher than the picked number
#          1 if num is lower than the picked number
#          otherwise return 0
# def guess(num):

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 1, n

        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            record_flag = guess(record_mid_ptr) #Record flag

            ##### Check if the current flag matched conditions or not #####
            if (not record_flag):
                return record_mid_ptr

            elif (record_flag > 0):
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/accumulating

            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/reducing

        return (-1)
