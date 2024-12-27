class Solution {
public:
    int lenLongestFibSubseq(vector<int> & arr) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (arr vector)        //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record dictionary, hashmap /////
        map<int, int> record_map;

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<int>> record_dp(len_arr,vector<int>(len_arr, 2));

        ///// Record difference value /////
        int record_diff_val;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Dynamic-programming based loop traversal with recorded dictionary, hashmap*/
        record_map[arr[0]] = 0; record_map[arr[1]] = 1; //Update, Overwrite

        for (int arr_idx = 2; (arr_idx < len_arr); (arr_idx++)) //Whole
        {
            record_map[arr[arr_idx]] = arr_idx; //Keep updating, recording

            for (int sub_arr_idx = 0; (sub_arr_idx < arr_idx); (sub_arr_idx++)) //Part
            {
                record_diff_val = (arr[arr_idx] - arr[sub_arr_idx]); //Keep updating, overwriting

                ///// Check if the current difference value existed or not /////
                if (record_map.find(record_diff_val) != record_map.end())
                {
                    ///// Check if the current difference value matched conditions or not /////
                    if (arr[sub_arr_idx] > record_diff_val) { (record_dp[arr_idx])[sub_arr_idx] = ((record_dp[sub_arr_idx])[record_map[record_diff_val]] + 1); } //Keep updating, overwriting
                    else { ; } //Keep updating, overwriting

                    res_max_cnter = max(res_max_cnter, (record_dp[arr_idx])[sub_arr_idx]); //Keep updating, overwriting
                }
                else { ; }

            } //Part

        } //Whole

        return (res_max_cnter == 2) ? 0 : res_max_cnter;
    }
};
