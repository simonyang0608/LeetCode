class Solution {
public:
    vector<int> secondGreaterElement(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record stacks (i.e. 1, 2) /////
        stack<int> record_stack1, record_stack2;

        ///// Result vector /////
        vector<int> res_vect(len_nums, (-1));


        /*Stack-based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            while ((! record_stack2.empty()) && (nums[record_stack2.top()]) < nums[nums_idx]) //Part
            {
                res_vect[record_stack2.top()] = nums[nums_idx]; record_stack2.pop(); //Keep updating, popped

            } //Part

            vector<int> record_vect; //Record vector

            while ((! record_stack1.empty()) && (nums[record_stack1.top()] < nums[nums_idx])) //Part
            {
                record_vect.emplace_back(record_stack1.top()); record_stack1.pop(); //Keep updating, popped

            } //Part

            ///// Check if the current vector is empty or not /////
            if (! record_vect.empty())
            {
                reverse(record_vect.begin(), record_vect.end()); //Keep updating, reversing

                for (const int & record_idx: record_vect) //Whole
                {
                    record_stack2.emplace(record_idx); //Keep updating, recording

                } //Whole
            }
            else { ; }

            record_stack1.emplace(nums_idx); //Keep updating, recording

        } //Whole

        return res_vect;
    }
};
