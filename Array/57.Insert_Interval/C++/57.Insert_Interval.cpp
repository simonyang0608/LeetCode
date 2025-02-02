class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>> & intervals, vector<int> & newInterval) 
    {
        //=================================================//
        // Input type:                                     //
        //   - vector<vector<int>> ref. (intervals vector) //
        //   - vector<int> ref. (newInterval vector)       //
        // Return type:                                    //
        //   - vector<vector<int>> (result vector)         //
        //=================================================//

        /*Initialize*/
        ///// Length of intervals vector /////
        int len_intervals = intervals.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result vector /////
        vector<vector<int>> res_vect;


        /*Greedy-based loop traversal with sorted, updated vector*/
        ///// Step 1: Sorted, Updated vector with new element /////
        intervals.push_back(newInterval); //Update, Record

        (len_intervals++); //Update, Accumulate

        sort(intervals.begin(), intervals.end(), [&](const vector<int> & interval_1, const vector<int> & interval_2)
        {
            return (interval_1[0] < interval_2[0]);

        }); //Sorted-operations

        ///// Step 2: Looped-traversal with sorted, updated vector /////
        while (record_trav_ptr < len_intervals) //Whole
        {
            int fst_val = (intervals[record_trav_ptr])[0]; int scnd_val = (intervals[record_trav_ptr])[1]; //Firts, Second value

            while (((record_trav_ptr + 1) < len_intervals) && ((intervals[(record_trav_ptr + 1)])[0] <= scnd_val)) //Part
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((intervals[(record_trav_ptr + 1)])[1] <= scnd_val) { ; } 
                else { scnd_val = (intervals[(record_trav_ptr + 1)])[1]; } //Keep updating, overwriting

                (record_trav_ptr++); //Keep updating, traversing

            } //Part

            res_vect.push_back({fst_val, scnd_val}); //Keep updating, recording

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_vect;
    }
};
