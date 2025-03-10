class Solution {
public:
    double mincostToHireWorkers(vector<int> & quality, vector<int> & wage, int k) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (quality vector) //
        //   - vector<int> ref. (wage vector)    //
        //   - int (k-th length)                 //
        // Return type:                          //
        //   - double (result minimun value)     //
        //=======================================//

        /*Initialize*/
        ///// Length of vectors (i.e. quality, wage) /////
        int len_total = quality.size();

        ///// Record vector /////
        vector<pair<double, int>> record_vect;

        ///// Record heap, priority-queue /////
        priority_queue<int> record_pq;

        ///// Record summary value /////
        double record_sum = 0;

        ///// Result minimun summary value /////
        double res_min_sum = DBL_MAX;


        /*Heap, Priority-queue based loop traversal with recorded vector*/
        ///// Step 1: Record indexed-informations with vector /////
        for (int record_idx = 0; (record_idx < len_total); (record_idx++)) //Whole
        {
            record_vect.emplace_back((static_cast<double>(wage[record_idx]) / quality[record_idx]), quality[record_idx]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the recorded vector /////
        sort(record_vect.begin(), record_vect.end()); //Sorted-operations

        for (int record_idx = 0; (record_idx < len_total); (record_idx++)) //Whole
        {
            record_sum += (record_vect[record_idx]).second; //Keep updating, accumulating

            record_pq.emplace((record_vect[record_idx]).second); //Keep updating, recording

            ///// Check if the current size exceed k-th or not /////
            if (record_pq.size() > k) { record_sum -= record_pq.top(); record_pq.pop(); } //Keep updating, popped

            if (record_pq.size() == k) { res_min_sum = min(res_min_sum, (record_sum * (record_vect[record_idx]).first)); } //Keep updating, overwriting

            else { ; }

        } //Whole

        return res_min_sum;
    }
};
