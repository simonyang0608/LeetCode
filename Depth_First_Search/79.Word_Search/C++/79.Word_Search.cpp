class Solution {
public:
    bool exist(vector<vector<char>> & board, string word) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<char>> ref. (board vector) //
        //   - string (word string)                     //
        // Return type:                                 //
        //   - bool (result flag)                       //
        //==============================================//

        /*Initialize*/
        ///// Length of rows, columns ///// 
        int len_rows = board.size(), len_cols = (board[0]).size();

        ///// Length of word string /////
        int len_word = word.size();


        /*Recursion-based DFS loop traversal*/
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current flag is true or not /////
                if (dfsTraversal(board, word, len_rows, len_cols, len_word, rows_idx, cols_idx, 0)) { return true; }

            } //Columns

        } //Rows

        return false;
    }


    bool dfsTraversal(vector<vector<char>> & board, const string & word, const int & len_rows, const int & len_cols, const int & len_word, int rows_idx, int cols_idx, int record_idx)
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<char>> ref. (board vector) //
        //   - const string ref. (word string)          //
        //   - const int ref. (length of rows)          //
        //   - const int ref. (length of columns)       //
        //   - const int ref. (length of word string)   //
        //   - int (rows index)                         //
        //   - int (columns index)                      //
        //   - int (record index)                       //
        // Return type:                                 //
        //   - bool (result flag)                       //
        //==============================================//
        if (((rows_idx < 0) || (rows_idx >= len_rows)) || ((cols_idx < 0) || (cols_idx >= len_cols))) { return false; } //Issue, Boundary-case handling

        if ((board[rows_idx])[cols_idx] != word[record_idx]) { return false; } //Issue, Boundary-case handling

        if (record_idx >= (len_word - 1)) { return true; } //Issue, Boundary-case handling

        char record_chr = (board[rows_idx])[cols_idx]; //Update, Overwrite

        (board[rows_idx])[cols_idx] = '*'; //Update, Overwrite

        bool res_flag = (dfsTraversal(board, word, len_rows, len_cols, len_word, rows_idx, (cols_idx - 1), (record_idx + 1)) | //Recursion function call (i.e. left)
                         dfsTraversal(board, word, len_rows, len_cols, len_word, (rows_idx - 1), cols_idx, (record_idx + 1)) | //Recursion function call (i.e. up)
                         dfsTraversal(board, word, len_rows, len_cols, len_word, rows_idx, (cols_idx + 1), (record_idx + 1)) | //Recursion function call (i.e. right)
                         dfsTraversal(board, word, len_rows, len_cols, len_word, (rows_idx + 1), cols_idx, (record_idx + 1))); //Recursion function call (i.e. down)

        (board[rows_idx])[cols_idx] = record_chr; //Update, Overwrite

        return res_flag;
    }
};
