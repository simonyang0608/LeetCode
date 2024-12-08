class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>> & image, int sr, int sc, int color) 
    {
        //===============================================//
        // Input type:                                   //
        //   - vector<vector<int>> ref. (image vector)   //
        //   - int (sr start row)                        //
        //   - int (sc start column)                     //
        //   - int (target color)                        //
        // Return type:                                  //
        //   - vector<vector<int>> (result image vector) //
        //===============================================//
        if ((image[sr])[sc] == color) { return image; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = image.size(), len_cols = (image[0]).size();

        ///// Adjacent value /////
        int adj_val = (image[sr])[sc];


        /*Recursion-based DFS loop traversal*/
        dfsTraversal(image, adj_val, len_rows, len_cols, sr, sc, color); //Recursion function call (i.e. whole image)

        return image;
    }


    void dfsTraversal(vector<vector<int>> & image, int & adj_val, int & len_rows, int & len_cols, int record_row_idx, int record_col_idx, int & color)
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (image vector) //
        //   - int ref. (adjacent value)               //
        //   - int ref. (length of rows)               //
        //   - int ref. (length of columns)            //
        //   - int (record row index)                  //
        //   - int (record column index)               //
        //   - int ref. (target color)                 //
        // Return type:                                //
        //   - void (no return)                        //
        //=============================================//
        if (((record_row_idx < 0) || (record_row_idx >= len_rows)) || ((record_col_idx < 0) || (record_col_idx >= len_cols))) { return; } //Issue, boundary-case handling

        if ((image[record_row_idx])[record_col_idx] != adj_val) { return; } //Issue, boundary-case handling


        /*Whole prcoess, flow*/
        (image[record_row_idx])[record_col_idx] = color; //Update, Overwrite

        dfsTraversal(image, adj_val, len_rows, len_cols, record_row_idx, (record_col_idx - 1), color); //Recursion function call (i.e. left)
        dfsTraversal(image, adj_val, len_rows, len_cols, (record_row_idx - 1), record_col_idx, color); //Recursion function call (i.e. up)
        dfsTraversal(image, adj_val, len_rows, len_cols, record_row_idx, (record_col_idx + 1), color); //Recursion function call (i.e. right)
        dfsTraversal(image, adj_val, len_rows, len_cols, (record_row_idx + 1), record_col_idx, color); //Recursion function call (i.e. down)
    }
};
