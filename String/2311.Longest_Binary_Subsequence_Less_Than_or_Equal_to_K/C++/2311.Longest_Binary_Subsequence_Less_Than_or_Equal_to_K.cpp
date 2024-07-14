class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        //==========================================//
        // Input type:                              //
        //   - string (s string)                    //
        //   - int (k-th target)                    //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Reversed operations /////
        reverse(s.begin(), s.end());

        ///// Record summary values /////
        int record_sum_val = 0;

        ///// Result summary counter /////
        int res_cnter = count(s.begin(), s.end(), '0');


        /*Bit-wise manipulations with recorded summary values*/
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (s[s_idx] == '1')
            {
                record_sum_val += (1 << s_idx); //Keep updating, accumulating

                ///// Check if the current summary values exceed boundary or not /////
                if (record_sum_val > k) { return res_cnter; }

                else { (res_cnter++); } //Keep updating, accumulating
            }

            else { ; }

        } //Whole

        return res_cnter;
    }
};
