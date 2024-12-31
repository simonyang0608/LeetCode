class Solution {
public:
    long long minimalKSum(vector<int> & nums, int k) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<int> ref. (nums vector)           //
        //   - int (k-th ranges)                        //
        // Return type:                                 //
        //   - long long (result minimun summary value) //
        //==============================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dictionary, hashmap /////
        map<int, bool> record_map;

        ///// Result minimun summary value /////
        long long res_min_sum = (((long long)(k) * ((long long)(k) + 1)) / 2);


        /*Greedy-based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-value with dictionary, hashmap /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++))
        {
            record_map[nums[nums_idx]] = true;
        }

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (auto record_ele = record_map.begin(); (record_ele != record_map.end()); (record_ele++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((record_ele->first) <= k)
            {
                res_min_sum -= (record_ele->first); //Keep updating, reducing

                res_min_sum += (++k); //Keep updating, accumulating
            }
            else { break; }

        } //Whole

        return res_min_sum;
    }
};
