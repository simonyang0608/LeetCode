class Solution {
public:
    int findMaxFish(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result maximun summary value)     //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Result maximun summary value /////
        int res_max_sum = 0; 


        /*Recursion-based DFS loop traversal*/
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value is 0 or not /////
                if (! (grid[rows_idx])[cols_idx]) { continue; }
                else
                {
                    int record_sum_val = 0; //Record summary value

                    dfsTraversal(grid, len_rows, len_cols, rows_idx, cols_idx, record_sum_val); //Recursion function call

                    res_max_sum = max(res_max_sum, record_sum_val); //Keep updating, overwriting
                }
            }
        }

        return res_max_sum;
    }


    void dfsTraversal(vector<vector<int>> & grid, const int & len_rows, const int & len_cols, int rows_idx, int cols_idx, int & record_sum_val)
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        //   - const int ref. (length of rows)        //
        //   - const int ref. (length of columns)     //
        //   - int (rows index)                       //
        //   - int (columns index)                    //
        //   - int (record summary value)             //
        // Return type:                               //
        //   - void (no return)                       //
        //============================================//
        if (((rows_idx < 0) || (rows_idx >= len_rows)) || ((cols_idx < 0) || (cols_idx >= len_cols))) { return; } //Issue, Boundary-case handling

        if (! (grid[rows_idx])[cols_idx]) { return; } //Issue, Boundary-case handling

        record_sum_val += (grid[rows_idx])[cols_idx]; (grid[rows_idx])[cols_idx] = 0; //Keep updating overwriting

        dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_sum_val); //Recursion function call (i.e. left)
        dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_sum_val); //Recursion function call (i.e. up)
        dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_sum_val); //Recursion function call (i.e. right)
        dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_sum_val); //Recursion function call (i.e. down)
    }
};
