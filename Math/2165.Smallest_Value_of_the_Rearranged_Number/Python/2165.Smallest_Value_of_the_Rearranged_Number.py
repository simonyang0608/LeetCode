class Solution(object):
    def smallestNumber(self, num):
        """
        :type num: int
        :rtype: int
        """
        #===============================#
        # Sorted-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Check if the current value is positive or not #####
        if (num < 0):
            res_str = "" #Result string

            sorted_arry = sorted(str((num * (-1))), reverse = True) #Sorted array

            for record_chr in sorted_arry:
                res_str += record_chr #Keep updating/recording

            return ((-1) * int(res_str))

        ##### Sorted array #####
        sorted_arry = sorted(str(num))

        if (sorted_arry[(-1)] == '0'): #Issue/Boundary-case handling
            return 0

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result string #####
        res_str = ""


        #############################
        #Sorted-based loop traversal
        while (record_trav_ptr < len(sorted_arry)):

            ##### Check if the current indexed-char is zero or not #####
            if (sorted_arry[record_trav_ptr] == '0'):
                record_trav_ptr += 1 #Keep updating/traversing
            else:
                break

        res_str += sorted_arry[record_trav_ptr] #Keep updating/recording

        res_str += ''.join(sorted_arry[: record_trav_ptr]) #Keep updating/recording

        res_str += ''.join(sorted_arry[(record_trav_ptr + 1): ]) #Keep updating/recording

        return int(res_str)
