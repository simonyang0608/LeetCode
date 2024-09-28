class Solution {
public:
    int maxProduct(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result maximun product)   //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Current maximun product /////
        int curr_max_prod;

        ///// Record maximun, minimun product /////
        int record_max_prod = nums[0], record_min_prod = nums[0];

        ///// Result maximun product /////
        int res_max_prod = record_max_prod;


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int nums_idx = 1; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            curr_max_prod = max(max((record_min_prod * nums[nums_idx]), nums[nums_idx]), (record_max_prod * nums[nums_idx])); //Keep updating, overwriting

            record_min_prod = min(min((record_min_prod * nums[nums_idx]), nums[nums_idx]), (record_max_prod * nums[nums_idx])); //Keep updating, overwriting

            record_max_prod = curr_max_prod; //Keep updating, overwriting

            res_max_prod = max(res_max_prod, record_max_prod); //Keep updating, overwriting

        } //Whole

        return res_max_prod;
    }
};
