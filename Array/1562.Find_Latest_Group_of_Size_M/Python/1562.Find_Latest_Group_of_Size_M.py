class Solution(object):
    def findLatestStep(self, arr, m):
        """
        :type arr: List[int]
        :type m: int
        :rtype: int
        """
        #=======================================#
        # Prefix-summary based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record arrays (i.e. length, counter) #####
        length_arry, cnter_arry = [0 for _ in range((len_arr + 2))], [0 for _ in range((len_arr + 1))]

        ##### Result maximun steps #####
        res_max_steps = (-1)


        ##########################################################
        #Prefix-summary based loop traversal with recorded arrays
        for arr_idx in range(len_arr):
            left, right = length_arry[(arr[arr_idx] - 1)], length_arry[(arr[arr_idx] + 1)] #Left, Right

            record_sum_val = (left + right + 1) #Record summary value

            length_arry[(arr[arr_idx] - left)] = length_arry[(arr[arr_idx] + right)] = record_sum_val #Keep updating/overwriting

            cnter_arry[left] -= 1 #Keep updating/reducing
            cnter_arry[right] -= 1 #Keep updating/reducing

            cnter_arry[record_sum_val] += 1 #Keep updating/accumulating

            ##### Check if the current summary counter matched conditions or not #####
            if (cnter_arry[m] > 0):
                res_max_steps = (arr_idx + 1) #Keep updating/overwriting
            else:
                pass

        return res_max_steps
