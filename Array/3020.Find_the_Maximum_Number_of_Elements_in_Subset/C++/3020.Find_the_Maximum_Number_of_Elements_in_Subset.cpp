class Solution {
public:
    int maximumLength(vector<int> & nums) 
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

        ///// Record dictionary, hashmap /////
        unordered_map<long long, int> record_map;

        ///// Record power value /////
        long long record_pow_val;

        ///// Record ones summary counter /////
        int record_ones_cnter = count(nums.begin(), nums.end(), 1);

        ///// Result maximun summary counter /////
        int res_max_cnter = 1;


        /*Greedy-based loop traversal with recorded dictionary, hashmap*/
        sort(nums.begin(), nums.end(), [](const int & num1, const int & num2)
        {
            return (num1 > num2);
        }); //Sorted operations

        for(int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value is 1 or not /////
            if (nums[nums_idx] != 1)
            {
                record_pow_val = ((long long)(nums[nums_idx]) * (long long)(nums[nums_idx])); //Record power value

                ///// Check if the current power value existed or not /////
                if ((record_map.find(record_pow_val) != record_map.end()))
                {
                    ///// Check if the current indexed-value existed or not /////
                    if (record_map.find(nums[nums_idx]) != record_map.end())
                    {
                        record_map[nums[nums_idx]] = (2 + record_map[record_pow_val]); //Keep updating, recording

                        res_max_cnter = max(res_max_cnter, record_map[nums[nums_idx]]); //Keep updating, overwriting
                    }
                    else { ((record_map[nums[nums_idx]])++); } //Keep updating, accumulating
                }
                else { record_map[nums[nums_idx]] = 1; } //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return max(res_max_cnter, ((record_ones_cnter % 2) ? record_ones_cnter : (record_ones_cnter - 1)));
    }
};
