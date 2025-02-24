class Solution {
public:
    int longestSubarray(vector<int> & nums) 
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

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Result maximun window-size /////
        int res_max_winsize = 0;


        /*Sliding-window based loop traversal with recorded two-pointers*/
        while (record_right_ptr < len_nums) //Right-pointer
        {
            record_cnter += (! nums[record_right_ptr]) ? 1 : 0; //Keep updating, accumulating

            ///// Check if the current summary counter matched conditions or not /////
            if (record_cnter >= 2)
            {
                res_max_winsize = max(res_max_winsize, (record_right_ptr - record_left_ptr - 1)); //Keep updating, overwriting

                while (record_cnter >= 2) //Left-pointer
                {
                    record_cnter -= (! nums[record_left_ptr]) ? 1 : 0; //Keep updating, reducing

                    (record_left_ptr++); //Keep updating, traversing

                } //Left-pointer
            }
            else { res_max_winsize = max(res_max_winsize, (record_right_ptr - record_left_ptr)); } //Keep updating, overwriting

            (record_right_ptr++); //Keep updating, traversing

        } //Right-pointer

        return res_max_winsize;
    }
};
