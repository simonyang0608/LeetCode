class Solution {
public:
    int longestSubarray(vector<int> & nums, int limit) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (limit value)              //
        // Return type:                       //
        //   - int (result maximun length)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record deques (i.e. minimun, maximun) /////
        deque<int> record_dq_min, record_dq_max;

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Result maximun length /////
        int res_max_length = 0;


        /*Sliding-window based loop traversal with recorded deques*/
        while (record_right_ptr < len_nums) //Whole
        {
            while ((! record_dq_min.empty()) && ((record_dq_min.back() > nums[record_right_ptr]))) //Part
            {
                record_dq_min.pop_back(); //Keep updating, popped

            } //Part

            record_dq_min.push_back(nums[record_right_ptr]); //Keep updating, recording

            while ((! record_dq_max.empty()) && ((record_dq_max.back() < nums[record_right_ptr]))) //Part
            {
                record_dq_max.pop_back(); //Keep updating, popped

            } //Part

            record_dq_max.push_back(nums[record_right_ptr]); //Keep updating, recording

            while ((record_dq_max.front() - record_dq_min.front()) > limit) //Part
            {
                ///// Check if the current maximun value matched conditions or not /////
                if (record_dq_max.front() == nums[record_left_ptr]) { record_dq_max.pop_front(); } //Keep updating, popped
                else { ; }

                ///// Check if the current minimun value matched conditions or not /////
                if (record_dq_min.front() == nums[record_left_ptr]) { record_dq_min.pop_front(); } //Keep updating, popped
                else { ; }

                (record_left_ptr++); //Keep updating, traversing

            } //Part

            res_max_length = max(res_max_length, (record_right_ptr - record_left_ptr + 1)); //Keep updating, overwriting

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_max_length;
    }
};
