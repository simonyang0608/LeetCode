class Solution(object):
    def maxTurbulenceSize(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record char #####
        record_chr = 'n'

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record summary counter #####
        record_cnter = 1

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        #####################################
        #Sliding-window based loop traversal
        while (record_trav_ptr < len_arr):

            ##### Check if the current pointer exceed boundary or not #####
            if ((record_trav_ptr + 1) < len_arr):

                ##### Check if the current indexed-value matched conditions or not #####
                if (arr[record_trav_ptr] == arr[(record_trav_ptr + 1)]):

                    ##### Check if the current summary counter matched conditions or not #####
                    if (record_cnter != 1):
                        record_cnter = 1 #Keep updating/reset

                        record_chr = 'n' #Keep updating/overwriting
                    else:
                        pass

                elif (arr[record_trav_ptr] < arr[(record_trav_ptr + 1)]):

                    ##### Check if the current indexed-char matched conditions or not #####
                    if ((record_chr == 'n') or (record_chr == 'd')):
                        record_cnter += 1 #Keep updating/accumulating

                        record_chr = 'i' #Keep updating/overwriting
                    else:

                        ##### Check if the current summary counter matched conditions or not #####
                        if (record_cnter != 2):
                            record_cnter = 2 #Keep updating/reset
                        else:
                            pass
                else:
                    ##### Check if the current indexed-char matched conditions or not #####
                    if ((record_chr == 'n') or (record_chr == 'i')):
                        record_cnter += 1 #Keep updating/accumulating

                        record_chr = 'd' #Keep updating/overwriting
                    else:
                        ##### Check if the current summary counter matched conditions or not #####
                        if (record_cnter != 2):
                            record_cnter = 2 #Keep updating/reset
                        else:
                            pass
            else:
                pass

            res_max_cnter = max(res_max_cnter, record_cnter) #Keep updating/overwriting

            record_trav_ptr += 1 #Keep updating/traversing

        return res_max_cnter
