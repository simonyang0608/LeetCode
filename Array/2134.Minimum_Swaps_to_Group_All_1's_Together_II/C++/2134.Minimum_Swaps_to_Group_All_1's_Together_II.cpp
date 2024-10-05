class Solution {
public:
    int minSwaps(vector<int> & nums) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums vector)  //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Summary of nums vector /////
        int sum_nums = accumulate(nums.begin(), nums.end(), 0);

        ///// Record summary value /////
        int record_sum_val = 0;

        for (int nums_idx = 0; (nums_idx < sum_nums); (nums_idx++))
        {
            record_sum_val += nums[nums_idx];
        }

        ///// Result maximun summary value /////
        int res_max_sum_val = record_sum_val;


        /*Sliding-window based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_sum_val -= nums[nums_idx]; //Keep updating, reducing
            record_sum_val += nums[((nums_idx + sum_nums) % len_nums)]; //Keep updating, accumulating

            res_max_sum_val = max(res_max_sum_val, record_sum_val); //Keep updating, overwriting

        } //Whole

        return (sum_nums - res_max_sum_val);
    }
};
