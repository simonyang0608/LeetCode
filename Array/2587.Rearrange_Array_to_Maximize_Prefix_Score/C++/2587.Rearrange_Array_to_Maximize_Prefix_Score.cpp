class Solution {
public:
    int maxScore(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result maximun score)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Sorted operations /////
        sort(nums.rbegin(), nums.rend());

        ///// Record prefix-summary value /////
        long long record_prefix_sum = 0;

        ///// Result maximun score /////
        int res_max_score = 0;


        /*One-pass update based loop traversal with recorded prefix-summary value*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_prefix_sum += nums[nums_idx]; //Keep updating, accumulating

            ///// Check if the current prefix-summary value matched conditions or not /////
            if (record_prefix_sum > 0) { (res_max_score++); } //Keep updating, accumulating
            else { break; }

        } //Whole

        return res_max_score;
    }
};
