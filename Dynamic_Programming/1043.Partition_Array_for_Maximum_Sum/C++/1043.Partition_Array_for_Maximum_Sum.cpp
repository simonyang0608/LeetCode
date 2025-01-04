class Solution {
public:
    int maxSumAfterPartitioning(vector<int> & arr, int k) 
    {
        //===================================//
        // Input type:                       //
        //   - vector<int> ref. (arr vector) //
        //   - int (k-th order)              //
        // Retuurn type:                     //
        //   - int (result maximun score)    //
        //===================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        if (len_arr < 2) { return arr[0]; } //Issue, Boundary-case handling

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp((len_arr + 1), 0);


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int record_idx = 1; (record_idx <= len_arr); (record_idx++)) //Whole
        {
            int record_max_val = 0; //Record maximun value

            for (int sub_record_idx = 1; ((sub_record_idx <= k) && ((record_idx - sub_record_idx) >= 0)); (sub_record_idx++)) //Part
            {
                record_max_val = max(record_max_val, arr[(record_idx - sub_record_idx)]); //Keep updating, overwriting

                record_dp[record_idx] = max(record_dp[record_idx], (record_dp[(record_idx - sub_record_idx)] + (record_max_val * sub_record_idx))); //Keep updating, overwriting

            } //Part

        } //Whole

        return record_dp[len_arr];
    }
};
