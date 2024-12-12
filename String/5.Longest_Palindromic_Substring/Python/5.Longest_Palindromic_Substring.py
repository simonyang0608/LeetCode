class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        #=================================#
        # Manacher-based traversal method #
        #=================================#

        ############
        #Initialize
        ##### Length of s string #####
        len_s = len(s)

        ##### Record new-s string #####
        new_s = "@#"

        for s_idx in range(len_s):
            new_s += s[s_idx]
            new_s += "#"

        new_s += "*"

        len_new_s = len(new_s)

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp_arry = [0 for _ in range(len_new_s)]

        ##### Record center, right-boundary #####
        record_center, record_rbound = record_trav_ptr, record_trav_ptr

        ##### Result maximun index, radius #####
        res_max_idx, res_max_rds = (-1), 0


        #######################################################################
        #Manacher-based loop traversal with recorded dynamic-programming array
        while (record_trav_ptr < len_new_s):
            record_mirror = ((2 * record_center) - record_trav_ptr) #Record mirror

            ##### Check if the current indexed-pointer matched conditions or not #####
            if ((record_trav_ptr < record_rbound) and ((record_trav_ptr + record_dp_arry[record_mirror]) < record_rbound)):
                record_dp_arry[record_trav_ptr] = record_dp_arry[record_mirror] #Keep updating/overwriting
            
            elif ((record_trav_ptr < record_rbound) and ((record_trav_ptr + record_dp_arry[record_mirror]) > record_rbound)):
                record_diff = (record_rbound - record_trav_ptr) #Record difference

                record_dp_arry[record_trav_ptr] = record_diff #Keep updating/overwriting

                while (((((record_trav_ptr - record_dp_arry[record_trav_ptr]) - 1) >= 0) and (((record_trav_ptr + record_dp_arry[record_trav_ptr]) + 1) < len_new_s)) and (new_s[((record_trav_ptr - record_dp_arry[record_trav_ptr]) - 1)] == new_s[((record_trav_ptr + record_dp_arry[record_trav_ptr]) + 1)])):
                    record_dp_arry[record_trav_ptr] += 1 #Keep updating/accumulating

                record_center = record_trav_ptr #Keep updating/overwriting
                record_rbound = (record_trav_ptr + record_dp_arry[record_trav_ptr]) #Keep updating/overwriting

            else:
                while (((((record_trav_ptr - record_dp_arry[record_trav_ptr]) - 1) >= 0) and (((record_trav_ptr + record_dp_arry[record_trav_ptr]) + 1) < len_new_s)) and (new_s[((record_trav_ptr - record_dp_arry[record_trav_ptr]) - 1)] == new_s[((record_trav_ptr + record_dp_arry[record_trav_ptr]) + 1)])):
                    record_dp_arry[record_trav_ptr] += 1 #Keep updating/accumulating

                record_center = record_trav_ptr #Keep updating/overwriting
                record_rbound = (record_trav_ptr + record_dp_arry[record_trav_ptr]) #Keep updating/overwriting

            ##### Check if the current radius is larger or not #####
            if (record_dp_arry[record_trav_ptr] > res_max_rds):
                res_max_rds = record_dp_arry[record_trav_ptr] #Keep updating/overwriting

                res_max_idx = record_trav_ptr #Keep updating/overwriting
            else:
                pass

            record_trav_ptr += 1 #Keep updating/traversing

        return s[(((res_max_idx - record_dp_arry[res_max_idx]) - 1) // 2): ((((res_max_idx - record_dp_arry[res_max_idx]) - 1) // 2) + res_max_rds)]
