class Solution {
public:
    long long subArrayRanges(vector<int> & nums) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (nums vector)   //
        // Return type:                         //
        //   - long long (result summary value) //
        //======================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record stack /////
        stack<int> record_stack;

        ///// Result summary value /////
        long long res_sum_val = 0;


        /*Stack-based loop traversal*/
        ///// Step 1: Looped-traversal for the minimun subarray-values /////
        nums.emplace_back((((-1) * 1e9) - 1)); //Update, Record

        for (int nums_idx = 0; (nums_idx <= len_nums); (nums_idx++)) //Whole
        {
            while ((! record_stack.empty()) && (nums[nums_idx] < nums[record_stack.top()])) //Part
            {
                int record_idx = record_stack.top(); record_stack.pop(); //Record index

                int prev_idx = (record_stack.empty()) ? (-1) : record_stack.top(); //Previous index

                res_sum_val -= (nums[record_idx] * static_cast<long long>(nums_idx - record_idx) * 
                                static_cast<long long>(record_idx - prev_idx)); //Keep updating, reducing

            } //Part

            record_stack.emplace(nums_idx); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the maximun subarray-values /////
        while (! record_stack.empty()) { record_stack.pop(); } nums.back() = (1e9 + 1); //Update, Overwrite

        for (int nums_idx = 0; (nums_idx <= len_nums); (nums_idx++)) //Whole
        {
            while ((! record_stack.empty()) && (nums[nums_idx] > nums[record_stack.top()])) //Part
            {
                int record_idx = record_stack.top(); record_stack.pop(); //Record index

                int prev_idx = (record_stack.empty()) ? (-1) : record_stack.top(); //Previous index

                res_sum_val += (nums[record_idx] * static_cast<long long>(nums_idx - record_idx) * 
                                static_cast<long long>(record_idx - prev_idx)); //Keep updating, accumulating

            } //Part

            record_stack.emplace(nums_idx); //Keep updating, recording

        } //Whole

        return res_sum_val;
    }
};
