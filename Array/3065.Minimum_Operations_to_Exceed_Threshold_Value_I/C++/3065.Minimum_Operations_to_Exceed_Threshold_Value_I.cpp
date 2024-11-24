class Solution {
public:
    int minOperations(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (target value)             //
        // Return type:                       //
        //   - int (result summary counter)   //
        //====================================//
        if ((*min_element(nums.begin(), nums.end())) >= k) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Result summary counter /////
        int res_cnter = 0;


        /*One-pass compare based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[nums_idx] < k) { (res_cnter++); } //Keep updating, accumulating
            else { ; }

        } //Whole

        return res_cnter;
    }
};
