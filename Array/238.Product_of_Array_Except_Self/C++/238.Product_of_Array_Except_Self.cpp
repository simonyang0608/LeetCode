class Solution {
public:
    vector<int> productExceptSelf(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record vector (i.e. prefix, suffix) /////
        vector<int> record_prefix_vect = nums, record_suffix_vect = nums;

        ///// Result vector /////
        vector<int> res_vect(len_nums, 0);


        /*Prefix, Suffix-product based loop traversal*/
        ///// Step 1: Record prefix, suffix-product with vector /////
        for (int nums_idx = 1; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_prefix_vect[nums_idx] *= record_prefix_vect[(nums_idx - 1)]; //Keep updating, overwriting
            record_suffix_vect[((len_nums - 1) - nums_idx)] *= record_suffix_vect[(len_nums - nums_idx)]; //Keep updating, overwriting

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        record_prefix_vect.insert(record_prefix_vect.begin(), 1); //Update, Insert
        record_suffix_vect.emplace_back(1); //Update, Append

        for (int record_idx = 0; (record_idx < len_nums); (record_idx++)) //Whole
        {
            res_vect[record_idx] += (record_prefix_vect[record_idx] * record_suffix_vect[(record_idx + 1)]); //Keep updating, overwriting
             
        } //Whole

        return res_vect;
    }
};
