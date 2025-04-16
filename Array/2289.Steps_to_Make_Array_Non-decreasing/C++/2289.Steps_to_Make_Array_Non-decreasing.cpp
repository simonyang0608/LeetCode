class Solution {
public:
    int totalSteps(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result steps)             //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record stack /////
        stack<pair<int, int>> record_stack;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Stack-based loop traversal*/
        for (int nums_idx = (len_nums - 1); (nums_idx >= 0); (nums_idx--)) //Whole
        {
            int record_cnter = 0; //Record summary counter

            while ((! record_stack.empty()) && ((record_stack.top()).first < nums[nums_idx])) //Part
            {
                record_cnter = max((record_cnter + 1), (record_stack.top()).second); //Keep updating, overwriting

                record_stack.pop(); //Keep updating, popped

            } //Part

            res_max_cnter = (record_cnter > res_max_cnter) ? record_cnter : res_max_cnter; //Keep updating, overwriting

            record_stack.emplace(nums[nums_idx], record_cnter); //Keep updating, recording
        }

        return res_max_cnter;
    }
};
