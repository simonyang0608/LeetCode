class Solution {
public:
    int minSteps(string s, string t) 
    {
        //=====================================//
        // Input type:                         //
        //   - string (s string)               //
        //   - string (t string)               //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record vector /////
        vector<int> record_vect_s(26, 0);

        ///// Result minimun operations /////
        int res_min_oprs = 0;


        /*String counting-based loop traversal with recorded vector*/
        ///// Step 1: Record indexed-char informations with vector /////
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ((record_vect_s[(s[s_idx] - 'a')])++); //Keep updating, accumulating

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector
        for (int t_idx = 0; (t_idx < len_s); (t_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if ((--(record_vect_s[(t[t_idx] - 'a')])) < 0) { (res_min_oprs++); } //Keep updating, accumulating
            else { ; }

        } //Whole

        return res_min_oprs;
    }
};
