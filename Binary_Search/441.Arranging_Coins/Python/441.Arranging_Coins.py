class Solution(object):
    def arrangeCoins(self, n):
        """
        :type n: int
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 1, n

        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current indexed-pointer matched conditions or not #####
            if (((record_mid_ptr * (record_mid_ptr + 1)) // 2) <= n):
                res_step = record_mid_ptr #Keep updating/overwriting

                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting
            else:
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return res_step
