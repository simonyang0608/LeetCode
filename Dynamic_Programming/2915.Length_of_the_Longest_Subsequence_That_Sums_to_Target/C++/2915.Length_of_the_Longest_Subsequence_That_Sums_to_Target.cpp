class Solution {
public:
    int lengthOfLongestSubsequence(vector<int> & nums, int target) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (nums vector)       //
        //   - int (target value)                   //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp((target + 1), (-1));

        
        /*Dynamic-programming based loop traversal*/
        record_dp[0] = 0; //Update, Overwrite

        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            for (int record_idx = (target - nums[nums_idx]); (record_idx >= 0); (record_idx--)) //Part
            {
                ///// Check if the current summary counter matched conditions or not /////
                if (record_dp[record_idx] >= 0)
                {
                    record_dp[(record_idx + nums[nums_idx])] = max(record_dp[(record_idx + nums[nums_idx])], 
                                                                  (record_dp[record_idx] + 1)); //Keep updating, overwriting
                }
                else { ; }

            } //Part

        } //Whole

        return record_dp.back();
    }
};
