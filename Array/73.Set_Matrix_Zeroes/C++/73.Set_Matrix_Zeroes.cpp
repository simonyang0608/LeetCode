class Solution {
public:
    void setZeroes(vector<vector<int>> & matrix) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (matrix vector) //
        // Return type:                                 //
        //   - void (no return)                         //
        //==============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = matrix.size(), len_cols = (matrix[0]).size();

        ///// Zero-position vector /////
        vector<pair<int, int>> zero_position_vect;


        /*Specific-value record based loop traversal with recorded vector*/
        ///// Step 1: Record zero-value position index with vector /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value is zero or not /////
                if (! (matrix[rows_idx])[cols_idx]) { zero_position_vect.emplace_back(rows_idx, cols_idx); } //Keep updating, recording
                else { ; }

            } //Columns

        } //Rows

        ///// Step 2: Looped-traversal with recorded vector /////
        for (int zero_position_idx = (zero_position_vect.size() - 1); (zero_position_idx >= 0); (zero_position_idx--)) //Position index
        {
            int record_position_row = (zero_position_vect[zero_position_idx]).first; //Record position row index
            int record_position_col = (zero_position_vect[zero_position_idx]).second; ////Record position column index

            for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
            {
                ///// Check if the current indexed-value is zero or not /////
                if (! ((matrix[rows_idx])[record_position_col])) { continue; }

                (matrix[rows_idx])[record_position_col] = 0; //Keep updating, overwriting

            } //Rows

            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value is zero or not /////
                if (! ((matrix[record_position_row])[cols_idx])) { continue; }

                (matrix[record_position_row])[cols_idx] = 0; //Keep updating, overwriting

            } //Columns

        } //Position index
    }
};
