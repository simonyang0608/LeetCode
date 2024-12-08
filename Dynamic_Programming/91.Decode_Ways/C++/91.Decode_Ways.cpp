class Solution {
public:
    int numDecodings(string s) 
    {
        //===============================//
        // Input type:                   //
        //   - string (s string)         //
        // Return type:                  //
        //   - int (result combinations) //
        //===============================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp((len_s + 1), 0);

        record_dp[0] = 1;


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int s_idx = 1; (s_idx <= len_s); (s_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((s[(s_idx - 1)] - '0') != 0)
            {
                record_dp[s_idx] = record_dp[(s_idx - 1)]; //Keep updating, overwriting
            }
            else { ; }

            ///// Check if the current indexed-value matched conditions or not /////
            if ((s_idx > 1) && ((s[(s_idx - 2)] - '0') != 0) && ((((s[(s_idx - 2)] - '0') * 10) + (s[(s_idx - 1)] - '0')) <= 26))
            {
                record_dp[(s_idx)] += record_dp[(s_idx - 2)]; //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return record_dp[len_s];
    }
};
