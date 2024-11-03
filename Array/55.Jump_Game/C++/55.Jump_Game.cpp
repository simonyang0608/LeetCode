class Solution {
public:
    bool canJump(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - bool (result flag)             //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record steps /////
        int record_steps = nums[0];


        /*Greedy-based loop traversal*/
        for (int nums_idx = 1; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current steps matched conditions or not /////
            if (record_steps > 0)
            {
                (record_steps--); //Keep updating, reducing

                record_steps = max(record_steps, nums[nums_idx]); //Keep updating, overwirting
            }

            else { return false; }

        } //Whole

        return true;
    }
};
