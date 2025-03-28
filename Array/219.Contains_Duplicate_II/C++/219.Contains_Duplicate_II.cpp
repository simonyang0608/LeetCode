class Solution {
public:
    bool containsNearbyDuplicate(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th distance)            //
        // Return type:                       //
        //   - bool (result flag)             //
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
            if (record_map.find(nums[nums_idx]) != record_map.end())
            {
                ///// Check if the current difference is less than k-th or not /////
                if ((nums_idx - record_map[nums[nums_idx]]) <= k) { return true; }
            }
            else { ; }

            record_map[nums[nums_idx]] = nums_idx; //Keep updating, recording

        } //Whole

        return false;
    }
};
