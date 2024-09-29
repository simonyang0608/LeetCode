class Solution {
public:
    long long maxKelements(vector<int> & nums, int k) 
    {
        //================================================//
        // Input type:                                    //
        //   - vector<int> ref. (nums vector)             //
        //   - int (k-th operations)                      //
        // Return type:                                   //
        //   - long long (result maximun summary counter) //
        //================================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record heap, priority-queue /////
        priority_queue<int> record_pq(begin(nums), end(nums));

        ///// Record value /////
        int record_val;

        ///// Result maximun summary counter /////
        long long res_max_cnter = 0;


        /*Heap, Priority-queue based loop traversal*/
        for (int k_idx = 0; (k_idx < k); (k_idx++)) //K-th operations
        {
            record_val = record_pq.top(); //Record value
            record_pq.pop(); //Keep updating, popping

            res_max_cnter += record_val; //Keep updating, accumulating

            ///// Check if the current indexed-value is divisable by 3 or not /////
            if (! (record_val % 3)) { record_pq.push((record_val / 3)); } //Keep updating, recording
            else { record_pq.push(((record_val / 3) + 1)); } //Keep updating, recording

        } //K-th operations

        return res_max_cnter;
    }
};
