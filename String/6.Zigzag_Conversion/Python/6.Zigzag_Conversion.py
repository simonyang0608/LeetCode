class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        #===========================#
        # One-pass traversal method #
        #===========================#
        if (numRows == 1): #Issue/Boundary-case handling
            return s
        
        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record index (i.e. rows) #####
        record_rows_idx = 0

        ##### Result string #####
        res_str = ""


        #########################
        #One-pass loop traversal
        while ((record_rows_idx < len_s) and (record_rows_idx < numRows)):
            record_trav_ptr = record_rows_idx #Record traversal pointer #####

            while (record_trav_ptr < len_s):
                res_str += s[record_trav_ptr] #Keep updating/recording

                record_trav_ptr += ((numRows - record_rows_idx) - 1) #Keep updating/traversing

                ##### Check if the current indexed-rows matched conditions or not #####
                if (not record_rows_idx):
                    record_trav_ptr += ((numRows - record_rows_idx) - 1) #Keep updating/traversing

                elif (record_rows_idx == (numRows - 1)):
                    record_trav_ptr += (record_rows_idx * 2) #Keep updating/traversing

                else:
                    record_trav_ptr += ((numRows - record_rows_idx) - 1) #Keep updating/traversing

                    ##### Check if the current indexed-pointer exceed boundary or not #####
                    if (record_trav_ptr >= len_s):
                        break

                    res_str += s[record_trav_ptr] #Keep updating/recording

                    record_trav_ptr += (2 * record_rows_idx) #Keep updating/traversing

            record_rows_idx += 1 #Keep updating/traversing

        return res_str
