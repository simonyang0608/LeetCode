class Solution(object):
    def solve(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(board), len(board[0])

        ####################################
        #Recursion-based DFS loop traversal
        ##### Step 1: Looped-traversal for the edge boundaries (i.e. rows, columns) #####
        for rows_idx in range(len_rows):

            ##### Check if the current indexed-char matched conditions or not #####
            if ((board[rows_idx])[0] == 'O'):
                self.dfsTraversal(board, len_rows, len_cols, rows_idx, 0) #Recursion function call (i.e. left-sider)
            else:
                pass

            if ((board[rows_idx])[(len_cols - 1)] == 'O'):
                self.dfsTraversal(board, len_rows, len_cols, rows_idx, (len_cols - 1)) #Recursion function call (i.e. right-sider)
            else:
                pass

        for cols_idx in range(len_cols):

            ##### Check if the current indexed-char matched conditions or not #####
            if ((board[0])[cols_idx] == 'O'):
                self.dfsTraversal(board, len_rows, len_cols, 0, cols_idx) #Recursion function call (i.e. up-sider)
            else:
                pass

            if ((board[(len_rows - 1)])[cols_idx] == 'O'):
                self.dfsTraversal(board, len_rows, len_cols, (len_rows - 1), cols_idx) #Recursion function call (i.e. down-sider)
            else:
                pass

        ##### Step 2: Post-process, Final completions #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-char matched conditions or not #####
                if ((board[rows_idx])[cols_idx] == 'O'):
                    (board[rows_idx])[cols_idx] = 'X' #Keep updating/overwriting
                
                elif ((board[rows_idx])[cols_idx] == 'F'):
                    (board[rows_idx])[cols_idx] = 'O' #Keep updating/overwriting
                else:
                    pass

        
    def dfsTraversal(self, board, len_rows, len_cols, rows_idx, cols_idx):
        """
        :type board: List[List[str]]
        :type len_rows: int
        :type len_cols: int
        :type rows_idx: int
        :type cols_idx: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (((rows_idx < 0) or (rows_idx >= len_rows)) or ((cols_idx < 0) or (cols_idx >= len_cols))): #Issue/Boundary-case handling
            return

        if ((board[rows_idx])[cols_idx] != 'O'):  #Issue/Boundary-case handling
            return

        (board[rows_idx])[cols_idx] = 'F' #Update/Overwrite

        self.dfsTraversal(board, len_rows, len_cols, rows_idx, (cols_idx - 1)) #Recursion function call (i.e. left)
        self.dfsTraversal(board, len_rows, len_cols, (rows_idx - 1), cols_idx) #Recursion function call (i.e. up)
        self.dfsTraversal(board, len_rows, len_cols, rows_idx, (cols_idx + 1)) #Recursion function call (i.e. right)
        self.dfsTraversal(board, len_rows, len_cols, (rows_idx + 1), cols_idx) #Recursion function call (i.e. down)
