class Solution {
public:
    int findUnsortedSubarray(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result length)            //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Sort nums vector /////
        vector<int> sort_nums(nums.begin(), nums.end());

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_nums - 1);

        ///// Result two-pointers (i.e. left, right) /////
        int res_left_ptr = (-1), res_right_ptr = (-1);


        /*Two-pointers based loop traversal*/
        sort(sort_nums.begin(), sort_nums.end()); //Sorted operations

        while (record_left_ptr < record_right_ptr) //Two-pointers
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[record_left_ptr] == sort_nums[record_left_ptr]) { (record_left_ptr++); } //Keep updating, traversing
            else { res_left_ptr = record_left_ptr; } //Keep updating, overwriting

            if (nums[record_right_ptr] == sort_nums[record_right_ptr]) { (record_right_ptr--); } //Keep updating, traversing
            else { res_right_ptr = record_right_ptr; } //Keep updating, overwriting

            ///// Check if the current pointers matched conditions or not /////
            if ((res_left_ptr != (-1)) && (res_right_ptr != (-1))) { break; }

        } //Two-pointers

        return ((res_left_ptr == (-1)) && (res_right_ptr == (-1))) ? 0: ((res_right_ptr - res_left_ptr) + 1);
    }
};
