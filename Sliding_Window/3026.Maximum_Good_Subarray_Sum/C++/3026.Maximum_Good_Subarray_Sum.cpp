class Solution {
public:
    long long maximumSubarraySum(vector<int> & nums, int k) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<int> ref. (nums vector)           //
        //   - int (k-th difference)                    //
        // Return type:                                 //
        //   - long long (result maximun summary value) //
        //==============================================//

        /*Initialize*/
        ///// Lengt of nums vector /////
        int len_nums = nums.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<long long> record_dp((len_nums + 1), 0);

        for (int nums_idx = 1; (nums_idx <= len_nums); (nums_idx++))
        {
            record_dp[nums_idx] = (record_dp[(nums_idx - 1)] + nums[(nums_idx - 1)]);
        }

        ///// Result maximun summary value /////
        long long res_max_sum = (((-1) * 1e14) - 1);


        /*One-pass record based loop traversal with recorded dictionary, hashmap*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current differenced-value existed or not /////
            if (record_map.find((nums[nums_idx] - k)) != record_map.end())
            {
                ///// Check if the current summary value is larger or not /////
                if ((record_dp[(nums_idx + 1)] - record_dp[record_map[(nums[nums_idx] - k)]]) > res_max_sum)
                {
                    res_max_sum = (record_dp[(nums_idx + 1)] - record_dp[record_map[(nums[nums_idx] - k)]]); //Keep updating, overwriting
                }
                else { ; }
            }
            else { ; }

            ///// Check if the current differenced-value existed or not /////
            if (record_map.find((nums[nums_idx] + k)) != record_map.end())
            {
                ///// Check if the current summary value is larger or not /////
                if ((record_dp[(nums_idx + 1)] - record_dp[record_map[(nums[nums_idx] + k)]]) > res_max_sum)
                {
                    res_max_sum = (record_dp[(nums_idx + 1)] - record_dp[record_map[(nums[nums_idx] + k)]]); //Keep updating, overwriting
                }
                else { ; }
            }
            else { ; }

            ///// Check if the current indexed-value existed or not /////
            if (record_map.find(nums[nums_idx]) != record_map.end())
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if (record_dp[(nums_idx + 1)] > record_dp[(record_map[nums[nums_idx]] + 1)]) { ; }
                else { record_map[nums[nums_idx]] = nums_idx; } //Keep updating, recording
            }
            else { record_map[nums[nums_idx]] = nums_idx; } //Keep updating, recording

        } //Whole

        return (res_max_sum == (((-1) * 1e14) - 1)) ? 0 : res_max_sum;
    }
};
