class Solution(object):
    def sumSubarrayMins(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record stack #####
        record_stack = []

        ##### Record module #####
        record_module = ((10 ** 9) + 7)

        ##### Result summary value #####
        res_sum_val = 0


        ############################
        #Stack-based loop traversal
        arr.append(0) #Update/Record

        for arr_idx in range((len_arr + 1)):
            while (record_stack and (arr[arr_idx] < arr[record_stack[(-1)]])):
                record_idx = record_stack.pop() #Record index

                prev_idx = (record_stack[(-1)] if (record_stack) else (-1)) #Previous index

                res_sum_val += (arr[record_idx] * (arr_idx - record_idx) * (record_idx - prev_idx)) #Keep updating/accumulating

                res_sum_val %= record_module #Keep updating/moduling

            record_stack.append(arr_idx) #Keep updating/recording

        return res_sum_val
