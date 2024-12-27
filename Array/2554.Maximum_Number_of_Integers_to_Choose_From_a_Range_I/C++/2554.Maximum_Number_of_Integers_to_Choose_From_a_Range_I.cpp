class Solution {
public:
    int maxCount(vector<int> & banned, int n, int maxSum) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (banned vector)     //
        //   - int (n-th value)                     //
        //   - int (maximun summary value)          //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Record set /////
        set<int> record_set(banned.begin(), banned.end());

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp((n + 1), 0);

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Dynamic-programming based loop traversal with recorded set*/
        for (int record_idx = 1; (record_idx <= n); (record_idx++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_set.find(record_idx) != record_set.end()) { record_dp[record_idx] = record_dp[(record_idx - 1)]; continue; } //Keep updating, overwriting

            record_dp[record_idx] = (record_dp[(record_idx - 1)] + record_idx); //Keep updating, overwriting

            ///// Check if the current indexed-value exceed bouundary or not /////
            if (record_dp[record_idx] > maxSum) { break; }

            (res_max_cnter++); //Keep updating, accumulating

        } //Whole

        return res_max_cnter;
    }
};
