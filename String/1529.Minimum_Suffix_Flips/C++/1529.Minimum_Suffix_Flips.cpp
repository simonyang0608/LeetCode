class Solution {
public:
    int minFlips(string target) 
    {
        //=====================================//
        // Input type:                         //
        //   - string (target string)          //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Length of target string /////
        int len_target = target.size();

        ///// Record indexed-char /////
        char record_char = '0';

        ///// Result minimun operations /////
        int res_min_oprs = 0;


        /*Greedy-based loop traversal with recorded indexed-char*/
        for (int target_idx = 0; (target_idx < len_target); (target_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (target[target_idx] != record_char)
            {
                (res_min_oprs++); //Keep updating, accumulating

                record_char = target[target_idx]; //Keep updating, overwriting
            }

            else { ; }

        } //Whole

        return res_min_oprs;
    }
};
