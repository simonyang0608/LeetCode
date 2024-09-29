class Solution {
public:
    int minStoneSum(vector<int> & piles, int k) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (piles vector)      //
        //   - int (k-th operations)                //
        // Return type:                             //
        //   - int (result minimun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Record heap, priority-queue /////
        priority_queue<int> record_pq(begin(piles), end(piles));

        ///// Record maximun value /////
        int record_max_val;

        ///// Result minimun summary counter /////
        int res_min_cnter = accumulate(piles.begin(), piles.end(), 0);


        /*Heap, Priority-queue based loop traversal*/
        for (int k_idx = 0; (k_idx < k); (k_idx++)) //K-th operations
        {
            record_max_val = record_pq.top(); //Record maximun value
            record_pq.pop(); //Keep updating, popping

            record_pq.push((record_max_val - (record_max_val / 2))); //Keep updating, recording

            res_min_cnter -= (record_max_val / 2); //Keep updating, reducing

        } //K-th operations

        return res_min_cnter;
    }
};
