class Solution {
public:
    int minimumDeletions(string s) 
    {
        //=====================================//
        // Input type:                         //
        //   - string (s string)               //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Greedy-based loop traversal*/
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched ocnditions or not /////
            if (s[s_idx] == 'b') { (record_cnter++); } //Keep updating, accumulating
            else
            {
                if (record_cnter) { (record_cnter--); (res_cnter++); } //Keep updating, accumulating
                else { ; }
            }

        } //Whole

        return res_cnter;
    }
};
