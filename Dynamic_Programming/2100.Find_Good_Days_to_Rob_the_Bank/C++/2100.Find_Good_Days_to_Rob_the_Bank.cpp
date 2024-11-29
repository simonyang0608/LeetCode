class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int> & security, int time) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (security vector) //
        //   - int (time)                         //
        // Return type:                           //
        //   - vector<int> (result vector)        //
        //========================================//

        /*Initialize*/
        //// Length of security vector /////
        int len_security = security.size();

        ///// Record dynamic-programming vector (i.e. decrease, increase) /////
        vector<int> record_decr_dp(len_security, 1), record_incr_dp(len_security, 1);

        ///// Result vector /////
        vector<int> res_vect;


        /*Dynamic-programming based loop traversal*/
        (len_security--); //Update, Reduce

        for (int decr_dp_idx = 0; (decr_dp_idx < len_security); (decr_dp_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (security[decr_dp_idx] >= security[(decr_dp_idx + 1)])
            {
                record_decr_dp[(decr_dp_idx + 1)] = (record_decr_dp[decr_dp_idx] + 1); //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        for (int incr_dp_idx = len_security; (incr_dp_idx > 0); (incr_dp_idx--)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (security[incr_dp_idx] >= security[(incr_dp_idx - 1)])
            {
                record_incr_dp[(incr_dp_idx - 1)] = (record_incr_dp[incr_dp_idx] + 1); //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        for (int security_idx = 0; (security_idx <= len_security); (security_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((record_decr_dp[security_idx] > time) && (record_incr_dp[security_idx] > time))
            {
                res_vect.emplace_back(security_idx); //Keep updating, recording
            }
            else { ; }

        } //Whole

        return res_vect;
    }
};
