class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) 
    {
        //==========================================//
        // Input type:                              //
        //   - striing (text1 string)               //
        //   - string (text2 string)                //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of texts vector (i.e. 1, 2) /////
        int len_text1 = text1.size(), len_text2 = text2.size();

        ///// Record dynamic-programming vectors (i.e. text1, text2) /////
        vector<vector<int>> record_dp((len_text1 + 1), vector<int>((len_text2 + 1), 0));


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int text1_idx = 1; (text1_idx <= len_text1); (text1_idx++)) //Text1
        {
            for (int text2_idx = 1; (text2_idx <= len_text2); (text2_idx++)) //Text2
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if (text1[(text1_idx - 1)] == text2[(text2_idx - 1)])
                {
                    (record_dp[text1_idx])[text2_idx] = ((record_dp[(text1_idx - 1)])[(text2_idx - 1)] + 1); //Keep updating, overwriting
                }
                else { (record_dp[text1_idx])[text2_idx] = max((record_dp[(text1_idx - 1)])[text2_idx], (record_dp[text1_idx])[(text2_idx - 1)]); } //Keep updating, overwriting

            } //Text2

        } //Text1

        return (record_dp[len_text1])[len_text2];
    }
};
