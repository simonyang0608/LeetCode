class Solution {
public:
    int lengthOfLIS(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result length)            //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Result vector /////
        vector<int> res_vect = {nums[0]};


        /*Binary-search based loop traversal*/
        for (int nums_idx = 1; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[nums_idx] > res_vect.back()) { res_vect.emplace_back(nums[nums_idx]); } //Keep updating, recording
            else
            {
                res_vect[binary_search(res_vect, nums[nums_idx])] = nums[nums_idx]; //Keep updating, overwriting
            }

        } //Whole

        return res_vect.size();
    }


    int binary_search(vector<int> & res_vect, int & record_val)
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (result vector) //
        //   - int ref. (record value)          //
        // Return type:                         //
        //   - int (result index)               //
        //======================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right, middle) /////
        int record_mid_ptr, record_left_ptr = 0, record_right_ptr = (res_vect.size() - 1);

        /*Whole process, flow*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            ///// Check if the current indexed-value matched conditions or not /////
            if (record_val <= res_vect[record_mid_ptr]) { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }
};
