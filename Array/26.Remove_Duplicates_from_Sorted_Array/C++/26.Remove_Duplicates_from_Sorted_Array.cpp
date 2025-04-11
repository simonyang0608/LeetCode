class Solution {
public:
    int removeDuplicates(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result length, size)      //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record two pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;


        /*Two-pointers based loop traversal*/
        while (record_right_ptr < len_nums) //Whole
        {
            nums[(record_left_ptr++)] = nums[record_right_ptr]; //Keep updating, recording

            int next_ptr = binarySearch(len_nums, nums, record_right_ptr, nums[record_right_ptr]); //Next traversal pointer

            record_right_ptr = next_ptr; //Keep updating, overwriting

        } //Whole

        return record_left_ptr;
    }


    int binarySearch(const int & len_nums, const vector<int> & nums, const int & record_idx, 
                     const int & record_val)
    {
        //============================================//
        // Input type:                                //
        //   - const int ref. (length of nums vector) //
        //   - const vector<int> ref. (nums vector)   //
        //   - int (record index)                     //
        //   - const int ref. (record value)          //
        // Return type:                               //
        //   - int (result index)                     //
        //============================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = (record_idx + 1), record_right_ptr = (len_nums - 1);

        /*Whole process, flow*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[record_mid_ptr] <= record_val) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }
};
