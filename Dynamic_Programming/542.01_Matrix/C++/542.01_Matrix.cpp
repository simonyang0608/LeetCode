class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> & mat) 
    {
        //===========================================//
        // Input type:                               //
        //   - vector<vector<int>> ref. (mat vector) //
        // Return type:                              //
        //   - vector<vector<int>> (result vector)   //
        //===========================================//

        /*Initialize*/
        ///// Lenght of rows, columns /////
        int len_rows = mat.size(), len_cols = (mat[0]).size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<int>> record_dp(mat.begin(), mat.end());


        /*Dynamic-programming based loop traversal*/
        ///// Step 1: Looped-traversal for the top-down cells positions /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows (top-down)
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns (top-down)
            {
                ///// Check if the current cell is valid or not /////
                if (! (record_dp[rows_idx])[cols_idx]) { continue; }

                (record_dp[rows_idx])[cols_idx] = (1e4 + 1); //Keep updating, overwriting

                ///// Check if the current indexed-rows exceed boundary or not /////
                if ((rows_idx - 1) >= 0)
                {
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], ((record_dp[(rows_idx - 1)])[cols_idx] + 1)); //Keep updating, overwriting
                }
                else { ; }

                ///// Check if the current indexed-columns exceed boundary or not /////
                if ((cols_idx - 1) >= 0)
                {
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], ((record_dp[rows_idx])[(cols_idx - 1)] + 1)); //Keep updating, overwriting
                }
                else { ; }

            } //Columns (top-down)

        } //Rows (top-down)

        ///// Step 1: Looped-traversal for the bottom-up cells positions /////
        for (int rows_idx = (len_rows - 1); (rows_idx >= 0); (rows_idx--)) //Rows (bottom-up)
        {
            for (int cols_idx = (len_cols - 1); (cols_idx >= 0); (cols_idx--)) //Columns (bottom-up)
            {
                ///// Check if the current cell is valid or not /////
                if (! (record_dp[rows_idx])[cols_idx]) { continue; }

                ///// Check if the current indexed-rows exceed boundary or not /////
                if ((rows_idx + 1) < len_rows)
                {
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], ((record_dp[(rows_idx + 1)])[cols_idx] + 1)); //Keep updating, overwriting
                }
                else { ; }

                ///// Check if the current indexed-columns exceed boundary or not /////
                if ((cols_idx + 1) < len_cols)
                {
                    (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], ((record_dp[rows_idx])[(cols_idx + 1)] + 1)); //Keep updating, overwriting 
                }
                else { ; }

            } //Columns (bottom-up)

        } //Rows (bottom-up)

        return record_dp;
    }
};
