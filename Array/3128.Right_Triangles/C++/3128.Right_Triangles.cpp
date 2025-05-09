class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - long long (result summary counter)     //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record vectors (i.e. rows, columns) /////
        vector<int> record_vect_rows(len_rows, 0), record_vect_cols(len_cols, 0);

        ///// Result summary counter /////
        long long res_cnter = 0;


        /*Counting-based loop traversal with recorded vectors*/
        ///// Step 1: Record indexed-values informations with vectors /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((grid[rows_idx])[cols_idx])
                {
                    ((record_vect_rows[rows_idx])++); //Keep updating, accumulating
                    ((record_vect_cols[cols_idx])++); //Keep updating, accumulating
                }
                else { ; }

            } //Columns

        } //Rows

        ///// Step 2: Looped-traversal with recorded vectors /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((grid[rows_idx])[cols_idx])
                {
                    ///// Check if the current summary counter matched conditions or not /////
                    if (record_vect_rows[rows_idx] == 1) { continue; }
                    if (record_vect_cols[cols_idx] == 1) { continue; }

                    res_cnter += ((record_vect_rows[rows_idx] - 1) * (record_vect_cols[cols_idx] - 1)); //Keep updating, accumulating
                }
                else { ; }
                 
            } //Columns

        } //Rows

        return res_cnter;
    }
};
