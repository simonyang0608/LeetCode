class Solution {
public:
    long long pickGifts(vector<int> & gifts, int k) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (gifts vector)  //
        //   - int (k-th operations)            //
        // Return type:                         //
        //   - long long (result summary value) //
        //======================================//

        /*Initialize*/
        ///// Length of gifts vector /////
        int len_gifts = gifts.size();

        ///// Record head, priority-queue /////
        priority_queue<int> record_pq(begin(gifts), end(gifts));

        ///// Record maximun value /////
        int record_max_val;

        ///// Record squart-of maximun value /////
        int record_sqrt_max_val;

        ///// Record operations counter /////
        int record_oprs_cnter = 0;

        ///// Result summary value /////
        long long res_sum_val = 0;

        for (int gifts_idx = 0; (gifts_idx < len_gifts); (gifts_idx++))
        {
            res_sum_val += gifts[gifts_idx];
        }


        /*Heap, Priority-queue based loop traversal*/
        while (record_oprs_cnter < k) //K-th operations
        {
            record_max_val = record_pq.top(); //Record maximun value
            record_sqrt_max_val = sqrt(record_max_val); //Record squart-of maximun value

            res_sum_val -= (record_max_val - record_sqrt_max_val); //Keep updating, reducing

            record_pq.pop(); //Keep updating, popping

            record_pq.push(record_sqrt_max_val); //Keep updating, recording

            (record_oprs_cnter++); //Keep updating, accumulating

        } //K-th operations

        return res_sum_val;
    }
};
