class Solution {
public:
    int maxSum(vector<int> & nums) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums vector)     //
        // Return type:                           //
        //   - int (result maximun summary value) //
        //========================================//

        /*Initialize*/
        ///// Lenght of nums vector /////
        int len_nums = nums.size();

        ///// Record set /////
        unordered_set<int> record_set;

        ///// Record maximun value /////
        int record_max_val = (-101);

        ///// Result maximun summary value /////
        int res_max_sum = 0;


        /*Greedy-based loop traversal with recorded hashset*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_max_val = (nums[nums_idx] > record_max_val) ?
                              nums[nums_idx] : record_max_val; //Keep updating, overwriting

            ///// Check if the current indexed-value existed or not /////
            if (record_set.count(nums[nums_idx])) { continue; }

            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[nums_idx] > 0)
            {
                record_set.insert(nums[nums_idx]); //Keep updating, recording

                res_max_sum += nums[nums_idx]; //Keep updating, accumulating
            }
            else { ; }

        } //Whole

        return (record_max_val <= 0) ? (record_max_val) : res_max_sum;
    }
};
