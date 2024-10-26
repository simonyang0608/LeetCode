# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
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
            record_middle_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if (not isBadVersion(record_middle_ptr)):
                record_left_ptr = (record_middle_ptr + 1) #Keep updating/overwriting
            else:
                if (record_middle_ptr == 1):
                    return record_middle_ptr

                if (isBadVersion((record_middle_ptr - 1))):
                    record_right_ptr = (record_middle_ptr - 1) #Keep updating/overwriting
                else:
                    return record_middle_ptr

        return (-1)
