class Solution {
public:
    int longestConsecutive(vector<int> & nums) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (nums vector)       //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        if (! len_nums) { return 0; } //Issue, Boundary-case handling

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 1;

        ///// Record dictionary, hashmap /////
        map<int, bool> record_map;


        /*Greedy-based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-value with dictionary, hashmap /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map.find(nums[nums_idx]) == record_map.end()) { record_map[nums[nums_idx]] = true; } //Keep updating, recording
            else { ; }

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (record_map[nums[nums_idx]])
            {
                ///// Check if the current indexed-value existed or not /////
                if (record_map.find((nums[nums_idx] - 1)) == record_map.end())
                {
                    while ((record_map.find(nums[nums_idx]) != record_map.end()) && record_map[nums[nums_idx]]) //Part
                    {
                        (record_cnter++); //Keep updating, accumulating

                        record_map[((nums[nums_idx])++)] &= false; //Keep updating, recording

                    } //Part

                    res_max_cnter = max(res_max_cnter, record_cnter); //Keep updating, overwriting

                    ///// Check if the current summary counter needs to be reset or not /////
                    if (record_cnter) { record_cnter &= 0; } //Keep updating, reset
                    else { ; }
                }
                else { ; }
            }
            else { ; }

        } //Whole

        return res_max_cnter;
    }
};
