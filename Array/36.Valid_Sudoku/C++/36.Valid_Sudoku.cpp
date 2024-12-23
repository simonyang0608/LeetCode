class Solution {
public:
    bool isValidSudoku(vector<vector<char>> & board) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<char>> ref. (board vector) //
        // Return type:                                 //
        //   - bool (result flag)                       //
        //==============================================//

        /*Initialize*/
        ///// Length of edges /////
        int len_edges = 9;

        ///// Record dictionary, hashmap (i.e. rows, columns, corners) /////
        map<int, bool> record_row_map, record_col_map, record_corner_map;


        /*Dictionary, Hashmap-based loop traversal*/
        ///// Step 1: Looped-traversal for the rows informations /////
        for (int rows_idx = 0; (rows_idx < len_edges); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_edges); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if ((board[rows_idx])[cols_idx] != '.')
                {
                    ///// Check if the current indexed-char existed or not /////
                    if (record_row_map.find((board[rows_idx])[cols_idx]) == record_row_map.end()) { record_row_map[(board[rows_idx])[cols_idx]] = true; } //Keep updating, recording
                    else { return false; }
                }
                else { ; }

            } //Columns

            ///// Check if the current dictionary, hasmap needs to be reset or not /////
            if (! record_row_map.empty()) { record_row_map.clear(); } //Update, Reset
            else { ; }

        } //Rows

        ///// Step 2: Looped-traversal for the columns informations /////
        for (int cols_idx = 0 ;(cols_idx < len_edges); (cols_idx++)) //Columns
        {
            for (int rows_idx = 0; (rows_idx < len_edges); (rows_idx++)) //Rows
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if ((board[rows_idx])[cols_idx] != '.')
                {
                    ///// Check if the current indexed-char existed or not /////
                    if (record_col_map.find((board[rows_idx])[cols_idx]) == record_col_map.end()) { record_col_map[(board[rows_idx])[cols_idx]] = true; } //Keep updating, recording
                    else { return false; }
                }
                else { ; }

            } //Rows

            ///// Check if the current dictionary, hasmap needs to be reset or not /////
            if (! record_col_map.empty()) { record_col_map.clear(); } //Update, Reset
            else { ; }

        } //Columns

        ///// Step 3: Looped-traversal for the corners informations /////
        for (int rows_idx = 0; (rows_idx < len_edges); (rows_idx += 3)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_edges); (cols_idx += 3)) //Columns
            {
                for (int sub_row_idx = rows_idx; (sub_row_idx < (rows_idx + 3)); (sub_row_idx++)) //Sub-rows
                {
                    for (int sub_col_idx = cols_idx; (sub_col_idx < (cols_idx + 3)); (sub_col_idx++)) //Sub-columns
                    {
                        ///// Check if the current indexed-char matched conditions or not /////
                        if ((board[sub_row_idx])[sub_col_idx] != '.')
                        {
                            ///// Check if the current indexed-char existed or not /////
                            if (record_corner_map.find((board[sub_row_idx])[sub_col_idx]) == record_corner_map.end()) { record_corner_map[(board[sub_row_idx])[sub_col_idx]] = true; } //Keep updating, recording
                            else { return false; }
                        }
                        else { ; }

                    } //Sub-columns

                } //Sub-rows

                ///// Check if the current dictionary, hasmap needs to be reset or not /////
                if (! record_corner_map.empty()) { record_corner_map.clear(); } //Update, Reset
                else { ; }

            } //Columns

        } //Rows

        return true;
    }
};
