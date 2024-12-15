class Solution {
public:
    int largestSumAfterKNegations(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th times)               //
        // Return type:                       //
        //   - int (result summary value)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record heap, priority-queue /////
        priority_queue<int, vector<int>, greater<int>> record_pq(nums.begin(), nums.end());

        ///// Record value /////
        int record_val;

        ///// Result summary value /////
        int res_sum_val = accumulate(nums.begin(), nums.end(), 0);


        /*Heap, Priority-queue based loop traversal*/
        while ((k--)) //K-th times
        {
            record_val = (record_pq.top() * (-1)); //Record value

            record_pq.pop(); //Keep updating, popped

            res_sum_val += (record_val * 2); //Keep updating, accumulating

            record_pq.push(record_val); //Keep updating, recording

        } //K-th times

        return res_sum_val;
    }
};
