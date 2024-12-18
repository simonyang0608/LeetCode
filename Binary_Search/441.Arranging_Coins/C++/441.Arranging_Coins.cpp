class Solution {
public:
    int arrangeCoins(int n) 
    {
        //========================//
        // Input type:            //
        //   - int (n-th coins)   //
        // Return type:           //
        //   - int (result steps) //
        //========================//

        /*Initialize*/
        ///// Record pointers (i.e. middle, left, right) /////
        long long record_mid_ptr, record_left_ptr = 1, record_right_ptr = n;

        ///// Result steps /////
        int res_step;


        /*Binary-search based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            ///// Check if the current indexed-pointer matched conditions or not /////
            if (((record_mid_ptr * (record_mid_ptr + 1)) / 2) <= n) { res_step = record_mid_ptr; record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

        } //Binary-search

        return res_step;
    }
};
