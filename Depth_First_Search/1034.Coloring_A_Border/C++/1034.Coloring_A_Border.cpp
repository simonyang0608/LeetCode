class Solution {
public:
    vector<vector<int>> colorBorder(vector<vector<int>> & grid, int row, int col, int color) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        //   - int (row index)                        //
        //   - int (column index)                     //
        //   - int (color value)                      //
        // Return type:                               //
        //   - vector<vector<int>> (result vector)    //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Adjacent value /////
        int adj_val = (grid[row])[col];

        ///// Record grid vector /////
        vector<vector<int>> record_grid(grid.begin(), grid.end());


        /*Recursion-based DFS loop traversal*/
        dfsTraversal(record_grid, len_rows, len_cols, row, col, adj_val); //Recursion function call

        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current edges boundary matched conditions or not /////
                if (((rows_idx == 0) || (rows_idx == (len_rows - 1))) || ((cols_idx == 0) || (cols_idx == (len_cols - 1))))
                {
                    ///// Check if the current indexed-value matched conditions or not /////
                    if ((record_grid[rows_idx])[cols_idx] == 1001) { (grid[rows_idx])[cols_idx] = color; } //Keep updating, overwriting
                    else { ; }
                }
                else
                {
                    ///// Check if the current indexed-value matched conditions or not /////
                    if ((record_grid[rows_idx])[cols_idx] == 1001)
                    {
                        ///// Check if the current boundary values matched conditions or not /////
                        if (((record_grid[rows_idx])[(cols_idx - 1)] != 1001) || ((record_grid[(rows_idx - 1)])[cols_idx] != 1001) || ((record_grid[rows_idx])[(cols_idx + 1)] != 1001) || ((record_grid[(rows_idx + 1)])[cols_idx] != 1001))
                        {
                            (grid[rows_idx])[cols_idx] = color; //Keep updating, overwriting

                            continue;
                        }
                    }
                    else { ; }
                }

            } //Columns

        } //Rows

        return grid;
    }


    void dfsTraversal(vector<vector<int>> & record_grid, int & len_rows, int & len_cols, int rows_idx, int cols_idx, int & adj_val)
    {
        //===================================================//
        // Input type:                                       //
        //   - vector<vector<int>> ref. (record grid vector) //
        //   - int ref. (length of rows)                     //
        //   - int ref. (length of columns)                  // 
        //   - int (row index)                               //
        //   - int (column index)                            //
        //   - int ref. (adjacent value)                     //
        // Return type:                                      //
        //   - void (no return)                              //
        //===================================================//
        if (((rows_idx < 0) || (rows_idx >= len_rows)) || ((cols_idx < 0) || (cols_idx >= len_cols))) { return; } //Issue, Boundary-case handling
        if ((record_grid[rows_idx])[cols_idx] != adj_val) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        (record_grid[rows_idx])[cols_idx] = 1001; //Update, Overwrite

        dfsTraversal(record_grid, len_rows, len_cols, rows_idx, (cols_idx - 1), adj_val); //Recursion function call (i.e. left)
        dfsTraversal(record_grid, len_rows, len_cols, (rows_idx - 1), cols_idx, adj_val); //Recursion function call (i.e. up)
        dfsTraversal(record_grid, len_rows, len_cols, rows_idx, (cols_idx + 1), adj_val); //Recursion function call (i.e. right)
        dfsTraversal(record_grid, len_rows, len_cols, (rows_idx + 1), cols_idx, adj_val); //Recursion function call (i.e. down)
    }
};
