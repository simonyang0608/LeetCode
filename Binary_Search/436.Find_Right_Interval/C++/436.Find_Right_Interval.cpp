class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>> & intervals) 
    {
        //==================================================//
        // Input type:                                      //
        //   - vector<vector<int>> ref. (intervals vector)  //
        // Return type:                                     //
        //   - vector<int> (result vector)                  //
        //==================================================//

        /*Initialize*/
        ///// Length of intervals vector /////
        int len_intervals = intervals.size();

        ///// Record dictionary, hashmap (i.e. index, rightest-bound) /////
        unordered_map<int, int> record_idx_map, record_rbound_map;

        ///// Sorted operations /////
        vector<vector<int>> sort_intervals = intervals;

        sort(sort_intervals.begin(), sort_intervals.end());

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr, record_right_ptr;

        ///// Record target
        int record_target;

        ///// Result vector /////
        vector<int> res_vect(len_intervals, (-1));


        /*Binary-search based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-positions with dictionary, hashmap /////
        for (int intervals_idx = 0; (intervals_idx < len_intervals); (intervals_idx++)) //Whole
        {
            record_idx_map[(intervals[intervals_idx])[0]] = intervals_idx; //Keep updating, recording

        } //Whole

        ///// Step 2: Record minimized right-bound with dictionary, hashmap /////
        for (int intervals_idx = 0; (intervals_idx < len_intervals); (intervals_idx++)) //Whole
        {
            record_left_ptr = intervals_idx; //Record left pointer
            record_right_ptr = (len_intervals - 1); //Record right pointer

            record_target = (sort_intervals[intervals_idx])[1]; //Record target

            ///// Check if the current target matched conditions or not /////
            if (record_target > (sort_intervals[(len_intervals - 1)])[0])
            { 
                record_rbound_map[(sort_intervals[intervals_idx])[0]] = (-1000001); //Keep updating, recording

                continue;
            }

            record_rbound_map[(sort_intervals[intervals_idx])[0]] = binarySearch(record_left_ptr, record_right_ptr, sort_intervals, record_target); //Keep updating, recording

        } //Whole

        ///// Step 3: Looped-traversal with recorded dictionary, hashmap /////
        for (int intervals_idx = 0; (intervals_idx < len_intervals); (intervals_idx++)) //Whole
        {
            ///// Check if the current right-bound is valid or not ///// 
            if (record_rbound_map[(intervals[intervals_idx])[0]] == (-1000001)) { continue; }

            res_vect[intervals_idx] = record_idx_map[record_rbound_map[(intervals[intervals_idx])[0]]]; //Keep updating, overwriting

        } //Whole

        return res_vect;
    }


    int binarySearch(int & record_left_ptr, int & record_right_ptr, vector<vector<int>> & sort_intervals, int & record_target)
    {
        //========================================================//
        // Input type:                                            //
        //   - int ref. (record left pointer)                     //
        //   - int ref. (record right pointer)                    //
        //   - vector<vector<int>> ref. (sorted intervals vector) //
        //   - int ref. (record target)                           //
        // Return type:                                           //
        //   - int (result minimized right-bound)                 //
        //========================================================//

        /*Initialize*/
        ///// Record pointer (i.e. middle) /////
        int record_mid_ptr;

        /*Whole process, flow*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            ///// Check if the current boundary matched conditions or not /////
            if ((sort_intervals[record_mid_ptr])[0] < record_target) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting

        } //Binary-search

        return (sort_intervals[record_left_ptr])[0];
    }
};
