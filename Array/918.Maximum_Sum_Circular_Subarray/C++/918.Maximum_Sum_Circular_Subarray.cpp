class Solution {
public:
    int maxSubarraySumCircular(vector<int> & nums) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums vector)     //
        // Return type:                           //
        //   - int (result maximun summary value) //
        //========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Maximun of nums vector /////
        int max_nums = *max_element(nums.begin(), nums.end());

        if (max_nums < 0) { return max_nums; } //Issue, Boundary-case handling

        int record_max_sum = 0, record_min_sum = 0;

        ///// Record values (i.e. minimun, maximun) /////
        int record_min_val = ((9 * 1e8) + 1), record_max_val = (((-9) * 1e8) - 1);

        ///// Result total summary value /////
        int res_total_sum = 0;


        /*Kadane's-based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_max_sum += nums[nums_idx]; //Keep updating, accumulating

            ///// Check if the current summary value is negative or not /////
            if (record_max_sum < 0) { record_max_sum &= 0; } //Keep updating, reset
            else { ; }

            record_max_val = max(record_max_val, record_max_sum); //Keep updating, overwriting

            record_min_sum += nums[nums_idx]; //Keep updating, accumulating

            ///// Check if the current summary value is positive or not /////
            if (record_min_sum > 0) { record_min_sum &= 0; } //Keep updating, reset
            else { ; }

            record_min_val = min(record_min_val, record_min_sum); //Keep updating, overwriting

            res_total_sum += nums[nums_idx]; //Keep updating, accumulating

        } //Whole

        return ((res_total_sum - record_min_val) > record_max_val) ? (res_total_sum - record_min_val) : record_max_val;
    }
};
