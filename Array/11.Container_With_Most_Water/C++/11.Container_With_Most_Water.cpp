class Solution {
public:
    int maxArea(vector<int> & height) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (height vector)   //
        // Return type:                           //
        //   - int (result maximun summary value) //
        //========================================//

        /*Initialize*/
        ///// Length of height vector /////
        int len_height = height.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_height - 1);

        ///// Result maximun summary value /////
        int res_max_sum = (-1);


        /*Two-pointers based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Two-pointers search
        {
            res_max_sum = max(res_max_sum, (min(height[record_left_ptr], height[record_right_ptr]) * (record_right_ptr - record_left_ptr))); //Keep updating, overwriting

            ///// Check if the current indexed-value is smaller or not /////
            if (height[record_left_ptr] < height[record_right_ptr]) { (record_left_ptr++); } //Keep updating, traversing
            else { (record_right_ptr--); } //Keep updating, traversing

        } //Two-pointers search

        return res_max_sum;
    }
};
