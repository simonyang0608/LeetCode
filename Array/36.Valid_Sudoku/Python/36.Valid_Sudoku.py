class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        #===========================================#
        # Dictionary/Hashmap-based traversal method #
        #===========================================#

        ############
        #Initialize
        ##### Length of edges #####
        len_edges = 9

        ##### Record dictionary/hashmap #####
        record_rows_dict, record_cols_dict, record_corners_dict = {}, {}, {}


        #########################################
        #Dictionary/Hashmap-based loop traversal
        ##### Step 1: Looped-traversal for the rows informations #####
        for rows_idx in range(len_edges):
            for cols_idx in range(len_edges):

                ##### Check if the current indexed-char matched conditions or not #####
                if ((board[rows_idx])[cols_idx] != '.'):

                    ##### Check if the current indexed-char existed or not #####
                    if ((board[rows_idx])[cols_idx] not in record_rows_dict):
                        record_rows_dict[(board[rows_idx])[cols_idx]] = True #Keep updating/recording
                    else:
                        return False
                else:
                    pass

            ##### Check if the current dictionary/hashmap needs to be reset or not #####
            if (record_rows_dict):
                record_rows_dict.clear() #Keep updating/reset
            else:
                pass

        ##### Step 2: Looped-traversal for the columns informations #####
        for cols_idx in range(len_edges):
            for rows_idx in range(len_edges):

                ##### Check if the current indexed-char matched conditions or not #####
                if ((board[rows_idx])[cols_idx] != '.'):

                    ##### Check if the current indexed-char existed or not #####
                    if ((board[rows_idx])[cols_idx] not in record_cols_dict):
                        record_cols_dict[(board[rows_idx])[cols_idx]] = True #Keep updating/recording
                    else:
                        return False
                else:
                    pass

            ##### Check if the current dictionary/hashmap needs to be reset or not #####
            if (record_cols_dict):
                record_cols_dict.clear() #Keep updating/reset
            else:
                pass

        ##### Step 3: Looped-traversal for the corners informations #####
        for rows_idx in range(0, len_edges, 3):
            for cols_idx in range(0, len_edges, 3):
                for sub_rows_idx in range(rows_idx, (rows_idx + 3)):
                    for sub_cols_idx in range(cols_idx, (cols_idx + 3)):

                        ##### Check if the current indexed-char matched conditions or not #####
                        if ((board[sub_rows_idx])[sub_cols_idx] != '.'):

                            ##### Check if the current indexed-char existed or not #####
                            if ((board[sub_rows_idx])[sub_cols_idx] not in record_corners_dict):
                                record_corners_dict[(board[sub_rows_idx])[sub_cols_idx]] = True #Keep updating/recording
                            else:
                                return False
                        else:
                            pass

                ##### Check if the current dictionary/hashmap needs to be reset or not #####
                if (record_corners_dict):
                    record_corners_dict.clear() #Keep updating/reset
                else:
                    pass

        return True
