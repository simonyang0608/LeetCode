class Solution {
public:
    int minimumPairRemoval(vector<int> & nums) 
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

        ///// Result minimun steps /////
        int res_min_steps = 0;


        /*Greedy-based loop traversal*/
        while (! is_sorted(nums, len_nums)) //Cycled-times
        {
            int record_idx = (-1); int record_pair_sum = INT_MAX; //Record index, pair-summary

            bool record_flag = false; //Record flag

            for (int nums_idx = 0; (nums_idx < (len_nums - 1)); (nums_idx++)) //Whole
            {
                ///// Check if the current pair-summary matched conditions or not /////
                if ((nums[nums_idx] + nums[(nums_idx + 1)]) < record_pair_sum)
                {
                    record_pair_sum = (nums[nums_idx] + nums[(nums_idx + 1)]); //Keep updating, overwriting

                    record_idx = nums_idx; //Keep updating, overwriting
                }
                else { ; }

            } //Whole

            for (int nums_idx = 0; (nums_idx < (len_nums - 1)); (nums_idx++)) //Whole
            {
                ///// Check if the current flag matched conditions or not /////
                if (! record_flag)
                {
                    ///// Check if the current index matched conditions or not /////
                    if (record_idx == nums_idx)
                    {
                        nums[nums_idx] += nums[(nums_idx + 1)]; //Keep updating, accumulating

                        record_flag = true; //Keep updating, overwriting
                    }
                    else { ; }
                }
                else { nums[nums_idx] = nums[(nums_idx + 1)]; } //Keep updating, overwriting

            } //Whole

            (res_min_steps++); //Keep updating, accumulating

            nums.pop_back(); (len_nums--); //Keep updating, reducing

        } //Cycled-times

        return res_min_steps;
    }


    bool is_sorted(const vector<int> & nums, const int & len_nums)
    {
        //============================================//
        // Input type:                                //
        //   - const vector<int> ref. (nums vector)   //
        //   - const int ref. (length of nums vector) //
        // Return type:                               //
        //   - bool (result flag)                     //
        //============================================//

        /*Whole process, flow*/
        for (int nums_idx = 0; (nums_idx < (len_nums - 1)); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((nums[nums_idx]) > nums[(nums_idx + 1)]) { return false; }

        } //Whole

        return true;
    }
};
