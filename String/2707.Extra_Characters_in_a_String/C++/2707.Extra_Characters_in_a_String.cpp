class Solution {
public:
    int minExtraChar(string s, vector<string> & dictionary) 
    {
        //=============================================//
        // Input type:                                 // 
        //   - string (s string)                       //
        //   - vector<string> ref. (dictionary vector) //
        // Return type:                                //
        //   - int (result minimun remains)            //
        //=============================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record dynamic-programming vector /////
        vector<int> record_dp((len_s + 1), 0);

        ///// Record set /////
        set<string> record_set(dictionary.begin(), dictionary.end());

        ///// Record string /////
        string record_str;


        /*Dynamic-programming based loop traversal*/
        for (int dp_idx = 1; (dp_idx <= len_s); (dp_idx++)) //Whole
        {
            record_dp[dp_idx] = (record_dp[(dp_idx - 1)] + 1); //Keep updating, overwriting

            for (int record_idx = (dp_idx - 1); (record_idx >= 0); (record_idx--)) //Part
            {
                record_str = s.substr(record_idx, (dp_idx - record_idx)); //Record string

                ///// Check if the current indexed-string existed or not /////
                if (record_set.find(record_str) != record_set.end())
                {
                    record_dp[dp_idx] = min(record_dp[record_idx], record_dp[dp_idx]); //Keep updating, overwriting
                }
                else { ; }

            } //Part

        } //Whole

        return record_dp[len_s];
    }
};
