class Solution {
public:
    int findBestValue(vector<int> & arr, int target) 
    {
        //===================================//
        // Input type:                       //
        //   - vector<int> ref. (arr vector) //
        //   - int (target value)            //
        // Return type:                      //
        //   - int (result value)            //
        //===================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record sumamry value /////
        int record_sum_val = 0;

        ///// Record pointers (i.e. middle, left, right) /////
        int record_mid_ptr, record_left_ptr = 0, record_right_ptr = *max_element(arr.begin(), arr.end());

        ///// Record pointers (i.e. left, right-bound) /////
        int record_lb_ptr, record_rb_ptr;

        ///// Record values (i.e. left, right-bound) /////
        int record_lb_val, record_rb_val;


        /*Binary-seach based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            findSumval(record_sum_val, arr, record_mid_ptr, len_arr); //Find-value function call

            ///// Check if the current summary value matched conditions or not /////
            if (record_sum_val < target) { record_lb_val = record_sum_val; record_lb_ptr = record_mid_ptr; record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

            else if (record_sum_val == target) { return record_mid_ptr; }
            else { record_rb_val = record_sum_val; record_rb_ptr = record_mid_ptr; record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

            ///// Check if the current summary value needs to be reset or not /////
            if (record_sum_val) { record_sum_val &= 0; } //Update, Reset
            else { ; }

        } //Binary-search

        return (abs((record_lb_val - target)) <= abs((record_rb_val - target))) ? record_lb_ptr : record_rb_ptr;
    }


    void findSumval(int & record_sum_val, vector<int> & arr, int & record_val, int & len_arr)
    {
        //=====================================//
        // Input type:                         //
        //   - int ref. (record summary value) //
        //   - vector<int> ref. (arr vector)   //
        //   - int ref. (record value)         //
        //   - int ref. (length of arr vector) //
        // Return type:                        //
        //   - void (no return)                //
        //=====================================//

        /*Whole process, flow*/
        for (int record_idx = 0; (record_idx < len_arr); (record_idx++)) //Whole
        {
            record_sum_val += min(record_val, arr[record_idx]); //Keep updating, accumulating

        } //Whole
    }
};
