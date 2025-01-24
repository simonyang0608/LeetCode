class Solution {
public:
    vector<int> searchRange(vector<int> & nums, int target) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (target value)             //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_nums - 1);

        ///// Result vector /////
        vector<int> res_vect(2, (-1));


        /*Binary-search based loop traversal*/
        ///// Step 1: Looped-traversal for finding the target index /////
        if (! len_nums) { return res_vect; } //Issue, Boundary-case handling

        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            ///// Check if the current indexed-value is larger than target or not /////
            if (nums[record_mid_ptr] >= target) { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        ///// Step 2: Post-process, Final completions /////
        if (nums[record_left_ptr] != target) { return res_vect; } //Issue, Boundary-case handling

        res_vect[0] = record_left_ptr; //Update, Overwrite

        while (((record_left_ptr + 1) < len_nums) && (nums[(record_left_ptr + 1)] == target)) //Part
        {
            (record_left_ptr++); //Keep updating, traversing

        } //Part

        res_vect[1] = record_left_ptr; //Update, Overwrite

        return res_vect;
    }
};
