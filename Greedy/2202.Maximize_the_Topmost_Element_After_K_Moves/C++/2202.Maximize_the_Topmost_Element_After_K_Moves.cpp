class Solution {
public:
    int maximumTop(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th operations)          //
        // Return type:                       //
        //   - int (result maximun value)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        if ((len_nums == 1) & ((k % 2))) { return (-1); } //Issue, Boundary-case handling

        if (k > len_nums) { return *max_element(nums.begin(), nums.end()); } //Issue, Boundary-case handling

        ///// Result maximun value /////
        int res_max_val = (-1);


        /*Greedy-based loop traversal*/
        for (int nums_idx = 0; (nums_idx < (k - 1)); (nums_idx++)) //Whole
        {
            res_max_val = max(res_max_val, nums[nums_idx]); //Keep updating, overwriting

        } //Whole

        ///// Check if the current operations times matched conditions or not /////
        if (k < len_nums) { res_max_val = max(res_max_val, nums[k]); } //Keep updating, overwriting
        else { ; }

        return res_max_val;
    }
};
