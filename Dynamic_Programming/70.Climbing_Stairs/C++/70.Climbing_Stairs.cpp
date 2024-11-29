class Solution {
public:
    int climbStairs(int n) 
    {
        //=======================//
        // Input type:           //
        //   - int (n-th length) //
        // Return type:          //
        //   - int (result ways) //
        //=======================//
        if ((n == 1) || (n == 2)) { return n; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp((++n), 0);

        record_dp[1] = 1;
        record_dp[2] = 2;


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int dp_idx = 3; (dp_idx < n); (dp_idx++)) //Whole
        {
            record_dp[dp_idx] = (record_dp[(dp_idx - 1)] + record_dp[(dp_idx - 2)]); //Keep updating, overwriting

        } //Whole

        return record_dp[(--n)];
    }
};
