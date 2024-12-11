class Solution {
public:
    vector<bool> isArraySpecial(vector<int> & nums, vector<vector<int>> & queries) 
    {
        //===============================================//
        // Input type:                                   //
        //   - vector<int> ref. (nums vector)            //
        //   - vector<vector<int>> ref. (queries vector) //
        // Return type:                                  //
        //   - vector<bool> (result flag vector)         //
        //===============================================//

        /*Initialize*/
        ///// Length of vectors (i.e. nums, queries) /////
        int len_nums = nums.size(), len_queries = queries.size();

        ///// Record dynamic-programming vector /////
        vector<int> record_dp(len_nums, 0);

        ///// Record query indexes (i.e. left, right) /////
        int record_query_lidx, record_query_ridx;

        ///// Record indexed-char /////
        char record_char = ((nums[0] % 2)) ? 'o' : 'e';

        ///// Result vector /////
        vector<bool> res_vect(len_queries, false);


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        ///// Step 1: Record indexed-value with dynamic-programming vector /////
        for (int nums_idx = 1; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (record_char == 'o')
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if (! (nums[nums_idx] % 2))
                {
                    record_dp[nums_idx] = (record_dp[(nums_idx - 1)] + 1); //Keep updating, overwriting

                    record_char = 'e'; //Keep updating, overwriting
                }
                else { record_dp[nums_idx] = record_dp[(nums_idx - 1)]; } //Keep updating, overwriting
            } 
            
            else if (record_char == 'e')
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((nums[nums_idx] % 2))
                {
                    record_dp[nums_idx] = (record_dp[(nums_idx - 1)] + 1); //Keep updating, overwriting

                    record_char = 'o'; //Keep updating, overwriting
                }
                else { record_dp[nums_idx] = record_dp[(nums_idx - 1)]; } //Keep updating, overwriting
            }

        } //Whole

        ///// Step 2: Looped-traversal wit recorded dynamic-programming vector /////
        for (int queries_idx = 0; (queries_idx < len_queries); (queries_idx++)) //Whole
        {
            record_query_lidx = (queries[queries_idx])[0]; //Record query left indexes
            record_query_ridx = (queries[queries_idx])[1]; ////Record query right indexes

            ///// Check if the current differences matched conditions or not /////
            if ((record_query_ridx - record_query_lidx) != (record_dp[record_query_ridx] - record_dp[record_query_lidx])) { ; }
            else { res_vect[queries_idx] = true; } //Keep updating, overwriting

        } //Whole

        return res_vect;
    }
};
