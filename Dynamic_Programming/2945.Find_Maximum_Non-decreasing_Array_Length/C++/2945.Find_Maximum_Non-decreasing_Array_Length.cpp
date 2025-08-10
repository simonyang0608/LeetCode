class Solution {
public:
    int findMaximumLength(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result maximun length)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Prefix-summary vector /////
        vector<long long> prefix_sum((len_nums + 1), 0);

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp((len_nums + 1), 0);

        ///// Previous vector /////
        vector<int> prev_vect((len_nums + 2), 0);


        /*Dynamic-programming based loop traversal with binary-search*/
        ///// Step 1: Record prefix-summary values with vector /////
        for (int record_idx = 1; (record_idx <= len_nums); (record_idx++)) //Whole
        {
            prefix_sum[record_idx] = (prefix_sum[(record_idx - 1)] + nums[(record_idx - 1)]);

        } //Whole

        ///// Step 2: Looped-traversal with recorded prefix-summary vector /////
        for (int prev_idx = 0, last_idx = 1; (last_idx <= len_nums); (last_idx++)) //Whole
        {
            prev_idx = (prev_vect[last_idx] > prev_idx) ? prev_vect[last_idx] : prev_idx; //Keep updating, overwriting

            record_dp[last_idx] = (record_dp[prev_idx] + 1); //Keep updating, overwriting

            int further_idx = (this->binarySearch)(len_nums, prefix_sum, last_idx, prev_idx); //Further index

            prev_vect[further_idx] = last_idx; //Keep updating, overwriting

        } //Whole

        return record_dp[len_nums];
    }


    int binarySearch(const int & len_nums, const vector<long long> & prefix_sum, const int & last_idx, 
                     const int & prev_idx)
    {
        //==========================================================//
        // Input type:                                              //
        //   - const int ref. (length of nums vector)               //
        //   - const vector<long long> ref. (prefix summary vector) //
        //   - const int ref. (last index)                          //
        //   - const int ref. (previous index)                      //
        // Return type:                                             //
        //   - int (further index)                                  //
        //==========================================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = len_nums;

        /*Whole process, flow*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            long long record_diff = ((2 * prefix_sum[last_idx]) - prefix_sum[prev_idx]); //Record differences

            ///// Check if the current differences matched conditions or not /////
            if (prefix_sum[record_mid_ptr] < record_diff) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }
};
