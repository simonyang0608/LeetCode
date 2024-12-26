class Solution(object):
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of citations #####
        len_citations = len(citations)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len_citations - 1)

        ##### Result maximun value #####
        res_max_val = 0


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            res_max_val = max(res_max_val, min(citations[record_mid_ptr], (len_citations - record_mid_ptr))) #Keep updating/overwriting

            ##### Check if the current indexed-value matched conditions or not #####
            if ((citations[record_mid_ptr] > (len_citations - record_mid_ptr))):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

        return res_max_val
