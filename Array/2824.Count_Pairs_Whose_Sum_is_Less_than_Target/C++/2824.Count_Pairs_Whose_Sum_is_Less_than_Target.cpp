class Solution {
public:
    int countPairs(vector<int> & nums, int target) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (nums vector)       //
        //   - int (target value)                   //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Sorted operations /////
        sort(nums.begin(), nums.end());

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_nums - 1);

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Two-pointers based loop traversal with sorted vector*/
        while (record_left_ptr < record_right_ptr) //Whole
        {
            ///// Check if the current summary counter matched conditions or not /////
            if ((nums[record_left_ptr] + nums[record_right_ptr]) < target)
            {
                res_max_cnter += (record_right_ptr - record_left_ptr); //Keep updating, accumulating

                (record_left_ptr++); //Keep updating, accumulating
            }

            else { (record_right_ptr--); } //Keep updating, reducing

        } //Whole

        return res_max_cnter;
    }
};
