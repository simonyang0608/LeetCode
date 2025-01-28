class Solution {
public:
    int jump(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result minimun steps)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        if (len_nums == 1) { return 0; } //Issue, Boundary-case handling

        ///// Record boundary, farest index /////
        int record_farest = 0, record_bound = 0;

        ///// Result minimun steps /////
        int res_min_steps = 0;


        /*Greedy-based loop traversal*/
        for (int nums_idx = 0; (nums_idx < (len_nums - 1)); (nums_idx++)) //Whole
        {
            record_farest = max(record_farest, (nums_idx + nums[nums_idx])); //Keep updating, overwriting

            ///// Check if the current index reach boundary or not /////
            if (nums_idx == record_bound)
            {
                (res_min_steps++); (record_bound = record_farest); //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return res_min_steps;
    }
};
