class Solution {
public:
    int maximumBeauty(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th threshold)           //
        // Return type:                       //
        //   - int (result maximun length)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record maximun difference /////
        int record_max_diff = (k * 2);

        ///// Result maximun length /////
        int res_max_length = 0;


        /*Sliding-window based loop traversal*/
        sort(nums.begin(), nums.end()); //Sorted operations

        while (record_right_ptr < len_nums) //Whole
        {
            while ((nums[record_right_ptr] - nums[record_left_ptr]) > record_max_diff) //Part
            {
                (record_left_ptr++); //Keep updating, traversing

            } //Part

            res_max_length = max(res_max_length, (record_right_ptr - record_left_ptr + 1)); //Keep updating, overwriting

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_max_length;
    }
};
