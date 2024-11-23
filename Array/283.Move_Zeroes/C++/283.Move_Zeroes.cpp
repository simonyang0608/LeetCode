class Solution {
public:
    void moveZeroes(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - void (no return)               //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 1;

        ///// Record value /////
        int record_val;


        /*Two-pointers based loop traversal*/
        while (record_right_ptr < len_nums) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (! nums[record_left_ptr])
            {
                if (! nums[record_right_ptr]) { (record_right_ptr++); } //Keep updating, traversing
                else
                {
                    record_val = nums[record_right_ptr]; //Record value

                    nums[record_right_ptr] = nums[record_left_ptr]; //Keep updating, swap
                    nums[record_left_ptr] = record_val; //Keep updating, swap

                    while ((record_left_ptr < record_right_ptr) && (nums[record_left_ptr])) { (record_left_ptr++); } //Keep updating, traversing
                }
            }

            else
            {
                (record_left_ptr++); //Keep updating, traversing
                (record_right_ptr++); //Keep updating, traversing
            }

        } //Whole
    }
};
