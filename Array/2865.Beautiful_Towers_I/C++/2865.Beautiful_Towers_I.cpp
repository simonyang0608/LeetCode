class Solution {
public:
    long long maximumSumOfHeights(vector<int> & heights) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<int> ref. (heights vector)        //
        // Return type:                                 //
        //   - long long (result maximun summary value) //
        //==============================================//

        /*Initialize*/
        ///// Length of heights vector /////
        int len_heights = heights.size();

        ///// Record vectors (i.e. left, right) /////
        vector<long long> record_vect_left(len_heights, 0), record_vect_right(len_heights, 0);

        ///// Record stacks (i.e. left, right) /////
        stack<int> record_stack_left, record_stack_right;

        ///// Result maximun summary value /////
        long long res_max_sum = 0;


        /*Stack-based loop traversal with recorded vectors*/
        ///// Step 1: Looped-traversal for the left-half part of vector /////
        for (int heights_idx = 0; (heights_idx < len_heights); (heights_idx++)) //Whole
        {
            while ((! record_stack_left.empty()) && (heights[record_stack_left.top()] > heights[heights_idx])) //Part
            {
                record_stack_left.pop(); //Keep updating, popped

            } //Part

            ///// Check if the current stack is empty or not /////
            if (record_stack_left.empty()) { record_vect_left[heights_idx] = (static_cast<long long>(heights[heights_idx]) * heights_idx); } //Keep updating, overwriting
            else { record_vect_left[heights_idx] = (record_vect_left[record_stack_left.top()] + 
                                                   (static_cast<long long>(heights[heights_idx]) * (heights_idx - record_stack_left.top() - 1)) +
                                                    heights[record_stack_left.top()]); } //Keep updating, overwriting

            record_stack_left.emplace(heights_idx); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the right-half part of vector /////
        for (int heights_idx = (len_heights - 1); (heights_idx >= 0); (heights_idx--)) //Whole
        {
            while ((! record_stack_right.empty()) && (heights[record_stack_right.top()] > heights[heights_idx])) //Part
            {
                record_stack_right.pop(); //Keep updating, popped

            } //Part

            ///// Check if the current stack is empty or not /////
            if (record_stack_right.empty()) { record_vect_right[heights_idx] = (static_cast<long long>(heights[heights_idx]) * (len_heights - heights_idx)); } //Keep updating, overwriting
            else { record_vect_right[heights_idx] = (record_vect_right[record_stack_right.top()] + 
                                                    (static_cast<long long>(heights[heights_idx]) * (record_stack_right.top() - heights_idx))); } //Keep updating, overwriting

            record_stack_right.emplace(heights_idx); //Keep updating, recording

        } //Whole

        ///// Step 3: Post-process, Final completions /////
        for (int heights_idx = 0; (heights_idx < len_heights); (heights_idx++)) //Whole
        {
            res_max_sum = max(res_max_sum, (record_vect_left[heights_idx] + record_vect_right[heights_idx])); //Keep updating, overwriting

        } //Whole

        return res_max_sum;
    }
};
