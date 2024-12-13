class Solution(object):
    def numSub(self, s):
        """
        :type s: str
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record summary counter #####
        record_cnter = 1

        ##### Result summary counter #####
        res_cnter = 0


        #####################################
        #Sliding-window based loop traversal
        while (record_trav_ptr < len_s):

            ##### Check if the current indexed-char matched conditions or not #####
            if (s[record_trav_ptr] == '1'):
                while (((record_trav_ptr + 1) < len_s) and (s[record_trav_ptr] == s[(record_trav_ptr + 1)])):
                    record_cnter += 1 #Keep updating/accumulating

                    record_trav_ptr += 1 #Keep updating/traversing

                res_cnter += (((record_cnter + 1) * record_cnter) // 2) #Keep updating/accumulating

                ##### Check if the current summary counter needs to be reset or not #####
                if (record_cnter > 1):
                    record_cnter = 1 #Update/Reset
                else:
                    pass

            else:
                pass

            record_trav_ptr += 1 #Keep updating/traversing

        return (res_cnter % ((10 ** 9) + 7))
