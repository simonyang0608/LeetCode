class Solution {
public:
    int minIncrementForUnique(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result minimun moves)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Sorted operations /////
        sort(nums.begin(), nums.end());

        ///// Record dictionary, hashmap /////
        unordered_map<int, bool> record_map;

        ///// Record maximun value /////
        int record_max_val;

        ///// Result minimun summary counter /////
        int res_min_cnter = 0;


        /*Greedy-based loop traversal with recorded dictionary, hashmap*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (record_map.find(nums[nums_idx]) == record_map.end())
            {
                record_map[nums[nums_idx]] = true; //Keep updating, recording

                record_max_val = nums[nums_idx]; //Keep updating, overwriting
            }
            else
            {
                res_min_cnter += ((++record_max_val) - nums[nums_idx]); //Keep updating, accumulating

                record_map[record_max_val] = true; //Keep updating, recording
            }

        } //Whole

        return res_min_cnter;
    }
};
