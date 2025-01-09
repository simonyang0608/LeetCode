class Solution {
public:
    long long totalCost(vector<int> & costs, int k, int candidates) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (costs vector)  //
        //   - int (k-th operations)            //
        //   - int (number of candidates)       //
        // Return type:                         //
        //   - long long (result minimun costs) //
        //======================================//

        /*Initialize*/
        ///// Length of costs vector /////
        int len_costs = costs.size();

        ///// Record heap, priority-queues (i.e. left, right) /////
        priority_queue<pair<int, int>> record_pq_left, record_pq_right;

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_costs - 1);

        ///// Result minimun costs /////
        long long res_min_costs = 0;


        /*Two-pointers based loop traversal with recorded heap, priority-queue*/
        for (int k_idx = 0; (k_idx < k); (k_idx++)) //K-th
        {
            while ((record_left_ptr <= record_right_ptr) && (record_pq_left.size() < candidates)) //Left-half
            {
                record_pq_left.push(make_pair((costs[record_left_ptr] * (-1)), (record_left_ptr * (-1)))); //Keep updating, recording

                (record_left_ptr++); //Keep updating, traversing

            } //Left-half

            while ((record_right_ptr >= record_left_ptr) && (record_pq_right.size() < candidates)) //Right-half
            {
                record_pq_right.push(make_pair((costs[record_right_ptr] * (-1)), (record_right_ptr * (-1)))); //Keep updating, recording

                (record_right_ptr--); //Keep updating, traversing

            } //Right-half

            int record_left_val = (record_pq_left.empty()) ? (1e5 + 1) : ((record_pq_left.top()).first * (-1)); //Record left-value
            int record_right_val = (record_pq_right.empty()) ? (1e5 + 1) : ((record_pq_right.top()).first * (-1)); //Record right-value

            ///// Check if the right-half value is smaller or not /////
            if (record_right_val < record_left_val) { res_min_costs += record_right_val; record_pq_right.pop(); } //Keep updating, accumulating
            else { res_min_costs += record_left_val; record_pq_left.pop(); } //Keep updating, accumulating

        } //K-th

        return res_min_costs;
    }
};
