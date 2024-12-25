class Solution(object):
    def colorBorder(self, grid, row, col, color):
        """
        :type grid: List[List[int]]
        :type row: int
        :type col: int
        :type color: int
        :rtype: List[List[int]]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Adjacent value #####
        adj_val = (grid[row])[col]

        ##### Record grid array #####
        record_grid = deepcopy(grid)


        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(record_grid, len_rows, len_cols, row, col, adj_val) #Recursion function call

        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current edge boundary matched conditions or not #####
                if (((not rows_idx) or (rows_idx == (len_rows - 1))) or ((not cols_idx) or (cols_idx == (len_cols - 1)))):

                    ##### Check if the current indexed-value matched conditions or not #####
                    if ((record_grid[rows_idx])[cols_idx] == 1001):
                        (grid[rows_idx])[cols_idx] = color #Keep updating/overwriting
                    else:
                        pass

                else:
                    ##### Check if the current indexed-value matched conditions or not #####
                    if ((record_grid[rows_idx])[cols_idx] == 1001):

                        ##### Check if the current boundary value matched conditions or not #####
                        if (((record_grid[rows_idx])[(cols_idx - 1)] != 1001) or ((record_grid[(rows_idx - 1)])[cols_idx] != 1001) or ((record_grid[rows_idx])[(cols_idx + 1)] != 1001) or ((record_grid[(rows_idx + 1)])[cols_idx] != 1001)):
                            (grid[rows_idx])[cols_idx] = color #Keep updating/overwriting
                        else:
                            pass
                    else:
                        pass
        
        return grid


    def dfsTraversal(self, record_grid, len_rows, len_cols, rows_idx, cols_idx, adj_val):
        """
        :type record_grid: List[List[int]]
        :type len_rows: int
        :type len_cols: int
        :type rows_idx: int
        :type cols_idx: int
        :type adj_val: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (((rows_idx < 0) or (rows_idx >= len_rows)) or ((cols_idx < 0) or (cols_idx >= len_cols))): #Issue/Boundary-case handling
            return

        if ((record_grid[rows_idx])[cols_idx] != adj_val): #Issue/Boundary-case handling
            return


        ####################
        #Whole process/flow
        (record_grid[rows_idx])[cols_idx] = 1001 #Keep updating/overwriting

        self.dfsTraversal(record_grid, len_rows, len_cols, rows_idx, (cols_idx - 1), adj_val) #Recursion function call (i.e. left)
        self.dfsTraversal(record_grid, len_rows, len_cols, (rows_idx - 1), cols_idx, adj_val) #Recursion function call (i.e. up)
        self.dfsTraversal(record_grid, len_rows, len_cols, rows_idx, (cols_idx + 1), adj_val) #Recursion function call (i.e. right)
        self.dfsTraversal(record_grid, len_rows, len_cols, (rows_idx + 1), cols_idx, adj_val) #Recursion function call (i.e. down)
