class Solution {
public:
    int bestTeamScore(vector<int> & scores, vector<int> & ages) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (scores vector)   //
        //   - vector<int> ref. (ages vector)     //
        // Return type:                           //
        //   - int (result maximun summary score) //
        //========================================//

        /*Initialize*/
        ///// Length of totals /////
        int len_total = scores.size();

        ///// Record vector /////
        vector<pair<int, int>> record_vect;

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp(len_total, 0);

        ///// Result maximun summary score /////
        int res_max_score = 0;


        /*Dynamic-programming based loop traversal*/
        ///// Step 1: Record personal informations with vector /////
        for (int total_idx = 0; (total_idx < len_total); (total_idx++)) //Whole
        {
            record_vect.emplace_back(ages[total_idx], scores[total_idx]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        sort(record_vect.begin(), record_vect.end()); //Sorted operations
    
        for (int total_idx = 0; (total_idx < len_total); (total_idx++)) //Whole
        {
            record_dp[total_idx] = (record_vect[total_idx]).second; //Keep updating, overwriting

            for (int sub_idx = 0; (sub_idx < total_idx); (sub_idx++)) //Part
            {
                ///// Check if the current score matched conditions or not /////
                if ((record_vect[sub_idx]).second <= (record_vect[total_idx]).second)
                {
                    record_dp[total_idx] = max(record_dp[total_idx], (record_dp[sub_idx] + (record_vect[total_idx]).second)); //Keep updating, overwriting
                }
                else { ; }

            } //Part

            res_max_score = (record_dp[total_idx] > res_max_score) ? record_dp[total_idx] : res_max_score; //Keep updating, overwriting

        } //Whole

        return res_max_score;
    }
};
