class Solution {
public:
    bool increasingTriplet(vector<int> & nums) 
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

        ///// Record minimun values (i.e. 1, 2) /////
        int record_min_val1 = INT_MAX, record_min_val2 = INT_MAX;


        /*Greedy-based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value is less than minimun values or not /////
            if (nums[nums_idx] <= record_min_val1) { record_min_val1 = nums[nums_idx]; } //Keep updating, overwriting

            else if (nums[nums_idx] <= record_min_val2) { record_min_val2 = nums[nums_idx]; } //Keep updating, overwriting
            else { return true; }

        } //Whole

        return false; 
    }
};
