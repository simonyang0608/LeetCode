class Solution {
public:
    vector<int> avoidFlood(vector<int> & rains) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (rains vector) //
        // Return type:                        //
        //   - vector<int> (result vector)     //
        //=====================================//

        /*Initialize*/
        ///// Length of rains vector /////
        int len_rains = rains.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record set /////
        set<int> record_set;

        ///// Result vector /////
        vector<int> res_vect(len_rains, (-1));


        /*Greedy-based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Looped-traversal for the main-process /////
        for (int rains_idx = 0; (rains_idx < len_rains); (rains_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (! rains[rains_idx]) { record_set.insert(rains_idx); } //Keep updating, recording
            else
            {
                ///// Check if the current indexed-value existed or not /////
                if (record_map.find(rains[rains_idx]) == record_map.end()) { record_map[rains[rains_idx]] = rains_idx; } //Keep updating, recording
                else
                {
                    auto ub_ptr = record_set.upper_bound(record_map[rains[rains_idx]]); //Upper-bound value

                    ///// Check if the current upper-bounds existed or not /////
                    if (ub_ptr == record_set.end()) { return {}; }

                    res_vect[(*ub_ptr)] = rains[record_map[rains[rains_idx]]]; //Keep updating, overwriting

                    record_map[rains[rains_idx]] = rains_idx; //Keep updating, recording

                    record_set.erase(ub_ptr); //Keep updating, deleting
                }
            }

        } //Whole

        ///// Step 2: Looped-traversal for the minor-process /////
        for (auto record_ptr = record_set.cbegin(); (record_ptr != record_set.cend()); (record_ptr++)) //Whole
        {
            res_vect[(*record_ptr)] = 1; //Keep updating, overwriting

        } //Whole

        return res_vect;
    }
};
