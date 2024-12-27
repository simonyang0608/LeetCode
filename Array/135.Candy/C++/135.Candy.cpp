class Solution {
public:
    int candy(vector<int> & ratings) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (ratings vector)  //
        // Return type:                           //
        //   - int (result minimun summary value) //
        //========================================//

        /*Initialize*/
        ///// Length of ratings vector /////
        int len_ratings = ratings.size();

        ///// Record dynamic-programming (i.e. DP) vector
        vector<int> record_dp(len_ratings, 1);

        ///// Record priority-queue /////
        priority_queue<pair<int, int>> record_pq;

        ///// Record index /////
        int record_idx;


        /*Heap, Priority-queue based loop traversal with recorded dynamic-programming vector*/
        ///// Step 1: Record indexed-value with dynamic-programming vector
        for (int ratings_idx = 0; (ratings_idx < len_ratings); (ratings_idx++)) //Whole
        {
            record_pq.push(make_pair((ratings[ratings_idx] * (-1)), ratings_idx)); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dynamic-programming vector /////
        while (! record_pq.empty()) //Whole
        {
            record_idx = (record_pq.top()).second; //Record index

            ///// Check if the current edges exceed boundary or not /////
            if ((record_idx - 1) >= 0)
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if (ratings[record_idx] > ratings[(record_idx - 1)]) { record_dp[record_idx] = max(record_dp[record_idx], (record_dp[(record_idx - 1)] + 1)); } //Keep updating, overwriting
                else { ; }
            }
            else { ; }

            if ((record_idx + 1) < len_ratings)
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if (ratings[record_idx] > ratings[(record_idx + 1)]) { record_dp[record_idx] = max(record_dp[record_idx], (record_dp[(record_idx + 1)] + 1)); } //Keep updating, overwriting
                else { ; }
            }
            else { ; }

            record_pq.pop(); //Keep updating, popped

        } //Whole

        return accumulate(record_dp.begin(), record_dp.end(), 0);
    }
};
