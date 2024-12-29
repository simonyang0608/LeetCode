class Solution(object):
    def pacificAtlantic(self, heights):
        """
        :type heights: List[List[int]]
        :rtype: List[List[int]]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(heights), len(heights[0])

        ##### Record arrays (i.e. pacific, altlantic) #####
        record_pac_arry = [[0 for _ in range(len_cols)] for _ in range(len_rows)]
        record_alt_arry = [[0 for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Result array #####
        res_arry = []


        ########################################################
        #Recursion-based DFS loop traversal with recorded array
        ##### Step 1: Record indexed-cell with array #####
        for cols_idx in range(len_cols):
            self.dfsTraversal(heights, len_rows, len_cols, 0, cols_idx, (heights[0])[cols_idx], record_pac_arry) #Recursion function call (i.e. first row)
            self.dfsTraversal(heights, len_rows, len_cols, (len_rows - 1), cols_idx, (heights[(len_rows - 1)])[cols_idx], record_alt_arry) #Recursion function call (i.e. last row)

        for rows_idx in range(len_rows):
            self.dfsTraversal(heights, len_rows, len_cols, rows_idx, 0, (heights[rows_idx])[0], record_pac_arry) #Recursion function call (i.e. first column)
            self.dfsTraversal(heights, len_rows, len_cols, rows_idx, (len_cols - 1), (heights[rows_idx])[(len_cols - 1)], record_alt_arry)#Recursion function call (i.e. last column)

        ##### Step 2: Looped-traversal with recorded array #####
        for rows_idx in range(len_rows):
            for cols_idx in range(len_cols):

                ##### Check if the current cell is valid or not #####
                if ((record_pac_arry[rows_idx])[cols_idx] and (record_alt_arry[rows_idx])[cols_idx]):
                    res_arry.append([rows_idx, cols_idx]) #Keep updating/recording
                else:
                    pass

        return res_arry


    def dfsTraversal(self, heights, len_rows, len_cols, rows_idx, cols_idx, prev_val, record_arry):
        """
        :type heights: List[List[int]]
        :type len_rows: int
        :type len_cols: int
        :type rows_idx: int
        :type cols_idx: int
        :type prev_val: int
        :type record_arry: List[List[int]]
        :rtype: List[List[int]]
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (((rows_idx < 0) or (rows_idx >= len_rows)) or ((cols_idx < 0) or (cols_idx >= len_cols))): #Issue/Boundary-case handling
            return

        if (prev_val > (heights[rows_idx])[cols_idx]): #Issue/Boundary-case handling
            return

        if ((record_arry[rows_idx])[cols_idx]): #Issue/Boundary-case handling
            return

        (record_arry[rows_idx])[cols_idx] = 1 #Update/Overwrite

        self.dfsTraversal(heights, len_rows, len_cols, rows_idx, (cols_idx - 1), (heights[rows_idx])[cols_idx], record_arry) #Recursion function call (i.e. left)
        self.dfsTraversal(heights, len_rows, len_cols, (rows_idx - 1), cols_idx, (heights[rows_idx])[cols_idx], record_arry) #Recursion function call (i.e. up)
        self.dfsTraversal(heights, len_rows, len_cols, rows_idx, (cols_idx + 1), (heights[rows_idx])[cols_idx], record_arry) #Recursion function call (i.e. right)
        self.dfsTraversal(heights, len_rows, len_cols, (rows_idx + 1), cols_idx, (heights[rows_idx])[cols_idx], record_arry) #Recursion function call (i.e. down)
