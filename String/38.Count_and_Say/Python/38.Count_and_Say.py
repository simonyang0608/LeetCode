class Solution(object):
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        #===============================#
        # String-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Record string #####
        record_str = "1"

        ##### Result string #####
        res_str = record_str


        #############################
        #String-based loop traversal
        for n_idx in range(2, (n + 1)):

            ##### Check if the current string is empty or not #####
            if (res_str):
                res_str = "" #Keep updating/reset
            else:
                pass

            record_trav_ptr = 0 #Record traversal pointer

            len_record_str = len(record_str) #Length of record string 

            while (record_trav_ptr < len_record_str):
                record_cnter = 1 #Record summary counter

                while (((record_trav_ptr + 1) < len_record_str) and ((record_str[record_trav_ptr] == record_str[(record_trav_ptr + 1)]))):
                    record_cnter += 1 #Keep updating/accumulating

                    record_trav_ptr += 1 #Keep updating/traversing

                res_str += (str(record_cnter) + record_str[record_trav_ptr]) #Keep updating/recording

                record_trav_ptr += 1 #Keep updating/traversing

            record_str = res_str #Keep updating/overwriting

        return res_str
