class Solution {
public:
    long long maximumTripletValue(vector<int> & nums) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums vector)     //
        // Return type:                           //
        //   - long long (result maximun product) //
        //========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dynamic-programming vector (i.e. prefix, suffix) /////
        vector<int> record_prefix_dp_vect(len_nums, 0), record_suffix_dp_vect(len_nums, 0);

        record_prefix_dp_vect[0] = (-1);
        record_prefix_dp_vect[1] = nums[0];

        record_suffix_dp_vect[(len_nums - 1)] = (-1);
        record_suffix_dp_vect[(len_nums - 2)] = nums[(len_nums - 1)];

        ///// Record product /////
        long long record_prod;

        ///// Result maximun product /////
        long long res_max_prod = 0;


        /*Dynamic-programming based loop traversal*/
        ///// Step 1: Record indexed-value with dynamic-programming vector (i.e. prefix, suffix) /////
        for (int nums_idx = 2; (nums_idx < len_nums); (nums_idx++)) //Prefix
        {
            record_prefix_dp_vect[nums_idx] += max(record_prefix_dp_vect[(nums_idx - 1)], nums[(nums_idx - 1)]); //Keep updating, overwriting

        } //Prefix

        for (int nums_idx = (len_nums - 3); (nums_idx >= 0); (nums_idx--)) //Suffix
        {
            record_suffix_dp_vect[nums_idx] += max(record_suffix_dp_vect[(nums_idx + 1)], nums[(nums_idx + 1)]); //Keep updating, overwriting

        } //Suffix

        ///// Step 2: Looped-traversal with recorded dynamic-programming vector (i.e. prefix, suffix) /////
        for (int record_idx = 1; (record_idx < (len_nums - 1)); (record_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[record_idx] >= record_prefix_dp_vect[record_idx]) { continue; }

            record_prod = (((long long)(record_prefix_dp_vect[record_idx]) - (long long)(nums[record_idx])) * (long long)(record_suffix_dp_vect[record_idx])); //Record product

            ///// Check if the current product is larger or not /////
            if (record_prod > res_max_prod) { res_max_prod = record_prod; } //Keep updating, overwriting
            else { ; }
             
        } //Whole

        return res_max_prod;
    }
};
