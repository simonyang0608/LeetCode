class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> & intervals) 
    {
        //=================================================//
        // Input type:                                     //
        //   - vector<vector<int>> ref. (intervals vector) //
        // Return type:                                    //
        //   - vector<vector<int>> (result vector)         //
        //=================================================//

        /*Initialize*/
        /////Length of intervals vector /////
        int len_intervals = intervals.size();

        ///// Sorted operations /////
        sort(intervals.begin(), intervals.end());

        ///// Record previous value /////
        int record_prev_val;

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record vector /////
        vector<int> record_vect(2, (-1));

        ///// Result vector /////
        vector<vector<int>> res_vect;


        /*Greedy-based loop traversal*/
        while (record_trav_ptr < len_intervals) //Whole
        {
            record_vect[0] = (intervals[record_trav_ptr])[0]; //Keep updating, overwriting

            record_prev_val = (intervals[record_trav_ptr])[1]; //Record previous value

            while ((record_trav_ptr + 1) < len_intervals) //Part
            {
                ///// Check if the curret indexed-value matched conditions or not /////
                if (((intervals[(record_trav_ptr + 1)])[0] <= record_prev_val) && ((intervals[(record_trav_ptr + 1)])[1] > record_prev_val))
                {
                    record_prev_val = (intervals[(record_trav_ptr + 1)])[1]; //Keep updating, overwriting
                }

                else if (((intervals[(record_trav_ptr + 1)])[0] <= record_prev_val) && ((intervals[(record_trav_ptr + 1)])[1] <= record_prev_val)) { ; }

                else { break; }

                (record_trav_ptr++); //Keep updating, traversing

            } //Part

            record_vect[1] = record_prev_val; //Keep updating, overwriting

            res_vect.push_back(record_vect); //Keep updating, recording

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_vect;
    }
};
