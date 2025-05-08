class Solution {
public:
    int minFallingPathSum(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result minimun summary value)     //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<int>> record_dp(grid.begin(), grid.end());

        ///// Result minimun summary value /////
        int res_min_sum = INT_MAX;


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int rows_idx = (len_rows - 2); (rows_idx >= 0); (rows_idx--)) //Rows
        {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> record_pq; //Heap, Priority-queue

            int next_minor_min = 1e7; //Next minor minimun value

            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current heap, priority-queue is empty or not /////
                if (! record_pq.empty())
                {
                    ///// Check if the current indexed-values informations matched conditions or not /////
                    if ((record_dp[(rows_idx + 1)])[cols_idx] < (record_pq.top()).first)
                    {
                        next_minor_min = (record_pq.top()).first; //Keep updating, overwriting

                        record_pq.pop(); //Keep updating, popped

                        record_pq.emplace((record_dp[(rows_idx + 1)])[cols_idx], cols_idx); //Keep updating, recording
                    }
                    else if ((record_dp[(rows_idx + 1)])[cols_idx] < next_minor_min)
                    {
                        next_minor_min = (record_dp[(rows_idx + 1)])[cols_idx]; //Keep updating, overwriting
                    }
                    else { ; }
                }
                else
                {
                    record_pq.emplace((record_dp[(rows_idx + 1)])[cols_idx], cols_idx); //Keep updating, recording
                }
            }

            int next_min_val = (record_pq.top()).first; int next_idx = (record_pq.top()).second; //Next minimun value, index

            (record_dp[rows_idx])[next_idx] += next_minor_min; //Keep updating, accumulating

            ///// Check if the current rows index matched conditions or not /////
            if (! rows_idx) { res_min_sum = ((record_dp[rows_idx])[next_idx] < res_min_sum) ?
                                             (record_dp[rows_idx])[next_idx] : res_min_sum; } //Keep updating, overwriting
            else { ; } 

            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current columns index matched conditions or not /////
                if (cols_idx == next_idx) { continue; }

                (record_dp[rows_idx])[cols_idx] += next_min_val; //Keep updating, accumulating

                ///// Check if the current rows index matched conditions or not /////
                if (! rows_idx) { res_min_sum = ((record_dp[rows_idx])[cols_idx] < res_min_sum) ?
                                                 (record_dp[rows_idx])[cols_idx] : res_min_sum; } //Keep updating, overwriting
                else { ; }

            } //Columns

        } //Rows

        return (res_min_sum == INT_MAX) ? (grid[0])[0] : res_min_sum;
    }
};
