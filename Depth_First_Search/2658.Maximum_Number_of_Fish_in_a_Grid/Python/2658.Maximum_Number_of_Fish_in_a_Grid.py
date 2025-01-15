class Solution(object):
    def findMaxFish(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Lenght of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Result maximun summary value #####
        res_max_sum = 0


        ####################################
        #Recursion-based DFS loop traversal
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-value is 0 or not #####
                if (not (grid[rows_idx])[cols_idx]):
                    continue
                else:
                    record_sum_val = [0] #Record summary value

                    self.dfsTraversal(grid, len_rows, len_cols, rows_idx, cols_idx, record_sum_val) #Recursion function call

                    res_max_sum = max(res_max_sum, record_sum_val[0]) #Keep updating/overwriting
        
        return res_max_sum


    def dfsTraversal(self, grid, len_rows, len_cols, rows_idx, cols_idx, record_sum_val):
        """
        :type grid: List[List[int]]
        :type len_rows: int
        :type len_cols: int
        :type rows_idx: int
        :type cols_idx: int
        :type record_sum_val: List[int]
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (((rows_idx < 0) or (rows_idx >= len_rows)) or ((cols_idx < 0) or (cols_idx >= len_cols))): #Issue/Boundary-case handling
            return

        if (not (grid[rows_idx])[cols_idx]): #Issue/Boundary-case handling
            return

        record_sum_val[0] += (grid[rows_idx])[cols_idx] #Keep updating/accumulating

        (grid[rows_idx])[cols_idx] = 0 #Keep updating/overwriting

        self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_sum_val) #Recursion function call (left)
        self.dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_sum_val) #Recursion function call (up)
        self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_sum_val) #Recursion function call (right)
        self.dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_sum_val) #Recursion function call (down)
