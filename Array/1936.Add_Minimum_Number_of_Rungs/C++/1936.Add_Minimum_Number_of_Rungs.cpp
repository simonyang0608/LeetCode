class Solution {
public:
    int addRungs(vector<int> & rungs, int dist) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (rungs vector) //
        //   - int (dist value)                //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//
        rungs.insert(rungs.begin(), 0); //Updated rungs vector

        /*Initialize*/
        ///// Length of rungs vector /////
        int len_rungs = rungs.size();
        (len_rungs--);

        ///// Record differences /////
        int record_diff;

        ///// Record cycled-times, remainings /////
        int record_times, record_remains;

        ///// Result minimun operations /////
        int res_min_oprs = 0;


        /*Greedy-based loop traversal*/
        for (int rungs_idx = 0; (rungs_idx < len_rungs); (rungs_idx++)) //Whole
        {
            record_diff = (rungs[(rungs_idx + 1)] - rungs[rungs_idx]); //Record differences

            record_times = (record_diff / dist); //Record cycled-times
            record_remains = (record_diff % dist); //Record remainings

            ///// Check if the current remainings matched conditions or not /////
            if (record_remains) { res_min_oprs += record_times; } //Keep updating, accumulating
            else { res_min_oprs += (record_times - 1); } //Keep updating, accumulating

        } //Whole

        return res_min_oprs;
    }
};
