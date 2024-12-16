class Solution {
public:
    int numIslands(vector<vector<char>> & grid) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<char>> ref. (grid vector) //
        // Return type:                                //
        //   - int (result summary counter)            //
        //=============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Recursion-based DFS loop traversal*/
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if ((grid[rows_idx])[cols_idx] == '1')
                {
                    (res_cnter++); //Keep updating, accumulating

                    dfsTraversal(grid, len_rows, len_cols, rows_idx, cols_idx); //Recursion function call
                }
                else { ; }

            } //Columns

        } //Rows

        return res_cnter;
    }


    void dfsTraversal(vector<vector<char>> & grid, int & len_rows, int & len_cols, int rows_idx, int cols_idx)
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<char>> ref. (grid vector) //
        //   - int ref. (length of rows)               //
        //   - int ref. (length of columns)            //
        //   - int (index of rows)                     //
        //   - int (index of columns)                  //
        // Return type:                                //
        //   - void (no return)                        //
        //=============================================//
        if (((rows_idx < 0) || (rows_idx >= len_rows)) || ((cols_idx < 0) || (cols_idx >= len_cols))) { return; } //Issue, Boundary-case handling

        if ((grid[rows_idx])[cols_idx] != '1') { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        ((grid[rows_idx])[cols_idx] = 'X'); //Update, Overwrite

        dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1)); //Recursion function call (i.e. left)
        dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx); //Recursion function call (i.e. up)
        dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1)); //Recursion function call (i.e. right)
        dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx); //Recursion function call (i.e. down)
    }
};
