class Solution {
public:
    vector<int> nextGreaterElements(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of vectors (i.e. nums, record-nums) /////
        int len_nums = nums.size(), len_record_nums = (-1);

        ///// Record nums vector /////
        vector<int> record_nums(nums.begin(), nums.end());

        ///// Record stack /////
        stack<int> record_stack;

        ///// Result vector /////
        vector<int> res_vect(len_nums, (-1));


        /*Stack-based loop traversal with recorded vector*/
        ///// Step 1: Record circular indexed-value with vector /////
        for (int nums_idx = 0; (nums_idx < (len_nums - 1)); (nums_idx++)) //Whole
        {
            record_nums.emplace_back(nums[nums_idx]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        len_record_nums = record_nums.size(); //Length of record-nums vector

        for (int record_nums_idx = 0; (record_nums_idx < len_record_nums); (record_nums_idx++)) //Whole
        {
            while ((! record_stack.empty()) && (record_nums[record_stack.top()] < record_nums[record_nums_idx])) //Part
            {
                ///// Check if the current index is valid or not /////
                if (record_stack.top() >= len_nums) { record_stack.pop(); continue; }

                res_vect[record_stack.top()] = record_nums[record_nums_idx]; //Keep updating, overwriting

                record_stack.pop(); //Keep updating, popped

            } //Part

            record_stack.emplace(record_nums_idx); //Keep updating, recording

        } //Whole

        return res_vect;
    }
};
