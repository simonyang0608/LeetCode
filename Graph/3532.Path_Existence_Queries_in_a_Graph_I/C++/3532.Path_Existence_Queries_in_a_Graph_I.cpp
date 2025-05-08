class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int> & nums, int maxDiff, vector<vector<int>> & queries) 
    {
        //===============================================//
        // Input type:                                   //
        //   - int (n-th nodes)                          //
        //   - vector<int> ref. (nums vector)            //
        //   - int (maximun difference value)            //
        //   - vector<vector<int>> ref. (queries vector) //
        // Return type:                                  //
        //   - vector<bool> (result vector)              //
        //===============================================//

        /*Initialize*/
        ///// Length of vectors (i.e. nums, queries) /////
        int len_nums = nums.size(), len_queries = queries.size();

        ///// Record vector /////
        vector<int> record_vect(len_nums, 0);

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Result vector /////
        vector<bool> res_vect(len_queries, false);


        /*Disjoint-set based loop traversal with recorded vectors*/
        ///// Step 1: Record indexed-values informations with vector /////
        for (int nums_idx = 1; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current difference matched conditions or not /////
            if ((nums[nums_idx] - nums[(nums_idx - 1)]) > maxDiff) { (record_cnter++); } //Keep updating, accumulating
            else { ; }

            record_vect[nums_idx] = record_cnter; //Keep updating, overwriting

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        for (int queries_idx = 0; (queries_idx < len_queries); (queries_idx++)) //Whole
        {
            ///// Check if the current summary counter matched conditions or not /////
            if (record_vect[(queries[queries_idx])[0]] == record_vect[(queries[queries_idx])[1]])
            {
                res_vect[queries_idx] = true; //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return res_vect;
    }
};
