class Solution {
public:
    long long continuousSubarrays(vector<int> & nums) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums vector)     //
        // Return type:                           //
        //   - long long (result summary counter) //
        //========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record deques (i.e. minimun, maximun) /////
        deque<int> record_dq_min, record_dq_max;

        ///// Record two pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Result summary counter /////
        long long res_cnter = 0;


        /*Deque-based loop traversal*/
        while (record_right_ptr < len_nums) //Whole
        {
            while ((! record_dq_min.empty()) && (nums[record_dq_min.back()] >= nums[record_right_ptr])) //Part
            {
                record_dq_min.pop_back(); //Keep updating, popped

            } //Part

            while ((! record_dq_max.empty()) && (nums[record_dq_max.back()] <= nums[record_right_ptr])) //Part
            {
                record_dq_max.pop_back(); //Keep updating, popped

            } //Part

            record_dq_min.emplace_back(record_right_ptr); record_dq_max.emplace_back(record_right_ptr); //Keep updating, recording

            while ((nums[record_dq_max.front()] - nums[record_dq_min.front()]) > 2) //Part
            {
                (record_left_ptr++); //Keep updating, traversing

                ///// Check if the current index exceed boundary or not /////
                if (record_dq_min.front() < record_left_ptr) { record_dq_min.pop_front(); } //Keep updating, popped
                else { ; }

                ///// Check if the current index exceed boundary or not /////
                if (record_dq_max.front() < record_left_ptr) { record_dq_max.pop_front(); } //Keep updating, popped
                else { ; }

            } //Part

            res_cnter += (record_right_ptr - record_left_ptr + 1); //Keep updating, accumulating

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_cnter;
    }
};
