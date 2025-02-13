class Solution {
public:
    int majorityElement(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result majority value)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;


        /*Hashmap-based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ((record_map[nums[nums_idx]])++); //Keep updating, recording

            ///// Check if the current indexed-value is majority or not /////
            if (record_map[nums[nums_idx]] > (len_nums / 2)) { return nums[nums_idx]; }

        } //Whole

        return (-1);
    }
};
