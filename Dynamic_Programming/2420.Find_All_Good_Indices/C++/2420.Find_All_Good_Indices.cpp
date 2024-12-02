class Solution {
public:
    vector<int> goodIndices(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th elements)            //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dynamic-programming vector (i.e. increase, decrease) /////
        vector<int> record_incr_dp_vect(len_nums, 1), record_decr_dp_vect(len_nums, 1);

        ///// Result vector /////
        vector<int> res_vect;


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int record_decr_idx = 1; (record_decr_idx < len_nums); (record_decr_idx++)) //Decrease
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[record_decr_idx] <= nums[(record_decr_idx - 1)])
            {
                record_decr_dp_vect[record_decr_idx] = (record_decr_dp_vect[(record_decr_idx - 1)] + 1); //Keep updating, overwriting
            }
            else { ; }

        } //Decrease

        for (int record_incr_idx = (len_nums - 1); (record_incr_idx > 0); (record_incr_idx--)) //Increase
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[record_incr_idx] >= nums[(record_incr_idx - 1)])
            {
                record_incr_dp_vect[(record_incr_idx - 1)] = (record_incr_dp_vect[(record_incr_idx)] + 1); //Keep updating, overwriting
            }
            else { ; }

        } //Increase

        for (int record_idx = 1; (record_idx < (len_nums - 1)); (record_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((record_incr_dp_vect[(record_idx + 1)] >= k) && (record_decr_dp_vect[(record_idx - 1)] >= k))
            {
                res_vect.emplace_back(record_idx); //Keep updating, recording
            }
            else { ; }

        } //Whole

        return res_vect;
    }
};
