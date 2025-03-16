class Solution {
public:
    int maximumCandies(vector<int> & candies, long long k) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (candies vector) //
        //   - long long (k-th children)         //
        // Return type:                          //
        //   - int (result maximun candies)      //
        //=======================================//

        /*Initialize*/
        ///// Length of candies vector /////
        int len_candies = candies.size();
        
        ///// Summary of candies vector /////
        long long sum_candies = 0;

        for (int candies_idx = 0; (candies_idx < len_candies); (candies_idx++)) //Whole
        {
            sum_candies += static_cast<long long>(candies[candies_idx]); //Keep updating, accumulating

        } //Whole

        if (sum_candies < k) { return 0; } //Issue, Boundary-case handling

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 1, record_right_ptr = *max_element(candies.begin(), candies.end());


        /*Binary-search based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) / 2); //Record middle pointer

            bool record_flag = canGetAll(len_candies, candies, record_mid_ptr, k); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (record_flag) { record_left_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }


    bool canGetAll(const int & len_candies, const vector<int> & candies, const int & record_val, 
                   const long long & k)
    {
        //===============================================//
        // Input type:                                   //
        //   - const int ref. (length of candies vector) //
        //   - const vector<int> ref. (candies vector)   //
        //   - const int ref. (record value)             //
        //   - const long long ref. (k-th children)      //
        // Return type:                                  //
        //   - bool (result flag)                        //
        //===============================================//

        /*Initialize*/
        ///// Result summary value /////
        long long res_sum_val = 0;

        /*Whole process, flow*/
        for (int candies_idx = 0; (candies_idx < len_candies); (candies_idx++)) //Whole
        {
            res_sum_val += ((candies[candies_idx]) / record_val); //Keep updating, accumulating

            ///// Check if the current summary value is larger than k-th or not /////
            if (res_sum_val >= k) { return true; }

        } //Whole

        return false;
    }
};
