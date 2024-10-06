class Solution {
public:
    int maxEvents(vector<vector<int>> & events) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (events vector) //
        // Return type:                                 //
        //   - int (result maximun summary counter)     //
        //==============================================//

        /*Initialize*/
        ///// Length of events vector /////
        int len_events = events.size();

        ///// Sorted operations /////
        sort(events.begin(), events.end());

        ///// Record values (i.e. minimun, maximun) /////
        int record_min_val = (events[0])[0], record_max_val = 0;

        for (int events_idx = 0; (events_idx < len_events); (events_idx++))
        {
            record_max_val = max(record_max_val, max((events[events_idx])[0], (events[events_idx])[1]));
        }

        ///// Record traversal index /////
        int record_trav_idx = 0;

        ///// Record heap, priority-queue /////
        priority_queue<int, vector<int>, greater<int>> record_pq;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Greedy-based loop traversal*/
        for (int val_idx = record_min_val; (val_idx <= record_max_val); (val_idx++)) //Whole
        {
            while ((record_trav_idx < len_events) && ((events[record_trav_idx])[0] == val_idx)) //Part
            {
                record_pq.push((events[record_trav_idx])[1]); //Keep updating, recording

                (record_trav_idx++); //Keep updating, accumulating

            } //Part

            while ((! record_pq.empty()) && (record_pq.top() < val_idx)) //Part
            {
                record_pq.pop(); //Keep updating, popping

            } //Part

            ///// Check if the current priority-queue matched conditions or not /////
            if (! record_pq.empty())
            {
                record_pq.pop(); //Keep updating, popping

                (res_max_cnter++); //Keep updating, accumulating
            }
            else { ; }

        } //Whole

        return res_max_cnter;
    }
};
