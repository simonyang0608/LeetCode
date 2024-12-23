class Solution {
public:
    int minOperations(vector<int> & nums) 
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

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Greedy-based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-value with dictionary, hashmap /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ((record_map[nums[nums_idx]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (auto record_elem = record_map.begin(); (record_elem != record_map.end()); (record_elem++)) //Whole
        {
            ///// Check if the current summary counter is less than 2 or not ///// 
            if ((record_elem->second) < 2) { return (-1); }

            if (! ((record_elem->second) % 3)) { res_cnter += ((record_elem->second) / 3); } //Keep updating, accumulating
            else { res_cnter += (((record_elem->second) / 3) + 1); } //Keep updating, accumulating

        } //Whole

        return res_cnter;
    }
};
