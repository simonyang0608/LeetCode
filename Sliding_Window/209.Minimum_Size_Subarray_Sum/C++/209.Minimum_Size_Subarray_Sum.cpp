class Solution {
public:
    int minSubArrayLen(int target, vector<int> & nums) 
    {
        //==========================================//
        // Input type:                              //
        //   - int (target value)                   //
        //   - vector<int> ref. (nums vector)       //
        // Return type:                             //
        //   - int (result minimun summary counter) //
        //==========================================//
        if (accumulate(nums.begin(), nums.end(), 0) < target) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record prefix-summary value /////
        int record_prefix_sum = 0;

        ///// Result minimun summary counter /////
        int res_min_cnter = 100001;


        /*Two-pointers based loop traversal*/
        while ((record_right_ptr < len_nums) && (record_left_ptr <= record_right_ptr)) //Whole
        {
            record_prefix_sum += nums[record_right_ptr]; //Keep updating, accumulating

            while (record_prefix_sum >= target) //Part
            {
                res_min_cnter = min(res_min_cnter, ((record_right_ptr - record_left_ptr) + 1)); //Keep updating, overwriting 
                record_prefix_sum -= nums[record_left_ptr]; //Keep updating, reducing

                (record_left_ptr++); //Keep updating, accumulating

            } //Part

            (record_right_ptr++); //Keep updating, accumulating

        } //Whole

        return res_min_cnter;
    }
};
