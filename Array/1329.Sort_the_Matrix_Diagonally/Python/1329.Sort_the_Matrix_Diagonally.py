class Solution(object):
    def diagonalSort(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: List[List[int]]
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_columns = len(mat), len(mat[0])

        ##### Record dictionary/hashmap #####
        record_dict = {}


        ##############################################################
        #Greedy-based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-value with dictionary/hashmap #####
        for rows_idx in range(len_rows):
            for columns_idx in range(len_columns):
                curr_diff = (rows_idx - columns_idx) #Current differences

                ##### Check if the current indexed-value existed or not #####
                if (curr_diff not in record_dict):
                    record_dict[curr_diff] = [(mat[rows_idx])[columns_idx]] #Keep updating/recording
                else:
                    (record_dict[curr_diff]).append((mat[rows_idx])[columns_idx]) #Keep updating/recording

        ##### Step 2: Sorted operations #####
        for sub_key in record_dict:
            (record_dict[sub_key]).sort(reverse = True) #Keep updating/overwriting

        ##### Step 3: Looped-traversal with recorded dictionary
        for rows_idx in range(len_rows):
            for columns_idx in range(len_columns):
                (mat[rows_idx])[columns_idx] = (record_dict[(rows_idx - columns_idx)]).pop((-1)) #Keep updating/overwriting

        return mat
