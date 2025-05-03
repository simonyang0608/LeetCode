class Solution {
public:
    long long mostPoints(vector<vector<int>> & questions) 
    {
        //=================================================//
        // Input type:                                     //
        //   - vector<vector<int>> ref. (questions vector) //
        // Return type:                                    //
        //   - long long (result maximun score)            //
        //=================================================//

        /*Initialize*/
        ///// Length of questions vector /////
        int len_questions = questions.size();

        ///// Record dynamic-programming vector /////
        vector<long long> record_dp(len_questions, 0);


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int questions_idx = (len_questions - 1); (questions_idx >= 0); (questions_idx--)) //Whole
        {
            record_dp[questions_idx] += (questions[questions_idx])[0]; //Keep updating, accumulating

            int next_idx = (questions_idx + (questions[questions_idx])[1] + 1); //Next index

            ///// Check if the next index exceed boundary or not /////
            if (next_idx >= len_questions) { ; }
            else { record_dp[questions_idx] += record_dp[next_idx]; } //Keep updating, accumulating

            ///// Check if the current index matched conditions or not /////
            if (questions_idx < (len_questions - 1))
            {
                record_dp[questions_idx] = max(record_dp[questions_idx], record_dp[(questions_idx + 1)]); //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return record_dp[0];
    }
};
