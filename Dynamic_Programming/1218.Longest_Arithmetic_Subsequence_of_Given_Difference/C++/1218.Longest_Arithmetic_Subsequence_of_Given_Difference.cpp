class Solution {
public:
    int longestSubsequence(vector<int> & arr, int difference) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (arr vector)        //
        //   - int (difference value)               //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record dynamic-programming (i.e. DP) /////
        unordered_map<int, int> record_dp;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Dynamic-programming based loop traversal*/
        record_dp[arr[0]] = 1; //Update, Overwrite

        for (int arr_idx = 1; (arr_idx < len_arr); (arr_idx++)) //Whole
        {
            record_dp[arr[arr_idx]] = ((record_dp[arr[arr_idx] - difference]) + 1); //Keep updating, recording

            res_max_cnter = max(res_max_cnter, record_dp[arr[arr_idx]]); //Keep updating, overwriting
        }

        return res_max_cnter;
    }
};
