class Solution {
public:
    int closedIsland(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result summary counter)           //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Recursion-based DFS loop traversal*/
        ///// Step 1: Looped-traversal for the edges boundary /////
        for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (! (grid[0])[cols_idx]) { dfsTraversal(grid, len_rows, len_cols, 0, cols_idx); } //Recursion function call
            else { ; }

            if (! (grid[(len_rows - 1)])[cols_idx]) { dfsTraversal(grid, len_rows, len_cols, (len_rows - 1), cols_idx); } //Recursion function call
            else { ; }

        } //Columns

        for (int rows_idx = 1; (rows_idx <= (len_rows - 2)); (rows_idx++)) //Rows
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (! (grid[rows_idx])[0]) { dfsTraversal(grid, len_rows, len_cols, rows_idx, 0); } //Recursion function call
            else { ; }

            if (! (grid[rows_idx])[(len_cols - 1)]) { dfsTraversal(grid, len_rows, len_cols, rows_idx, (len_cols - 1)); } //Recursion function call
            else { ; }

        } //Rows

        ///// Step 2: Looped-traversal for the inner area /////
        for (int rows_idx = 1; (rows_idx <= (len_rows - 2)); (rows_idx++)) //Rows
        {
            for (int cols_idx = 1; (cols_idx <= (len_cols - 2)); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if (! (grid[rows_idx])[cols_idx]) { (res_cnter++); dfsTraversal(grid, len_rows, len_cols, rows_idx, cols_idx); } //Recursion function call
                else { ; }

            } //Columns

        } //Rows

        return res_cnter;
    }


    void dfsTraversal(vector<vector<int>> & grid, int & len_rows, int & len_cols, int rows_idx, int cols_idx)
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        //   - int ref. (length of rows)              //
        //   - int ref. (length of columns)           //
        //   - int (index of rows)                    //
        //   - int (index of columns)                 //
        // Return type:                               //
        //   - void (no return)                       //
        //============================================//
        if (((rows_idx < 0) || (rows_idx >= len_rows)) || ((cols_idx < 0) || (cols_idx >= len_cols))) { return; } //Issue, Boundary-case handling
        if ((grid[rows_idx])[cols_idx]) { return; } //Issue, Boundary-case handling

        (grid[rows_idx])[cols_idx] = 2; //Update, Overwrite

        dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1)); //Recursion function call (i.e. left)
        dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx); //Recursion function call (i.e. up)
        dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1)); //Recursion function call (i.e. right)
        dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx); //Recursion function call (i.e. down)
    }
};
