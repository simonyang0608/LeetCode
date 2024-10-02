class Solution {
public:
    int halveArray(vector<int> & nums) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums vector)  //
        // Return type:                        //
        //   - int (result minimun operations) //
        //=====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record heap, priority-queue /////
        priority_queue<double> record_pq(begin(nums), end(nums));

        ///// Record half-of summary value /////
        double record_half_sum_val;

        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++))
        {
            record_half_sum_val += (nums[nums_idx] / 2.0);
        }

        ///// Record summary value /////
        double record_sum_val = 0.0;

        ///// Current half-of maximun value /////
        double curr_half_max_val;

        ///// Result minimun operations /////
        int res_min_oprs = 0;


        /*Heap, Priority-queue based loop traversal*/
        while (record_sum_val < record_half_sum_val) //Part
        {
            curr_half_max_val = (record_pq.top() / 2.0); //Current half-of maximun value
            record_sum_val += curr_half_max_val; //Keep updating, accumulating

            (res_min_oprs++); //Keep updating, accumulating

            record_pq.pop(); //Keep updating, popping

            record_pq.push(curr_half_max_val); //Keep updating, recording

        } //Part

        return res_min_oprs;
    }
};
