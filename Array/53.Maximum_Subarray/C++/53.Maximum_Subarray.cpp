class Solution {
public:
    int maxSubArray(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result maximun value)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record value /////
        int record_val = 0;

        ///// Result maximun value /////
        int res_max_val = ((-1) * 1e9);


        /*Kadanes'-based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_val += nums[nums_idx]; //Keep updating, accumulating

            res_max_val = max(res_max_val, record_val); //Keep updating, overwriting

            ///// Check if the current value needs to be reset or not /////
            if (record_val < 0) { record_val &= 0; } //Keep updating, reset
            else { ; }

        } //Whole

        return res_max_val;
    }
};
