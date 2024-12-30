class Solution {
public:
    int findPeakElement(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result peak value)        //
        //====================================//
        if (nums.size() == 1) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record pointers (i.e. middle, left, right) /////
        int record_mid_ptr, record_left_ptr = 0, record_right_ptr = (len_nums - 1);


        /*Binary-search based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Keep updating, overwriting

            ///// Check if the current indexed-value matched conditions or not /////
            if ((nums[record_mid_ptr] < nums[(record_mid_ptr + 1)])) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }
};
