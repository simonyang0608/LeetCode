class Solution {
public:
    int findKthLargest(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th order)               //
        // Return type:                       //
        //   - int (result value)             //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record heap, priority-queue /////
        priority_queue<int> record_pq;

        ///// Result value /////
        int res_val;


        /*Heap, Priority-queue based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_pq.push(nums[nums_idx]); //Keep updating, recording

        } //Whole

        while ((k--)) //K-th
        {
            res_val = record_pq.top(); //Keep updating, overwriting

            record_pq.pop(); //Keep updating, popped

        } //K-th

        return res_val;
    }
};
