class Solution {
public:
    void solve(vector<vector<char>> & board) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<char>> ref. (board vector) //
        // Return type:                                 //
        //   - void (no return)                         //
        //==============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = board.size(), len_cols = (board[0]).size();

        /*Recursion-based DFS loop traversal*/
        ///// Step 1: Looped-traversal for the edge boundaries (i.e. rows, columns) /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if ((board[rows_idx])[0] == 'O') { dfsTraversal(board, len_rows, len_cols, rows_idx, 0); } //Recursion function call (i.e. left-sider)
            else { ; }

            if ((board[rows_idx])[(len_cols - 1)] == 'O') { dfsTraversal(board, len_rows, len_cols, rows_idx, (len_cols - 1)); } //Recursion function call (i.e. right-sider)
            else { ; }

        } //Rows

        for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if ((board[0])[cols_idx] == 'O') { dfsTraversal(board, len_rows, len_cols, 0, cols_idx); } //Recursion function call (i.e. up-sider)
            else { ; }

            if ((board[(len_rows - 1)])[cols_idx] == 'O') { dfsTraversal(board, len_rows, len_cols, (len_rows - 1), cols_idx); } //Recursion function call (i.e. down-sider)
            else { ; }

        } //Columns

        ///// Step 2: Post-process, Final completions /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if ((board[rows_idx])[cols_idx] == 'O') { (board[rows_idx])[cols_idx] = 'X'; } //Keep updating, overwriting

                else if ((board[rows_idx])[cols_idx] == 'F') { (board[rows_idx])[cols_idx] = 'O'; } //Keep updating, overwriting
                else { ; }

            } //Columns

        } //Rows
    }


    void dfsTraversal(vector<vector<char>> & board, const int & len_rows, const int & len_cols, int rows_idx, int cols_idx)
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<char>> ref. (board vector) //
        //   - const int ref. (length of rows)          //
        //   - const int ref. (length of columns)       //
        //   - int (rows index)                         //
        //   - int (columns index)                      //
        // Return type:                                 //
        //   - void (no return)                         //
        //==============================================//
        if (((rows_idx < 0) || (rows_idx >= len_rows)) || ((cols_idx < 0) || (cols_idx >= len_cols))) { return; } //Issue, Boundary-case handling

        if ((board[rows_idx])[cols_idx] != 'O') { return; } //Issue, Boundary-case handling

        (board[rows_idx])[cols_idx] = 'F'; //Update, Overwrite

        dfsTraversal(board, len_rows, len_cols, rows_idx, (cols_idx - 1)); //Recursion function call (i.e. left)
        dfsTraversal(board, len_rows, len_cols, (rows_idx - 1), cols_idx); //Recursion function call (i.e. up)
        dfsTraversal(board, len_rows, len_cols, rows_idx, (cols_idx + 1)); //Recursion function call (i.e. right)
        dfsTraversal(board, len_rows, len_cols, (rows_idx + 1), cols_idx); //Recursion function call (i.e. down)
    }
};
