class Solution {
public:
    vector<int> singleNumber(vector<int> & nums) 
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
        unordered_map<int, int> record_map;

        ///// Result vector /////
        vector<int> res_vect;


        /*Hashmap-based loop traversal*/
        ///// Step 1: Record indexed-value with dictionary, hashmap /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ((record_map[nums[nums_idx]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the recorded dictionary, hashmap /////
        for (auto & record_ele: record_map) //Whole
        {
            ///// Check if the current summary counter matched conditions or not /////
            if (record_ele.second == 1) { res_vect.emplace_back(record_ele.first); } //Keep updating, recording
            else { ; }

            ///// Check if the current length matched conditions or not /////
            if (res_vect.size() == 2) { break; }

        } //Whole

        return res_vect;
    }
};
