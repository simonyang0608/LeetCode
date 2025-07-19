class Solution(object):
    def maximumSum(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        #======================================================#
        # Dynamic-programming (i.e. DP) based traversal method #
        #======================================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record dynamic-programming arrays #####
        record_dp_left, record_dp_right = [0 for _ in range(len_arr)], [0 for _ in range(len_arr)]

        ##### Result maximun summary value #####
        res_max_val = arr[0]


        ###############################################################
        #Dynamic-programming based loop traversal with recorded arrays
        record_dp_left[0], record_dp_right[(-1)] = arr[0], arr[(-1)] #Update/Overwrite

        ##### Step 1: Looped-traversal for the left-half part/indices #####
        for record_idx in range(1, len_arr):
            record_dp_left[record_idx] = max(arr[record_idx], (record_dp_left[(record_idx - 1)] + arr[record_idx])) #Keep updating/overwriting

            res_max_val = max(res_max_val, record_dp_left[record_idx]) #Keep updating/overwriting

        ##### Step 2: Looped-traversal for the right-half part/indices #####
        for record_idx in range((len_arr - 2), (-1), (-1)):
            record_dp_right[record_idx] = max(arr[record_idx], (record_dp_right[(record_idx + 1)] + arr[record_idx])) #Keep updating/overwriting

        ##### Step 3: Post-process/Final completions #####
        for record_idx in range(1, (len_arr - 1)):
            res_max_val = max(res_max_val, (record_dp_left[(record_idx - 1)] + record_dp_right[(record_idx + 1)])) #Keep updating/overwriting

        return res_max_val
