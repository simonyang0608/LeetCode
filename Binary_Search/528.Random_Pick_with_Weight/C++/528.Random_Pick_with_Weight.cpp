class Solution {
public:
    /*Initialize*/
    ///// Record dynamic-programming (i.e. DP) vector ///// 
    vector<int> record_dp;

    ///// Length of dynamic-programming vector /////
    int len_record_dp;

    ///// Summary of dynamic-programming vector /////
    int sum_dp;

    ///// Random value /////
    int rand_val;

    ///// Record pointers (i.e. left, right, middle) /////
    int record_left_ptr, record_right_ptr, record_mid_ptr;

public:
    Solution(vector<int> & w) 
    {
        //=================================//
        // Input type:                     //
        //   - vector<int> ref. (w vector) //
        // Return type:                    //
        //   - void (no return)            //
        //=================================//

        /*Initialize*/
        ///// Length of dynamic-programming vector /////
        len_record_dp = w.size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        record_dp = w;


        /*Whole process, flow*/
        ///// Record prefix-summary value with dynamic-programming vector /////
        for (int record_idx = 1; (record_idx < len_record_dp); (record_idx++)) //Whole
        {
            record_dp[record_idx] += record_dp[(record_idx - 1)]; //Keep updating, overwriting

        } //Whole

        sum_dp = record_dp.back(); //Summary of dynamic-programming vector
    }
    
    int pickIndex()
    {
        //======================//
        // Input type:          //
        //   - void (no return) //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right, middle) /////
        record_left_ptr = 0;
        record_right_ptr = (len_record_dp - 1);

        ///// Random value /////
        rand_val = (rand() % sum_dp);


        /*Binary-search based loop traversa;*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            ///// Check if the current indexed-value matched conditions or not /////
            if (record_dp[record_mid_ptr] <= rand_val) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
