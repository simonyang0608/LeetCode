class Solution {
public:
    long long maxStrength(vector<int> & nums) 
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

        ///// Record zero summary counter /////
        int record_zero_cnter = count(nums.begin(), nums.end(), 0);

        ///// Result maximun product /////
        long long res_max_prod = *max_element(nums.begin(), nums.end());


        /*Recursion-based backtrack loop traversal*/
        if (len_nums == 1) { return res_max_prod; } //Issue, Boundary-case handling

        if (record_zero_cnter == len_nums) { return res_max_prod; } //Issue, Boundary-case handling

        if ((record_zero_cnter == (len_nums - 1)) && (accumulate(nums.begin(), nums.end(), 0) < 0)) { return res_max_prod; } //Issue, Boundary-case handling

        recurseTraversal(nums, len_nums, 0, 1, res_max_prod); //Recursion function call

        return res_max_prod;
    }


    void recurseTraversal(vector<int> & nums, int & len_nums, int record_idx, long long record_prod, long long & res_max_prod)
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<int> ref. (nums vector)          //
        //   - int ref. (length of nums vector)        //
        //   - int (record index)                      //
        //   - long long (record product value)        //
        //   - long long ref. (result maximun product) // 
        // Return type:                                //
        //   - void (no return)                        //
        //=============================================// 
        if (record_idx >= len_nums) //Issue, Boundary-case handling
        {
            ///// Check if the current product value is larger or not /////
            if (record_prod > res_max_prod) { res_max_prod = record_prod; } //Update, Overwrite

            return;
        }

        if (! record_prod) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        recurseTraversal(nums, len_nums, (record_idx + 1), record_prod, res_max_prod); //Recursion function call (i.e. no get)
        recurseTraversal(nums, len_nums, (record_idx + 1), (record_prod * nums[record_idx]), res_max_prod); //Recursion function call (get)
    }
};
