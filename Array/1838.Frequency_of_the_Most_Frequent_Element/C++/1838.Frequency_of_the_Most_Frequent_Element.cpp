class Solution {
public:
    int maxFrequency(vector<int> & nums, int k) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (nums vector)       //
        //   - int (k-th operations)                //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Sorted operations /////
        sort(nums.begin(), nums.end());

        ///// Record steps /////
        long long record_steps = 0;

        ///// Record two-pointer (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record right value /////
        long long record_right_val;

        ///// Record fixed-window value /////
        long long record_fixed_winval;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Two-pointer based loop traversal*/
        while (record_right_ptr < len_nums) //Whole
        {
            record_right_val = nums[record_right_ptr]; //Record right value

            record_steps += record_right_val; //Keep updating, accumulating
            record_fixed_winval = (record_right_val * ((record_right_ptr - record_left_ptr) + 1)); //Record fixed-window value

            while ((record_fixed_winval - record_steps) > k) //Part
            {
                record_steps -= nums[record_left_ptr]; //Keep updating, reducing

                (record_left_ptr++); //Keep updating, accumulating
                record_fixed_winval -= record_right_val; //Keep updating, reducing

            } //Part

            res_max_cnter = (((record_right_ptr - record_left_ptr) + 1) > res_max_cnter) ? ((record_right_ptr - record_left_ptr) + 1) : res_max_cnter; //Keep updating, overwriting

            (record_right_ptr++); //Keep updating, accumulating

        } //Whole

        return res_max_cnter;
    }
};
