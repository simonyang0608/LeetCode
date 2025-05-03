class Solution {
public:
    int shortestSubarray(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th value)               //
        // Return type:                       //
        //   - int (result minimun length)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record heap, priority-queue /////
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> record_pq;

        ///// Record summary value /////
        long long record_sum_val = 0;

        ///// Result minimun length /////
        int res_min_length = INT_MAX;


        /*Heap, Priority-queue based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_sum_val += nums[nums_idx]; //Keep updating, accumulating

            ///// Check if the current summary value matched conditions or not /////
            if (record_sum_val >= k) { res_min_length = ((nums_idx + 1) < res_min_length) ? (nums_idx + 1) : res_min_length; } //Keep updating, overwriting
            else { ; }

            while ((! record_pq.empty()) && ((record_sum_val - (record_pq.top()).first) >= k)) //Part
            {
                res_min_length = min((nums_idx - (record_pq.top()).second), res_min_length); //Keep updating, overwriting

                record_pq.pop(); //Keep updating, popped

            } //Part

            record_pq.emplace(record_sum_val, nums_idx); //Keep updating, recording

        } //Whole

        return (res_min_length == INT_MAX) ? (-1) : res_min_length;
    }
};
