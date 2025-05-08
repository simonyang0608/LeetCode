class Solution {
public:
    int minFallingPathSum(vector<vector<int>> & matrix) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (matrix vector) //
        // Return type:                                 //
        //   - int (result minimun summary value)       //
        //==============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = matrix.size(), len_cols = (matrix[0]).size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<int>> record_dp(matrix.begin(), matrix.end());

        ///// Result minimun summary value /////
        int res_min_sum = INT_MAX;


        /*Dynamic-programming based loop traversal*/
        for (int record_rows = (len_rows - 2); (record_rows >= 0); (record_rows--)) //Rows
        {
            for (int record_cols = 0; (record_cols < len_cols); (record_cols++)) //Columns
            {
                int next_min_val = (record_dp[(record_rows + 1)])[record_cols]; //Next minimun value

                ///// Check if the next columns index exceed boundary or not /////
                if ((record_cols - 1) >= 0)
                {
                    next_min_val = min((record_dp[(record_rows + 1)])[(record_cols - 1)], next_min_val); //Keep updating, overwriting
                }
                else { ; }

                ///// Check if the next columns index exceed boundary or not /////
                if ((record_cols + 1) < len_cols)
                {
                    next_min_val = min((record_dp[(record_rows + 1)])[(record_cols + 1)], next_min_val); //Keep updating, overwriting
                }
                else { ; }

                (record_dp[record_rows])[record_cols] += next_min_val; //Keep updating, accumulating

                ///// Check if the current row index matched conditions or not /////
                if (! record_rows)
                {
                    res_min_sum = ((record_dp[record_rows])[record_cols] < res_min_sum) ? 
                                   (record_dp[record_rows])[record_cols] : res_min_sum; //Keep updating, overwriting
                }
                else { ; }

            } //Columns

        } //Rows

        return (res_min_sum == INT_MAX) ? (matrix[0])[0] : res_min_sum;
    }
};
