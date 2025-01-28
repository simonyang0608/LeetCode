class Solution {
public:
    long long maxScore(vector<int> & nums, int x) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (nums vector)   //
        //   - int (x score)                    //
        // Return type:                         //
        //   - long long (result maximun score) //
        //======================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record dynamic-programming (i.e. odd, even) /////
        long long record_dp_odd = (nums[0] - ((nums[0] % 2) ? 0 : x));
        long long record_dp_even = (nums[0] - ((! (nums[0] % 2)) ? 0 : x));


        /*Dynamic-programming based loop traversal*/
        for (int nums_idx = 1; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value is odd or even /////
            if ((nums[nums_idx] % 2))
            {
                record_dp_odd = max((record_dp_odd + nums[nums_idx]), ((record_dp_even + nums[nums_idx]) - x)); //Keep updating, overwriting
            }
            else { record_dp_even = max((record_dp_even + nums[nums_idx]), ((record_dp_odd + nums[nums_idx]) - x)); } //Keep updating, overwriting

        } //Whole

        return max(record_dp_odd, record_dp_even);
    }
};
