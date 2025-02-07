class Solution {
public:
    void rotate(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th order)               //
        // Return type:                       //
        //   - void (no return)               //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record mod /////
        int record_mod = (k % len_nums);

        if (! record_mod) { return; } //Issue, Boundary-case handling

        ///// Result nums vector /////
        vector<int> res_nums(len_nums, 0);


        /*Two-pass update based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            res_nums[((nums_idx + record_mod) % len_nums)] = nums[nums_idx]; //Keep updating, overwriting

        } //Whole

        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            nums[nums_idx] = res_nums[nums_idx]; //Keep updating, overwriting

        } //Whole
    }
};
