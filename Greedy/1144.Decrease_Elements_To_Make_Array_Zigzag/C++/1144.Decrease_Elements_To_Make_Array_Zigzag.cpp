class Solution {
public:
    int movesToMakeZigzag(vector<int> & nums) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (nums vector)       //
        // Return type:                             //
        //   - int (result minimun summary counter) //
        //==========================================//
        
        /*Initiialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        if (len_nums <= 2) { return 0; } //Issue, Boundary-case handling

        ///// Record vector /////
        vector<int> record_nums(nums.begin(), nums.end());

        ///// Result summary counters (i.e. odd, even) /////
        int res_cnter_odd = 0, res_cnter_even = 0;


        /*Greedy-based loop traversal*/
        ///// Step 1: Looped-traversal for the odd indexed-large /////
        for (int nums_idx = 1; (nums_idx < len_nums); (nums_idx += 2)) //Odd index
        {
            ///// Check if the previous indexed-value is smaller or not /////
            if (nums[(nums_idx - 1)] <= nums[nums_idx]) 
            {
                res_cnter_odd += ((nums[nums_idx] - nums[(nums_idx - 1)]) + 1); //Keep updating, accumulating

                nums[nums_idx] = (nums[(nums_idx - 1)] - 1); //Keep updating, overwriting
            }
            else { ; }

            ///// Check if the next index exceed boundary or not /////
            if ((nums_idx + 1) < len_nums)
            {
                ///// Check if the next indexed-value is smaller or not /////
                if (nums[(nums_idx + 1)] <= nums[nums_idx])
                {
                    res_cnter_odd += ((nums[nums_idx] - nums[(nums_idx + 1)]) + 1); //Keep updating, accumulating

                    nums[nums_idx] = (nums[(nums_idx + 1)] - 1); //Keep updating, overwriting
                }
                else { ; }
            }
            else { ; }

        } //Odd index

        ///// Step 2: Looped-traversal for the even indexed-large /////
        for (int nums_idx = 1; (nums_idx < len_nums); (nums_idx += 2)) //Even index
        {
            ///// Check if the current indexed-value is smaller or not /////
            if (record_nums[nums_idx] <= record_nums[(nums_idx - 1)])
            {
                res_cnter_even += ((record_nums[(nums_idx - 1)] - record_nums[nums_idx]) + 1); //Keep updating, accumulating

                record_nums[(nums_idx - 1)] = (nums[nums_idx] - 1); //Keep updating, overwriting
            }
            else { ; }

            ///// Check if the next index exceed boundary or not /////
            if ((nums_idx + 1) < len_nums)
            {
                ///// Check if the current indexed-value is smaller or not /////
                if (record_nums[nums_idx] <= record_nums[(nums_idx + 1)])
                {
                    res_cnter_even += ((record_nums[(nums_idx + 1)] - record_nums[nums_idx]) + 1); //Keep updating, accumulating

                    record_nums[(nums_idx + 1)] = (record_nums[nums_idx] - 1); //Keep updating, overwriting
                }
                else { ; }
            }
            else { ; }

        } //Even index

        return (res_cnter_odd < res_cnter_even) ? res_cnter_odd : res_cnter_even;
    }
};
