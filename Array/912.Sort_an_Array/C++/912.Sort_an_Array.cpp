class Solution {
public:
    vector<int> sortArray(vector<int> & nums) 
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

        ///// Record minimun, maximun values /////
        int record_min_val = (*min_element(nums.begin(), nums.end())), record_max_val = (*max_element(nums.begin(), nums.end()));

        ///// Result vector /////
        vector<int> res_vect;


        /*Greedy-based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-value with dictionary, hashmap /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map.find(nums[nums_idx]) == record_map.end())
            {
                record_map[nums[nums_idx]] = 1; //Keep updating, recording
            }
            else { record_map[nums[nums_idx]] += 1; } //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int min_max_idx = record_min_val; (min_max_idx <= record_max_val); (min_max_idx++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map.find(min_max_idx) != record_map.end())
            {
                for (int times_idx = 0; (times_idx < record_map[min_max_idx]); (times_idx++)) //Cycle-times
                {
                    res_vect.push_back(min_max_idx); //Keep updating, recording

                } //Cycle-times
            }

            else { ; }

        } //Whole

        return res_vect;
    }
};
