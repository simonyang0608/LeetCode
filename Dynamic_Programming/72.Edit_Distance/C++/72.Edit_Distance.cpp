class Solution {
public:
    int minDistance(string word1, string word2) 
    {
        //=====================================//
        // Input type:                         //
        //   - string (word1 string)           //
        //   - string (word2 string)           //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*initialize*/
        ///// Length of strings (i.e. word1, word2) /////
        int len_word1 = word1.size(), len_word2 = word2.size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<int>> record_dp((len_word1 + 1), vector<int>((len_word2 + 1), 0));


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        ///// Step 1: Record rows, columns with dynamic-programming vector /////
        for (int rows_idx = 1; (rows_idx <= len_word1); (rows_idx++)) //Rows
        {
            (record_dp[rows_idx])[0] = rows_idx; //Keep updating, overwriting

        } //Rows

        for (int cols_idx = 1; (cols_idx <= len_word2); (cols_idx++)) //Columns
        {
            (record_dp[0])[cols_idx] = cols_idx; //Keep updating, overwriting

        } //Columns

        ///// Step 2: Looped-traversal with recorded dynamic-programming vector /////
        for (int rows_idx = 1; (rows_idx <= len_word1); (rows_idx++)) //Rows
        {
            for (int cols_idx = 1; (cols_idx <= len_word2); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-char is the same or not /////
                if ((word1[(rows_idx - 1)] == word2[(cols_idx - 1)])) { (record_dp[rows_idx])[cols_idx] = (record_dp[(rows_idx - 1)])[(cols_idx - 1)]; } //Keep updating, overwriting
                else { (record_dp[rows_idx])[cols_idx] = (min((record_dp[(rows_idx - 1)])[(cols_idx - 1)], min((record_dp[(rows_idx - 1)])[cols_idx], (record_dp[rows_idx])[(cols_idx - 1)])) + 1); } //Keep updating, overwriting

            } //Columns

        } //Rows

        return (record_dp[len_word1])[len_word2];
    }
};
