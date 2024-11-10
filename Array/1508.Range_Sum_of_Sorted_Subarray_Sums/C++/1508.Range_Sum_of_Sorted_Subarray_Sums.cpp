class Solution {
public:
    int rangeSum(vector<int> & nums, int n, int left, int right) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (n-th length)              //
        //   - int (left boundary)            //
        //   - int (right boundary)           //
        // Return type:                       //
        //   - int (result summary value)     //
        //====================================//

        /*Initialize*/
        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = n;

        ///// Record prefix-summary value /////
        int record_prefix_sum = 0;

        ///// Result vector /////
        vector<int> res_vect;

        ///// Result summary value /////
        long long res_sum_val = 0;


        /*Two-pointers based loop traversal with recorded vector*/
        ///// Step 1: Looped-traversal with recorded vector /////
        while (record_left_ptr < record_right_ptr) //Whole
        {
            for (int nums_idx = record_left_ptr; (nums_idx < record_right_ptr); (nums_idx++)) //Part
            {
                record_prefix_sum += nums[nums_idx]; //Keep updating, accumulating

                res_vect.emplace_back(record_prefix_sum); //Keep updating, recording

            } //Part

            ///// Check if the current prefix-summary value needs to be reset or not /////
            if (! record_prefix_sum) { ; }
            else { record_prefix_sum &= 0; } //Reset

            (record_left_ptr++); //Keep updating, accumulating

        } //Whole

        ///// Step 2: Post-process, Final completions /////
        sort(res_vect.begin(), res_vect.end()); //Sorted-operations

        for (int res_vect_idx = (left - 1); (res_vect_idx < right); (res_vect_idx++)) //Left-Right interval
        {
            res_sum_val += (res_vect[res_vect_idx]); //Keep updating, accumulating

        } //Left-Right interval

        return (res_sum_val % (long long)((pow(10, 9) + 7)));
    }
};
