class Solution {
public:
    int minimumSum(vector<int> & nums) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums vector)     //
        // Return type:                           //
        //   - int (result minimun summary value) //
        //========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dynamic-programming vector (i.e. prefix, suffix) /////
        vector<int> record_dp_prefix_vect(len_nums, 0), record_dp_suffix_vect(len_nums, 0);

        record_dp_prefix_vect[0] = (1e8 + 1);
        record_dp_prefix_vect[1] = nums[0];

        record_dp_suffix_vect[(len_nums - 1)] = (1e8 + 1);
        record_dp_suffix_vect[(len_nums - 2)] = nums[(len_nums - 1)];

        ///// Record pivot /////
        int record_pivot;

        ///// Result minimun summary value /////
        int res_min_sum = (3e8 + 1);


        /*Dynamic-programming based loop traversal*/
        ///// Step 1: Record indexed-value with dynamic-programming vector (i.e. prefix, suffix) /////
        for (int nums_idx = 2; (nums_idx < len_nums); (nums_idx++)) //Prefix
        {
            record_dp_prefix_vect[nums_idx] += min(record_dp_prefix_vect[(nums_idx - 1)], nums[(nums_idx - 1)]); //Keep updating, overwriting

        } //Prefix

        for (int nums_idx = (len_nums - 3); (nums_idx >= 0); (nums_idx--)) //Suffix
        {
            record_dp_suffix_vect[nums_idx] += min(record_dp_suffix_vect[(nums_idx + 1)], nums[(nums_idx + 1)]); //Keep updating, overwriting

        } //Suffix

        ///// Step 2: Looped-traversal with recorded dynamic-programming vector (i.e. prefix, suffix) /////
        for (int record_idx = 1; (record_idx < (len_nums - 1)); (record_idx++)) //Whole
        {
            record_pivot = nums[record_idx]; //Record pivot

            ///// Check if the crrent indexed-value matced conditions or not /////
            if ((record_pivot <= record_dp_prefix_vect[record_idx]) || (record_pivot <= record_dp_suffix_vect[record_idx]))
            {
                continue;
            }

            res_min_sum = min(res_min_sum, (record_pivot + record_dp_prefix_vect[record_idx] + record_dp_suffix_vect[record_idx])); //Keep updating, overwriting

        } //Whole

        return (res_min_sum == (3e8 + 1)) ? (-1) : res_min_sum;
    }
};
