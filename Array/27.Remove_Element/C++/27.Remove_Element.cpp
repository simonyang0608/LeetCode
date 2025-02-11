class Solution {
public:
    int removeElement(vector<int> & nums, int val) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (target value)             //
        // Return type:                       //
        //   - int (result summary value)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = (len_nums - 1), record_right_ptr = (len_nums - 1);


        /*Two-pointers based loop traversal*/
        ///// Step 1: Looped-traversal for the swapped-stage /////
        while (record_left_ptr >= 0) //Whole
        {
            ///// Check if the current indexed-value is target or not /////
            if (nums[record_left_ptr] == val)
            { 
                swap(nums[record_left_ptr], nums[record_right_ptr]); //Keep updating, swapped

                (record_right_ptr--); //Keep updating, traversing
            }
            else { ; }

            (record_left_ptr--); //Keep updating, traversing

        } //Whole

        ///// Step 2: Post-process, Final completions /////
        while ((! nums.empty()) && (nums.back() == val)) //Part
        {
            nums.pop_back(); //Keep updating, popped

        } //Part

        return nums.size();
    }
};
