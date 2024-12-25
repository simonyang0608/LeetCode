class Solution {
public:
    vector<long long> minOperations(vector<int> & nums, vector<int> & queries) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (nums vector)    //
        //   - vector<int> ref. (queries vector) //
        // Return type:                          //
        //   - vector<long long> (result vector) //
        //=======================================//

        /*Initialize*/
        ///// Length of vectors (i.e. nums queries) /////
        int len_nums = nums.size(), len_queries = queries.size();

        ///// Sorted operations /////
        sort(nums.begin(), nums.end());

        ///// Record dynamic-programmig (i.e. DP) vector /////
        vector<long long> record_dp((len_nums + 1), 0);

        ///// Record index /////
        int record_idx;

        ///// Result vector /////
        vector<long long> res_vect(len_queries, 0);


        /*Binary-search based loop traversal with recorded dynamic-programming (i.e. DP) vector*/
        ///// Step 1: Record prefix-summary value with dynamic-programming vector /////
        for (int record_idx = 1; (record_idx < record_dp.size()); (record_idx++)) //Whole
        {
            record_dp[record_idx] = (record_dp[(record_idx - 1)] + nums[(record_idx - 1)]); //Keep updating, overwriting
             
        } //Whole

        ///// Step 2: Looped-traversal with recorded dynamic-programming vector /////
        for (int queries_idx = 0; (queries_idx < len_queries); (queries_idx++)) //Whole
        {
            record_idx = binarySearch(nums, len_nums, queries[queries_idx]); //Binary-search function call

            res_vect[queries_idx] = ((((long long)(queries[queries_idx]) * record_idx) - record_dp[record_idx]) + ((record_dp.back() - record_dp[record_idx]) - ((long long)(queries[queries_idx]) * (len_nums - record_idx)))); //Keep updating, overwriting

        } //Whole

        return res_vect;
    }


    int binarySearch(vector<int> & nums, int & len_nums, int & record_val)
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (nums vector)   //
        //   - int ref. (length of nums vector) //
        //   - int ref. (record value)          //
        // Return type:                         //
        //   - int (result index)               //
        //======================================//

        /*Initialize*/
        ///// Record pointers (i.e. middle, left, right) /////
        int record_mid_ptr, record_left_ptr = 0, record_right_ptr = (len_nums - 1);

        /*Whole process, flow*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Keep updating, overwriting

            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[record_mid_ptr] < record_val) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

            else if (nums[record_mid_ptr] > record_val) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { return record_mid_ptr; }

        } //Binary-search

        return record_left_ptr;
    }
};
