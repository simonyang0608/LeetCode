class Solution {
public:
    int findNumberOfLIS(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result summary counter)   //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record vectors (i.e. dynamic-programming, counter) /////
        vector<int> record_dp(len_nums, 1), record_cnter(len_nums, 1);

        ///// Record maximun value /////
        int record_max_val;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Dynamic-programming (i.e. DP) base loop traversal*/
        ///// Step 1: Looped-traversal with recorded dynamic-programming (i.e. DP) vector /////
        for (int record_right_ptr = 1; (record_right_ptr < len_nums); (record_right_ptr++)) //Right-pointer
        {
            for (int record_left_ptr = 0; (record_left_ptr < record_right_ptr); (record_left_ptr++)) //Left-pointer
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if (nums[record_right_ptr] > nums[record_left_ptr])
                {
                    ///// Check if the current indexed-length is larger or not /////
                    if ((record_dp[record_left_ptr] + 1) > record_dp[record_right_ptr])
                    {
                        record_dp[record_right_ptr] = (record_dp[record_left_ptr] + 1); //Keep updating, overwriting

                        record_cnter[record_right_ptr] = record_cnter[record_left_ptr]; //Keep updating, overwriting
                    }
                    else if ((record_dp[record_left_ptr] + 1) == record_dp[record_right_ptr])
                    {
                        record_cnter[record_right_ptr] += record_cnter[record_left_ptr]; //Keep updating, accumulating
                    }
                    else { ; }
                }
                else { ; }

            } //Left-pointer

        } //Right-pointer

        ///// Step 2: Post-process, Final completions /////
        record_max_val = *max_element(record_dp.begin(), record_dp.end()); //Record maximun value

        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (record_dp[nums_idx] == record_max_val) { res_cnter += record_cnter[nums_idx]; } //Keep updating, accumulating
            else { ; }

        } //Whole

        return res_cnter;
    }
};
