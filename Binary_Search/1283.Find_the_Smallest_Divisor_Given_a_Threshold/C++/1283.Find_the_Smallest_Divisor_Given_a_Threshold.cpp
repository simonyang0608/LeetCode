class Solution {
public:
    int smallestDivisor(vector<int> & nums, int threshold) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (threshold value)          //
        // Return type:                       //
        //   - int (result divisor value)     //
        //====================================//

        /*Initialize*/
        ///// Lenght of nums vector /////
        int len_nums = nums.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 1, record_right_ptr = *max_element(nums.begin(), nums.end());


        /*Binary-search based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            bool record_flag = isLargeThreshold(len_nums, nums, record_mid_ptr, threshold); //Record flag

            ///// Check if the current flag is larger than threshold or not /////
            if (record_flag) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }


    bool isLargeThreshold(const int & len_nums, const vector<int> & nums, const int & record_val, 
                         const int & threshold)
    {
        //============================================//
        // Input type:                                //
        //   - const int ref. (length of nums vector) //
        //   - const vector<int> ref. (nums vector)   //
        //   - const int ref. (record value)          //
        //   - const int ref. (threshold value)       //
        // Return type:                               //
        //   - bool (result flag)                     //
        //============================================//

        /*Initialize*/
        ///// Result summary value /////
        long long res_sum_val = 0;

        /*Whole process, flow*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            int record_quot = (nums[nums_idx] / record_val); int record_mod = (nums[nums_idx] % record_val); //Record quotient, module

            ///// Check if the current module is 0 or not /////
            if (record_mod) { res_sum_val += (record_quot + 1); } //Keep updating, accumulating
            else { res_sum_val += record_quot; } //Keep updating, accumulating

            if (res_sum_val > threshold) { return true; }

        } //Whole

        return false;
    }
};
