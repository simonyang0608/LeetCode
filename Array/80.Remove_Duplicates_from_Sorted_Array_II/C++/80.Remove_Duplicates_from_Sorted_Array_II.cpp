class Solution {
public:
    int removeDuplicates(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result summary counter)   //
        //====================================//
        if (nums.size() <= 2) { return nums.size(); } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 2, record_right_ptr = 2;


        /*Two-pointers based loop traversal*/
        while (record_right_ptr < len_nums) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[record_right_ptr] != nums[(record_left_ptr - 2)]) { swap(nums[(record_left_ptr++)], nums[record_right_ptr]); } //Keep updating, swapped
            else { ; }

            (record_right_ptr++); //Keep updating, traversing

        } //Whole
 
        return record_left_ptr;
    }
};
