class Solution {
public:
    int maximumSum(vector<int> & arr) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (arr vector)      //
        // Return type:                           //
        //   - int (result maximun summary value) //
        //========================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record dynamic-programming (i.e. DP) vectors /////
        vector<int> record_dp_left(len_arr, 0), record_dp_right(len_arr, 0);

        ///// Result maximun summary value /////
        int res_max_val = arr[0];


        /*Dynamic-programming based loop traversal with recorded vectors*/
        ///// Step 1: Looped-traversal for the left-half part, indices /////
        record_dp_left[0] = arr[0]; record_dp_right.back() = arr.back(); //Update, Overwrite

        for (int record_idx = 1; (record_idx < len_arr); (record_idx++)) //Whole
        {
            record_dp_left[record_idx] = max(arr[record_idx], (record_dp_left[(record_idx - 1)] + arr[record_idx])); //Keep updating, overwriting

            res_max_val = (record_dp_left[record_idx] > res_max_val) ? record_dp_left[record_idx] : res_max_val; //Keep updating, overwriting

        } //Whole

        ///// Step 2: Looped-traversal for the right-half part, indices /////
        for (int record_idx = (len_arr - 2); (record_idx >= 0); (record_idx--)) //Whole
        {
            record_dp_right[record_idx] = max(arr[record_idx], (record_dp_right[(record_idx + 1)] + arr[record_idx])); //Keep updating, overwriting

        } //Whole

        ///// Step 3: Post-process, Final completions /////
        for (int record_idx = 1; (record_idx < (len_arr - 1)); (record_idx++)) //Whole
        {
            res_max_val = max(res_max_val, (record_dp_left[(record_idx - 1)] + record_dp_right[(record_idx + 1)])); //Keep updating, overwriting

        } //Whole

        return res_max_val;
    }
};
