class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> & rides) 
    {
        //================================================//
        // Input type:                                    //
        //   - int (n-th points)                          //
        //   - vector<vector<int>> ref. (rides vector)    //
        // Return type:                                   //
        //   - long long (result maximun summary counter) //
        //================================================//

        /*Initialize*/
        ///// Length of rides vector /////
        int len_rides = rides.size();

        ///// Record n-th points /////
        (n++);

        ///// Record rides position /////
        vector<int> record_pos;

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<pair<int, int>>> record_map;

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<long long> record_dp(n, 0);

        ///// Record maximun summary counter /////
        long long record_max_cnter = 0;


        /*Dynamic-programming (i.e. DP) based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-value with dictionary, hashmap /////
        for (int rides_idx = 0; (rides_idx < len_rides); (rides_idx++)) //Whole
        {
            record_pos = rides[rides_idx]; //Record rides position

            ///// Check if the current indexed-value existed or not /////
            if (record_map.find(record_pos[1]) == record_map.end())
            {
                record_map[record_pos[1]] = {make_pair(record_pos[0], ((record_pos[1] - record_pos[0]) + record_pos[2]))}; //Keep updating, recording
            }

            else
            {
                record_map[record_pos[1]].push_back(make_pair(record_pos[0], ((record_pos[1] - record_pos[0]) + record_pos[2]))); //Keep updating, recording
            }

        } //Whole

        ///// Step 2: Looped-traversal with recorded hashmap /////
        for (int n_idx = 1; (n_idx < n); (n_idx++)) //Whole
        {
            record_dp[n_idx] = record_dp[(n_idx - 1)]; //Keep updating, overwriting

            ///// Check if the current indexed-value existed or not /////
            if (record_map.find(n_idx) != record_map.end())
            {
                for (pair<int, int> sub_pair: record_map[n_idx]) //Whole
                {
                    record_max_cnter = ((sub_pair.second + record_dp[sub_pair.first]) > record_max_cnter) ? (sub_pair.second + record_dp[sub_pair.first]) : record_max_cnter; //Keep updating, overwriting

                } //Whole

                record_dp[n_idx] = (record_max_cnter > record_dp[n_idx]) ? record_max_cnter : record_dp[n_idx]; //Keep updating, overwriting
            }
            else { ; }

            ///// Check if the current summary counter need to be reset or not /////
            if (record_max_cnter) { record_max_cnter &= 0; } //Keep updating, reset
            else { ; }

        } //Whole

        return record_dp.back();
    }
};
