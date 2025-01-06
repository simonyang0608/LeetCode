class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> & obstacleGrid) 
    {
        //====================================================//
        // Input type:                                        //
        //   - vector<vector<int>> ref. (obstacleGrid vector) //
        // Return type:                                       //
        //   - int (result summary counter)                   //
        //====================================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = obstacleGrid.size(), len_cols = (obstacleGrid[0]).size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<int>> record_dp(len_rows, vector<int>(len_cols, 0));


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
        {
            ///// Check if the current cell is valid or not /////
            if ((obstacleGrid[0])[cols_idx]) { break; }

            (record_dp[0])[cols_idx] = 1; //Keep updating, overwriting
          
        } //Columns

        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            ///// Check if the current cell is valid or not /////
            if ((obstacleGrid[rows_idx])[0]) { break; }

            (record_dp[rows_idx])[0] = 1; //Keep updating, overwriting
          
        } //Rows

        for (int rows_idx = 1; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 1; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current cell is valid or not /////
                if (! (obstacleGrid[rows_idx])[cols_idx])
                {
                    (record_dp[rows_idx])[cols_idx] = ((record_dp[(rows_idx)])[(cols_idx - 1)] + (record_dp[(rows_idx - 1)])[cols_idx]); //Keep updating, overwriting
                }
                else { ; }
              
            } //Columns
          
        } //Rows

        return (record_dp[(len_rows - 1)])[(len_cols - 1)];
    }
};
