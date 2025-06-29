class Solution {
public:
    int minimumOperations(vector<int> & nums) 
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

        ///// Record set /////
        unordered_set<int> record_set;

        ///// Result suummary couunter /////
        int res_cnter = 0;


        /*Hash-set based loop traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value is 0 or not /////
            if (! nums[nums_idx]) { continue; }

            ///// Check if the current indexed-value existed or not /////
            if (record_set.count(nums[nums_idx])) { continue; }

            record_set.insert(nums[nums_idx]); //Keep updating, recording

            (res_cnter++); //Keep updating, accuumulating

        } //Whole

        return res_cnter;
    }
};
