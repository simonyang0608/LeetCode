class Solution {
public:
    long long countGood(vector<int> & nums, int k) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums vector)     //
        //   - int (k-th pairs)                   //
        // Return type:                           //
        //   - long long (result summary counter) //
        //========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record summary counter /////
        long long record_pair_cnter = 0;

        ///// Result summary counter /////
        long long res_cnter = 0;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        while (record_right_ptr < len_nums) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map.find(nums[record_right_ptr]) == record_map.end()) { record_map[nums[record_right_ptr]] = 0; } //Keep updating, recording
            else { ; }
            
            record_pair_cnter += record_map[nums[record_right_ptr]]; //Keep updating, accumulating

            record_map[nums[record_right_ptr]] += 1; //Keep updating, accumulating

            while ((record_left_ptr < record_right_ptr) && (record_pair_cnter >= k)) //Part
            {
                record_map[nums[record_left_ptr]] -= 1; //Keep updating, reducing

                record_pair_cnter -= record_map[nums[(record_left_ptr++)]]; //Keep updating, reducing

            } //Part

            res_cnter += record_left_ptr; //Keep updating, accumulating

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_cnter;
    }
};
