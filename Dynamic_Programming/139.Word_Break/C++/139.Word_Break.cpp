class Solution {
public:
    bool wordBreak(string s, vector<string> & wordDict) 
    {
        //===========================================//
        // Input-type:                               //
        //   - string (s string)                     //
        //   - vector<string> ref. (wordDict vector) //
        // Return type:                              //
        //   - bool (result flag)                    //
        //===========================================//

        /*Initialize*/
        ///// Length of s string, wordDict vector /////
        int len_s = s.size(), len_wordDict = wordDict.size();

        ///// Record dictionary, hashmap /////
        map<string, bool> record_map;

        ///// Record dynamic-programming vector /////
        vector<int> record_dp((len_s + 1), 0);


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int wordDict_idx = 0; (wordDict_idx < len_wordDict); (wordDict_idx++)) //Whole
        {
            record_map[wordDict[wordDict_idx]] = true; //Keep updating, recording

        } //Whole

        for (int record_idx = 1; (record_idx <= len_s); (record_idx++)) //Whole
        {
            record_dp[record_idx] = (record_dp[(record_idx - 1)] + 1); //Keep updating, overwriting

            for (int sub_idx = (record_idx - 1); (sub_idx >= 0); (sub_idx--)) //Part
            {
                string record_str = s.substr(sub_idx, (record_idx - sub_idx)); //Record string

                ///// Check if the current string existed or not /////
                if (record_map[record_str])
                {
                    ///// Check if the current status matched conditions or not /////
                    if (! record_dp[sub_idx]) { record_dp[record_idx] = 0; break; }

                    record_dp[record_idx] = min(record_dp[record_idx], record_dp[sub_idx]); //Keep updating, overwriting
                }

                else { ; }

            } //Part

        } //Whole

        return (! record_dp[len_s]) ? true : false;
    }
};
