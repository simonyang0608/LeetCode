class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result maximun area)              //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record area /////
        int record_area = 0;

        ///// Result maximun area /////
        int res_max_area = 0;


        /*Recursion-based DFS loop traversal*/
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((grid[rows_idx])[cols_idx] == 1)
                {
                    dfsTraversal(grid, len_rows, len_cols, rows_idx, cols_idx, record_area); //Recursion function call

                    res_max_area = max(res_max_area, record_area); //Keep updating, overwriting

                    record_area &= 0; //Keep updating, reset
                }
                else { ; }

            } //Columns

        } //Rows

        return res_max_area;
    }


    void dfsTraversal(vector<vector<int>> & grid, int & len_rows, int & len_cols, int rows_idx, int cols_idx, int & record_area)
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        //   - int ref. (length of rows)              //
        //   - int ref. (length of columns)           //
        //   - int (index of rows)                    //
        //   - int (index of columns)                 //
        //   - int ref. (record area)                 //             
        // Return type:                               //
        //   - void (no return)                       //
        //============================================//
        if (((rows_idx < 0) || (rows_idx >= len_rows)) || ((cols_idx < 0) || (cols_idx >= len_cols))) { return; } //Issue, Boundary-case handling
        if ((grid[rows_idx])[cols_idx] != 1) { return; } //Issue, Boundary-case handling
 
        (record_area++); //Update, Accumulate

        (grid[rows_idx])[cols_idx] = (-1); //Update, Overwrite

        dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_area); //Recursion function call (i.e. left)
        dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_area); //Recursion function call (i.e. up)
        dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_area); //Recursion function call (i.e. right)
        dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_area); //Recursion function call (i.e. down)
    }
};
