class Solution(object):
    def peakIndexInMountainArray(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        #======================================#
        # Binary-search based traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of arr array #####
        arr.insert(0, 0)
        arr.append(0)

        len_arr = len(arr)

        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 1, (len_arr - 1)

        ##### Result maximun value #####
        res_max_val = (-1)


        ####################################
        #Binary-search based loop traversal
        while (record_left_ptr <= record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr) // 2) #Record middle pointer

            ##### Check if the current indexed-value matched conditions or not #####
            if (arr[record_mid_ptr] >= arr[(record_mid_ptr - 1)]):
                if (arr[record_mid_ptr] > res_max_val):
                    res_max_val = arr[record_mid_ptr] #Keep updating/overwriting

                    res_idx = record_mid_ptr #Keep updating/overwriting
                else:
                    pass

                record_left_ptr = (record_mid_ptr + 1) #Keep updating/overwriting

            else:
                if (arr[(record_mid_ptr - 1)] > res_max_val):
                    res_max_val = arr[(record_mid_ptr - 1)] #Keep updating/overwriting

                    res_idx = (record_mid_ptr - 1) #Keep updating/overwriting
                else:
                    pass

                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting

        return (res_idx - 1)
