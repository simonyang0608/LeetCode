class Solution {
public:
    int subarraySum(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th target value)        //
        // Return type:                       //
        //   - int (result summary counter)   //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        record_map[0] = 1;

        ///// Record prefix-summary value /////
        int record_prefix_sum = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*One-pass record based loop traversal with recorded dictionary, hashmap*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            record_prefix_sum += nums[nums_idx]; //Keep updating, accumulating

            ///// Check if the current previous summary existed or not /////
            if (record_map.find((record_prefix_sum - k)) != record_map.end())
            {
                res_cnter += record_map[(record_prefix_sum - k)]; //Keep updating, accumulating
            }
            else { ; }

            ///// Check if the current summary existed or not /////
            if (record_map.find(record_prefix_sum) != record_map.end())
            {
                record_map[record_prefix_sum] += 1; //Keep updating, recording
            }
            else { record_map[record_prefix_sum] = 1; } //Keep updating, recording

        } //Whole

        return res_cnter;
    }
};
