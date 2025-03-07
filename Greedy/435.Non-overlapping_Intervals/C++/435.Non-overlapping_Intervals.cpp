class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>> & intervals) 
    {
        //=================================================//
        // Input type:                                     //
        //   - vector<vector<int>> ref. (intervals vector) //
        // Return type:                                    //
        //   - int (result summary counter)                //
        //=================================================//

        /*Initialize*/
        ///// Length of intervals vector /////
        int len_intervals = intervals.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Greedy-based loop traversal with sorted-operations*/
        sort(intervals.begin(), intervals.end(), [&](const vector<int> & vect_1, const vector<int> & vect_2)
        {
            return ((vect_1[1] < vect_2[1]));

        }); //Sorted-operations

        while (record_trav_ptr < len_intervals) //Whole
        {
            int first_val = (intervals[record_trav_ptr])[0]; int second_val = (intervals[record_trav_ptr])[1]; //First, Second value

            while (((record_trav_ptr + 1) < len_intervals) && ((intervals[(record_trav_ptr + 1)])[0] == first_val)) //Same first value
            {
                (res_cnter++); (record_trav_ptr++); //Keep updating, traversing

            } //Same first value

            while (((record_trav_ptr + 1) < len_intervals) && ((intervals[(record_trav_ptr + 1)])[0] < second_val)) //Compare first, second value
            {
                (res_cnter++); (record_trav_ptr++); //Keep updating, traversing

            } //Compare first, second value

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_cnter;
    }
};
