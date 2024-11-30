class Solution(object):
    def containsCycle(self, grid):
        """
        :type grid: List[List[str]]
        :rtype: bool
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record dictionary/hashmap #####
        record_dict = {}


        ####################################
        #Recursion-based DFS loop traversal
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current indexed-char matched conditions or not #####
                if ((grid[rows_idx])[cols_idx] != "0"):
                    if (self.dfsTraversal(grid, len_rows, len_cols, rows_idx, cols_idx, (grid[rows_idx])[cols_idx], (-1), record_dict)): #Recursion function call
                        return True
                    else:
                        pass

                    record_dict.clear() #Update/Reset

                else:
                    pass

        return False


    def dfsTraversal(self, grid, len_rows, len_cols, rows_idx, cols_idx, record_char, record_dirc, record_dict):
        """
        :type grid: List[List[str]]
        :type len_rows: int
        :type len_cols: int
        :type rows_idx: int
        :type cols_idx: int
        :type record_char: char
        :type record_dirc: int
        :type record_dict: dict
        :rtype: bool
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (((rows_idx < 0) or (rows_idx >= len_rows)) or ((cols_idx < 0) or (cols_idx >= len_cols))): #Issue/Boundary-case handling
            return False

        if ((rows_idx, cols_idx) in record_dict): #Issue/Boundary-case handling
            return True

        if ((grid[rows_idx])[cols_idx] != record_char): #Issue/Boundary-case handling
            return False


        ###################
        #Whole process/flow
        record_dict[(rows_idx, cols_idx)] = True #Update/Record

        (grid[rows_idx])[cols_idx] = "0" #Update/Overwrite

        ##### Check which previous direction is #####
        if (record_dirc == (-1)): #Original
            return (self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_char, 0, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_char, 1, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_char, 2, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_char, 3, record_dict)) #Recursion function call

        elif (record_dirc == 0): #Left
            return (self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_char, 0, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_char, 1, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_char, 3, record_dict)) #Recursion function call

        elif (record_dirc == 1): #Up
            return (self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_char, 0, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_char, 1, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_char, 2, record_dict)) #Recursion function call

        elif (record_dirc == 2): #Right
            return (self.dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_char, 1, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_char, 2, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_char, 3, record_dict)) #Recursion function call

        elif (record_dirc == 3): #Down
            return (self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_char, 0, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_char, 2, record_dict) | self.dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_char, 3, record_dict)) #Recursion function call
