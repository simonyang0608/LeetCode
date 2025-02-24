class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        #=================================#
        # Pointers-based traversal method #
        #=================================#

        ############
        #Initialize
        ##### Length of chars array #####
        len_chars = len(chars)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result array #####
        res_arry = []


        ###############################
        #Pointers-based loop traversal
        while (record_trav_ptr < len_chars):
            record_cnter = 1 #Record summary counter

            while (((record_trav_ptr + 1) < len_chars) and (chars[record_trav_ptr] == chars[(record_trav_ptr + 1)])):
                record_cnter += 1 #Keep updating/accumulating

                record_trav_ptr += 1 #Keep updating/traversing

            res_arry.append(chars[record_trav_ptr]) #Keep updating/recording

            ##### Check if the current summary counter is 1 or not #####
            if (record_cnter == 1):
                pass
            else:
                for record_chr in str(record_cnter):
                    res_arry.append(record_chr) #Keep updating/recording

            record_trav_ptr += 1 #Keep updating/traversing

        chars[:] = [] #Keep updating/reset

        chars += res_arry #Keep updating/overwriting

        return len(chars)
