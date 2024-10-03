class Solution {
public:
    int minOperations(vector<int> & nums, int k) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums vector)  //
        //   - int (target threshold)          //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Record heap, priority-queue /////
        priority_queue<long long, vector<long long>, greater<long long>> record_pq(begin(nums), end(nums));

        ///// Record minimun values (i.e. 1st, 2nd) /////
        long long record_min_val1, record_min_val2;

        ///// Result minimun operations /////
        int res_min_oprs = 0;


        /*Heap, Priority-queue based loop traversal*/
        while (record_pq.size() >= 2) //Part
        {
            record_min_val1 = record_pq.top(); //Record minimun value (i.e. 1st)

            ///// Check if the current minimun value exceed threshold or not /////
            if (record_min_val1 >= k) { break; }

            record_pq.pop(); //Keep updating, popping

            record_min_val2 = record_pq.top(); //Record minimun value (i.e. 2nd)

            record_pq.pop(); //Keep updating, popping

            record_pq.push(((min(record_min_val1, record_min_val2) * 2) + max(record_min_val1, record_min_val2))); //Keep updating, recording

            (res_min_oprs++); //Keep updating, accumulating

        } //Part

        return res_min_oprs;
    }
};
