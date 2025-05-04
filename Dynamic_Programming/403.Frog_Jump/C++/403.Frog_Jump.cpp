class Solution {
public:
    bool canCross(vector<int> & stones) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (stones vector) //
        // Return type:                         //
        //   - bool (result flag)               //
        //======================================//

        /*Initialize*/
        ///// Length of stones vector /////
        int len_stones = stones.size();

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp(len_stones, 0);

        ///// Record dictionary, hashmap /////
        unordered_map<int, unordered_set<int>> record_map;

        ///// Record index /////
        int record_idx = 0;


        /*Dynamic-programming based loop traversal with recorded dictionary, hashmap*/
        (record_map[0]).insert(0); //Update, Record

        for (int stones_idx = 1; (stones_idx < len_stones); (stones_idx++)) //Whole
        {
            while ((record_dp[record_idx] + 1) < (stones[stones_idx] - stones[record_idx])) //Part
            {
                (record_idx++); //Keep updating, traversing

            } //Part

            for (int sub_idx = record_idx; (sub_idx < stones_idx); (sub_idx++)) //Part
            {
                int record_diff = (stones[stones_idx] - stones[sub_idx]); //Record difference

                ///// Check if the current index informations matched conditions or not /////
                if ((record_map[sub_idx]).count((record_diff - 1)) || (record_map[sub_idx]).count(record_diff) || (record_map[sub_idx]).count((record_diff + 1)))
                {
                    (record_map[stones_idx]).insert(record_diff); //Keep updating, recording

                    record_dp[stones_idx] = max(record_dp[stones_idx], record_diff); //Keep updating, overwriting
                }
                else { ; }
            }

        } //Whole

        return record_dp.back();
    }
};
