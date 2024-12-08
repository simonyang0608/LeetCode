class Solution(object):
    def floodFill(self, image, sr, sc, color):
        """
        :type image: List[List[int]]
        :type sr: int
        :type sc: int
        :type color: int
        :rtype: List[List[int]]
        """
        #======================================#
        # Recursion-based DFS traversal method #
        #======================================#
        if ((image[sr])[sc] == color): #Issue/Boundary-case handling
            return image

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(image), len(image[0])

        ##### Adjacent value #####
        adj_val = deepcopy((image[sr])[sc])


        ####################################
        #Recursion-based DFS loop traversal
        self.dfsTraversal(image, adj_val, len_rows, len_cols, sr, sc, color) #Recursion function call (i.e. whole image)

        return image

        
    def dfsTraversal(self, image, adj_val, len_rows, len_cols, record_row_idx, record_col_idx, color):
        """
        :type image: List[List[int]]
        :type adj_val: int
        :type len_rows: int
        :type len_cols: int
        :type record_row_idx: int
        :type record_col_idx: int
        :type color: int
        :rtype: None, void
        """
        #========================================#
        # Recursion-based DFS traversal function #
        #========================================#
        if (((record_row_idx < 0) or (record_row_idx >= len_rows)) or ((record_col_idx < 0) or (record_col_idx >= len_cols))): #Issue/Boundary-case handling
            return

        if ((image[record_row_idx])[record_col_idx] != adj_val): #Issue/Boundary-case handling
            return


        #####################
        #Whole process/flow
        (image[record_row_idx])[record_col_idx] = color #Update/Overwrite

        self.dfsTraversal(image, adj_val, len_rows, len_cols, record_row_idx, (record_col_idx - 1), color) #Recursion function call (i.e. left)
        self.dfsTraversal(image, adj_val, len_rows, len_cols, (record_row_idx - 1), record_col_idx, color) #Recursion function call (i.e. up)
        self.dfsTraversal(image, adj_val, len_rows, len_cols, record_row_idx, (record_col_idx + 1), color) #Recursion function call (i.e. right)
        self.dfsTraversal(image, adj_val, len_rows, len_cols, (record_row_idx + 1), record_col_idx, color) #Recursion function call (i.e. down)
