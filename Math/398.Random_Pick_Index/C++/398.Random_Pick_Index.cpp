class Solution {
public:
    /*Initialize*/
    ///// Record dictionary, hashmap /////
    unordered_map<int, vector<int>> record_map;

public:
    Solution(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - void (no return)               //
        //====================================//

        /*Whole process, flow*/
        ///// Check if the current dictionary, hashmap needs to be reset or not /////
        if (! record_map.empty()) { record_map.clear(); } //Update, Reset
        else { ; }

        for (int nums_idx = 0; (nums_idx < nums.size()); (nums_idx++)) //Whole
        {
            (record_map[nums[nums_idx]]).emplace_back(nums_idx); //Keep updating, recording

        } //Whole
    }
    
    int pick(int target)
    {
        //========================//
        // Input type:            //
        //   - int (target value) //
        // Return type:           //
        //   - int (result index) //
        //========================//
        
        return (record_map[target])[(rand() % (record_map[target]).size())];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
