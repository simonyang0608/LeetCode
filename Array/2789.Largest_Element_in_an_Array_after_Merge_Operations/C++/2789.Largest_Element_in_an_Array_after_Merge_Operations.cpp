class Solution {
public:
    long long maxArrayValue(vector<int> & nums) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<int> ref. (nums vector)           //
        // Return type:                                 //
        //   - long long (result maximun summary value) //
        //==============================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record right pointer /////
        int record_right_ptr = (len_nums - 1);

        ///// Record summary value /////
        long long record_sum_val = 0;

        ///// Result maximun summary value /////
        long long res_max_sum_val = 0;


        /*Greedy-based loop traversal*/
        while (record_right_ptr >= 0) //Whole
        {
            record_sum_val += nums[record_right_ptr]; //Keep updating, accumulating

            while (((record_right_ptr - 1) >= 0) && (record_sum_val >= nums[(record_right_ptr - 1)])) //Part
            {
                record_sum_val += nums[(record_right_ptr - 1)]; //Keep updating, accumulating

                (record_right_ptr--); //Keep updating, reducing

            } //Part

            res_max_sum_val = max(res_max_sum_val, record_sum_val); //Keep updating, overwriting

            ///// Check if the current summary value needs to be reset or not /////
            if (! record_sum_val) { ; }
            else { record_sum_val &= 0; } //Reset

            (record_right_ptr--); //Keep updating, reducing

        } //Whole

        return res_max_sum_val;
    }
};
