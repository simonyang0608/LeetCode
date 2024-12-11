class Solution {
public:
    long long maximumSubarraySum(vector<int> & nums, int k) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<int> ref. (nums vector)           //
        //   - int (k-th length)                        //
        // Return type:                                 //
        //   - long long (result maximun summary value) //
        //==============================================//

        /*Initialize*/
        ///// Lenght of nums vector /////
        int len_nums = nums.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record summary value /////
        long long record_sum_val = 0;

        ///// Result maximun summary value /////
        long long res_max_sum = 0;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        while (record_right_ptr < len_nums) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map.find(nums[record_right_ptr]) == record_map.end())
            {
                record_sum_val += nums[record_right_ptr]; //Keep updating, accumulating

                record_map[nums[record_right_ptr]] = 1; //Keep updating,recording

                ///// Check if the current length matched conditions or not /////
                if (record_map.size() > k)
                {
                    record_sum_val -= nums[record_left_ptr]; //Keep updating, reducing

                    record_map.erase(nums[(record_left_ptr++)]); //Keep updating, delete

                }
                else { ; }

                ///// Check if the current length matched conditions or not /////
                if (record_map.size() == k) { res_max_sum = max(res_max_sum, record_sum_val); } //Keep updating, overwriting
                else { ; }

                (record_right_ptr++); //Keep updating, traversing
            }
            else
            {
                while (record_map.find(nums[record_right_ptr]) != record_map.end()) //Part
                {
                    record_sum_val -= nums[record_left_ptr]; //Keep updating, reducing

                    record_map.erase(nums[(record_left_ptr++)]); //Keep updating, delete

                } //Part
            }

        } //Whole

        return res_max_sum;
    }
};
