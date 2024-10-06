class Solution {
public:
    int secondsToRemoveOccurrences(string s) 
    {
        //=============================//
        // Input type:                 //
        //   - string (s string)       //
        // Return type:                //
        //   - int (result operations) //
        //=============================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record traversal index /////
        int record_trav_idx = 0;

        ///// Result operations /////
        int res_oprs = 0;


        /*Greedy-based loop traversal*/
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (s[s_idx] == '0') { continue; }

            ///// Check if the current operations matched conditions or not /////
            if (! res_oprs) { res_oprs = (s_idx - record_trav_idx); } //Keep updating, overwriting

            else
            {
                ///// Check if the current operations matched conditions or not /////
                if (res_oprs >= (s_idx - record_trav_idx)) { (res_oprs++); } //Keep updating, accumulating
                else { res_oprs = (s_idx - record_trav_idx); } //Keep updating, overwriting
            }

            (record_trav_idx++); //Keep updating, accumulating

        } //Whole

        return res_oprs;
    }
};
