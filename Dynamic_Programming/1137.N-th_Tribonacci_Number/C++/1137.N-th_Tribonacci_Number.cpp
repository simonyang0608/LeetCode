class Solution {
public:
    int tribonacci(int n) 
    {
        //================================//
        // Input type:                    //
        //   - int (n-th times)           //
        // Return type:                   //
        //   - int (result summary value) //
        //================================//
        if (! n) { return 0; } //Issue, Boundary-case handling
        
        if (n <= 2) { return 1; } //Issue, Boundary-case handling


        /*Initialize*/
        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp((n + 1), 0);

        /*Dynamic-programming based loop traversal*/
        record_dp[0] = 0; record_dp[1] = 1; record_dp[2] = 1; //Update, Overwrite

        for (int n_idx = 3; (n_idx <= n); (n_idx++)) //N-th times
        {
            record_dp[n_idx] = (record_dp[(n_idx - 1)] + record_dp[(n_idx - 2)] + record_dp[(n_idx - 3)]); //Keep updating, overwriting

        } //N-th times

        return record_dp[n];
    }
};
