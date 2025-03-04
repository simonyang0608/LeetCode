class Solution {
public:
    int maxOperations(vector<int> & nums, int k) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums vector)  //
        //   - int (k-th target)               //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_nums - 1);

        ///// Result minimun operations /////
        int res_min_oprs = 0;


        /*Two-pointers based loop traversal with sorted operations*/
        sort(nums.begin(), nums.end()); //Sorted operations

        while (record_left_ptr < record_right_ptr) //Two-pointers
        {
            ///// Check if the current summary-value is larger than target or not /////
            if ((nums[record_left_ptr] + nums[record_right_ptr]) > k) { (record_right_ptr--); } //Keep updating, traversing

            else if ((nums[record_left_ptr] + nums[record_right_ptr]) == k)
            {
                (res_min_oprs++); //Keep updating, accumulating

                (record_left_ptr++); (record_right_ptr--); //Keep updating, traversing
            }
            else { (record_left_ptr++); } //Keep updating, traversing

        } //Two-pointers

        return res_min_oprs;
    }
};
