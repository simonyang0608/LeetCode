class Solution {
public:
    int maximalSquare(vector<vector<char>> & matrix) 
    {
        //===============================================//
        // Input type:                                   //
        //   - vector<vector<char>> ref. (matrix vector) //
        // Return type:                                  //
        //   - int (result maximun area)                 //
        //===============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = matrix.size(), len_cols = (matrix[0]).size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<int>> record_dp((len_rows + 1), vector<int>((len_cols + 1), 0));

        ///// Result maximun length /////
        int res_max_length = 0;


        /*Dynamic-programming based loop traversal*/
        for (int rows_idx = 1; (rows_idx <= len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 1; (cols_idx <= len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if ((matrix[(rows_idx - 1)])[(cols_idx - 1)] - '0')
                {
                    (record_dp[rows_idx])[cols_idx] = (min((record_dp[(rows_idx - 1)])[(cols_idx - 1)], min((record_dp[(rows_idx - 1)])[cols_idx], (record_dp[rows_idx])[(cols_idx - 1)])) + 1); //Keep updating, overwriting

                    res_max_length = max(res_max_length, (record_dp[rows_idx])[cols_idx]); //Keep updating, overwriting
                }
                else { ; }

            } //Columns

        } //Rows

        return (res_max_length * res_max_length);
    }
};
