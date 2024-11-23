class Solution(object):
    def maxLength(self, arr):
        """
        :type arr: List[str]
        :rtype: int
        """
        #============================================#
        # Recursion-based backtrack traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        return self.backtrackTraversal(arr, len_arr, 0, "") #Recursion function call


    def backtrackTraversal(self, arr, len_arr, slice_idx, record_str):
        """
        :type arr: List[str]
        :type len_arr: int
        :type slice_idx: int
        :type record_str: str
        :rtype: int
        """
        #==============================================#
        # Recursion-based backtrack traversal function #
        #==============================================#
        if (slice_idx >= len_arr): #Issue/Boundary-case handling
            return len(record_str)

        ############
        #Initialize
        ##### Record flag #####
        record_flag = False

        ##### Record string set #####
        record_set = set(record_str)

        ##### Result maximun length #####
        res_max_length = len(record_str)


        ####################
        #Whole process/flow
        for record_idx in range(slice_idx, len_arr):
            curr_str = arr[record_idx] #Current string

            ##### Check if the current indexed-string matched conditions or not #####
            if (len(set(curr_str)) != len(curr_str)):
                continue

            for curr_char in curr_str:

                ##### Check if the current indexed-char matched conditions or not #####
                if (curr_char in record_set):
                    record_flag |= True #Update/Overwrite

                    break

            ##### Check if the current flag matched conditions or not #####
            if (not record_flag):
                record_max_length = self.backtrackTraversal(arr, len_arr, (record_idx + 1), (record_str + curr_str)) #Recursion function call

                ##### Check if the current length is larger or not #####
                if (record_max_length > res_max_length):
                    res_max_length = record_max_length #Keep updating/Overwriting

            ##### Check if the current flag needs to be reset or not #####
            if (record_flag):
                record_flag &= False #Update/Reset

        return res_max_length
