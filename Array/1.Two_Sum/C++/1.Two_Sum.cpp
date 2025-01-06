class Solution {
public:
    vector<int> twoSum(vector<int> & nums, int target) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (target value)             //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;


        /*Hashmap-based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map.find((target - nums[nums_idx])) != record_map.end())
            {
                return {record_map[(target - nums[nums_idx])], nums_idx};
            }
            else { ; }

            record_map[nums[nums_idx]] = nums_idx; //Keep updating, recording

        } //Whole

        return {(-1), (-1)};
    }
};
