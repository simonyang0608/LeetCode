class Solution {
public:
    int rob(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result maximun value)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp((len_nums + 1), 0);


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        record_dp[1] = nums[0]; //Update, Overwrite

        for (int nums_idx = 2; (nums_idx <= len_nums); (nums_idx++)) //Whole
        {
            record_dp[nums_idx] = record_dp[(nums_idx - 1)]; //Keep updating, transferring

            record_dp[nums_idx] = max(record_dp[nums_idx], (record_dp[(nums_idx - 2)] + nums[(nums_idx - 1)])); //Keep updating, overwriting

        } //Whole

        return record_dp[len_nums];
    }
};
