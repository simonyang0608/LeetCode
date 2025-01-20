class Solution {
public:
    vector<int> getSneakyNumbers(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dictionary, hashmap /////
        map<int, int> record_map;

        ///// Result vector /////
        vector<int> res_vect;


        /*Hashmap based loopp traversal*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map[nums[nums_idx]]) { res_vect.emplace_back(nums[nums_idx]); continue; } //Keep updating, recording
            
            ((record_map[nums[nums_idx]])++); //Keep updating, accumulating

        } //Whole

        return res_vect;
    }
};
