class Solution {
public:
    double findMaxAverage(vector<int> & nums, int k) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums vector)  //
        //   - int (k-th window-size)          //
        // Return type:                        //
        //   - double (result maximun average) //
        //=====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record summary value /////
        double record_sum_val = 0;

        ///// Result maximun summary value /////
        double res_max_sum = (((-1) * 1e4) - 1);


        /*Sliding-window based loop traversal*/
        ///// Step 1: Looped-traversal for the fixed-window size /////
        for (int nums_idx = 0; (nums_idx < k); (nums_idx++)) //Fixed-window
        {
            record_sum_val += nums[nums_idx]; //Keep updating, accumulating

        } //Fixed-window

        ///// Step 2: Looped-traversal for the remainings /////
        res_max_sum = max(res_max_sum, (record_sum_val / k)); //Update, Overwrite

        for (int nums_idx = k; (nums_idx < len_nums); (nums_idx++)) //Remainings
        {
            record_sum_val -= nums[(nums_idx - k)]; //Keep updating, reducing

            record_sum_val += nums[nums_idx]; //Keep updating, accumulating

            res_max_sum = max(res_max_sum, (record_sum_val / k)); //Keep updating, overwriting

        } //Remainings

        return res_max_sum;
    }
};
