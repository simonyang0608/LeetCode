class Solution {
public:
    int minOperations(vector<int> & nums, int x) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums vector)  //
        //   - int (x-target value)            //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Summary of nums vector /////
        int sum_nums = accumulate(nums.begin(), nums.end(), 0);

        ///// Record left-pointer /////
        int record_left_ptr = 0;

        ///// Record prefix-summary value /////
        int record_prefix_sum = 0;

        ///// Record fixed-interval value /////
        int record_inter_val = (sum_nums - x);

        ///// Result maximun window-size /////
        int res_max_winsize = (-1);


        /*Sliding-window based loop traversal*/
        for (int record_right_ptr = 0; (record_right_ptr < len_nums); (record_right_ptr++)) //Whole
        {
            record_prefix_sum += nums[record_right_ptr]; //Keep updating, accumulating

            while ((record_left_ptr <= record_right_ptr) && (record_prefix_sum > record_inter_val)) //Part
            {
                record_prefix_sum -= nums[record_left_ptr]; //Keep updating, reducing

                (record_left_ptr++); //Keep updating, accumulating

            } //Part

            ///// Check if the current value matched conditions or not /////
            if (record_prefix_sum == record_inter_val)
            {
                res_max_winsize = max(res_max_winsize, ((record_right_ptr - record_left_ptr) + 1)); //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return (res_max_winsize == (-1)) ? (-1) : (len_nums - res_max_winsize);
    }
};
