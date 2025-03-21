class Solution {
public:
    int longestMonotonicSubarray(vector<int> & nums) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (nums vector)   //
        // Return type:                         //
        //   - int (result maximun window-size) //
        //======================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Result maximun window-sizes (i.e. increase, decrease) /////
        int res_max_incr = 0, res_max_decr = 0;


        /*Greedy-based loop traversal with recorded two-pointers*/
        ///// Step 1: Looped-traversal for the increased-subarrar /////
        while (record_right_ptr < len_nums) //Right-pointer
        {
            while (((record_right_ptr + 1) < len_nums) && (nums[(record_right_ptr + 1)] > nums[record_right_ptr])) //Part
            {
                (record_right_ptr++); //Keep updating, traversing

            } //Part

            res_max_incr = max(res_max_incr, (record_right_ptr - record_left_ptr + 1)); //Keep updating, overwriting

            record_left_ptr = (++record_right_ptr); //Keep updating, traversing
        }

        ///// Step 2: Looped-traversal for the decreased-subarrar /////
        record_left_ptr &= 0; record_right_ptr &= 0; //Update, Reset

        while (record_right_ptr < len_nums) //Right-pointer
        {
            while (((record_right_ptr + 1) < len_nums) && (nums[(record_right_ptr + 1)] < nums[record_right_ptr])) //Part
            {
                (record_right_ptr++); //Keep updating, traversing

            } //Part

            res_max_decr = max(res_max_decr, (record_right_ptr - record_left_ptr + 1)); //Keep updating, overwriting

            record_left_ptr = (++record_right_ptr); //Keep updating, traversing

        } //Right-pointer

        return max(res_max_incr, res_max_decr);
    }
};
