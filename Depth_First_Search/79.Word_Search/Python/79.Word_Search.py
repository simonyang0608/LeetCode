class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(board), len(board[0])

        ##### Length of word string #####
        len_word = len(word)


        ####################################
        #Recursion-based DFS loop traversal
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current flag is true or not #####
                if (self.dfsTraversal(board, len_rows, len_cols, len_word, word, rows_idx, cols_idx, 0)):
                    return True

        return False


    def dfsTraversal(self, board, len_rows, len_cols, len_word, word, rows_idx, cols_idx, record_idx):
        """
        :type board: List[List[str]]
        :type len_rows: int
        :type len_cols: int
        :type len_word: int
        :type word: str
        :type rows_idx: int
        :type cols_idx: int
        :type record_idx: int
        :rtype: bool
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (((rows_idx < 0) or (rows_idx >= len_rows)) or ((cols_idx < 0) or (cols_idx >= len_cols))): #Issue/Boundary-case handling
            return False

        if ((board[rows_idx])[cols_idx] != word[record_idx]): #Issue/Boundary-case handling
            return False

        if (record_idx >= (len_word - 1)): #Issue/Boundary-case handling
            return True

        record_char = (board[rows_idx])[cols_idx] #Update/Overwrite

        (board[rows_idx])[cols_idx] = '*' #Update/Overwrite

        res_flag = (self.dfsTraversal(board, len_rows, len_cols, len_word, word, rows_idx, (cols_idx - 1), (record_idx + 1)) or #Recursion function call (i.e. left)
                    self.dfsTraversal(board, len_rows, len_cols, len_word, word, (rows_idx - 1), cols_idx, (record_idx + 1)) or #Recursion function call (i.e. up)
                    self.dfsTraversal(board, len_rows, len_cols, len_word, word, rows_idx, (cols_idx + 1), (record_idx + 1)) or #Recursion function call (i.e. right)
                    self.dfsTraversal(board, len_rows, len_cols, len_word, word, (rows_idx + 1), cols_idx, (record_idx + 1))) #Recursion function call (i.e. down)

        (board[rows_idx])[cols_idx] = record_char #Update/Overwrite

        return res_flag
