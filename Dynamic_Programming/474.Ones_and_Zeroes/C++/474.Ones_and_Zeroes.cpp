class Solution {
public:
    int findMaxForm(vector<string> & strs, int m, int n) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<string> ref. (strs vector) //
        //   - int (m-th zeros)                  //
        //   - int (n-th ones)                   //
        // Return type:                          //
        //   - int (result maximun subsets)      //
        //=======================================//

        /*Initialize*/
        ///// Length of strs vector /////
        int len_strs = strs.size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<int>> record_dp((m + 1), vector<int>((n + 1), 0));


        /*Dynamic-programming based loop traversal*/
        for (int strs_idx = 0; (strs_idx < len_strs); (strs_idx++)) //Whole
        {
            int zeros_cnter = 0; int ones_cnter = 0; //Zeros, Ones summary counter

            for (const char & record_chr: strs[strs_idx]) //Whole
            {
                ///// Check if the current char is zeros or not /////
                if (record_chr == '0') { (zeros_cnter++); } //Keep updating, accumulating
                else { (ones_cnter++); } //Keep updating, accumulating

            } //Whole

            for (int zeros_idx = m; (zeros_idx >= zeros_cnter); (zeros_idx--)) //Zeros
            {
                for (int ones_idx = n; (ones_idx >= ones_cnter); (ones_idx--)) //Ones
                {
                    (record_dp[zeros_idx])[ones_idx] = max((record_dp[zeros_idx])[ones_idx], ((record_dp[(zeros_idx - zeros_cnter)])[(ones_idx - ones_cnter)] + 1)); //Keep updating, overwriting

                } //Ones

            } //Zeros

        } //Whole

        return (record_dp[m])[n];
    }
};
