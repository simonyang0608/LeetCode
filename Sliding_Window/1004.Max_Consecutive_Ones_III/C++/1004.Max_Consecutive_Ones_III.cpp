class Solution {
public:
    int longestOnes(vector<int> & nums, int k) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (nums vector)       //
        //   - int (k-th value)                     //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record k-th value /////
        int record_kth = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Sliding-window based loop traversal*/
        while (record_right_ptr < len_nums) //Right-pointer
        {
            record_kth += (nums[record_right_ptr] == 0) ? 1 : 0; //Keep updating, accumulating

            while (record_kth > k) //Part
            {
                record_kth -= (nums[record_left_ptr] == 0) ? 1 : 0; //Keep updating, reducing

                (record_left_ptr++); //Keep updating, traversing

            } //Part

            res_max_cnter = max(res_max_cnter, (record_right_ptr - record_left_ptr + 1)); //Keep updating, overwriting

            (record_right_ptr++); //Keep updating, traversing

        } //Right-pointer

        return res_max_cnter;
    }
};
