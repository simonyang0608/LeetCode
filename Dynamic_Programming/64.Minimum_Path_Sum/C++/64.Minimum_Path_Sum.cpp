class Solution {
public:
    int minPathSum(vector<vector<int>> & grid)
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result summary value)             //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<long long>> record_dp(len_rows, vector<long long>(len_cols, 0));


        /*Dynamic-programming based loop traversal*/
        (record_dp[0])[0] = (grid[0])[0]; //Update, Overwrite

        for (int cols_idx = 1; (cols_idx < len_cols); (cols_idx++)) //First rows
        {
            (record_dp[0])[cols_idx] = ((grid[0])[cols_idx] + (record_dp[0])[(cols_idx - 1)]); //Keep updating, overwriting

        } //First rows

        for (int rows_idx = 1; (rows_idx < len_rows); (rows_idx++)) //Fisrt columns
        {
            (record_dp[rows_idx])[0] = ((grid[rows_idx])[0] + (record_dp[(rows_idx - 1)])[0]); //Keep updating, overwriting

        } //Fisrt columns

        for (int rows_idx = 1; (rows_idx < len_rows); (rows_idx++)) //Rows 
        {
            for (int cols_idx = 1; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                (record_dp[rows_idx])[cols_idx] = ((grid[rows_idx])[cols_idx] + min((record_dp[(rows_idx - 1)])[cols_idx], (record_dp[rows_idx])[(cols_idx - 1)])); //Keep updating, overwriting

            } //Columns

        } //Rows

        return (int)((record_dp[(len_rows - 1)])[(len_cols - 1)]);
    }
};
