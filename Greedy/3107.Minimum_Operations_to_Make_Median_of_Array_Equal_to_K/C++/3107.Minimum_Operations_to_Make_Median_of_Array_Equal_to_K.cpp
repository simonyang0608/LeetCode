class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int> & nums, int k) 
    {
        //================================================//
        // Input type:                                    //
        //   - vector<int> ref. (nums vector)             //
        //   - int (k-th value)                           //
        // Return type:                                   //
        //   - long long (result minimun summary counter) //
        //================================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = (len_nums / 2), record_right_ptr = (len_nums / 2);

        ///// Result minimun summary counter /////
        long long res_min_cnter = 0;


        /*Greedy-based loop traversal with sorted-operations*/
        sort(nums.begin(), nums.end()); //Sorted-operations

        ///// Check if the current indexed-value is larger than k-th or not /////
        if (nums[record_left_ptr] >= k) { res_min_cnter += (nums[record_left_ptr] - k); } //Update, Accumulate
        else { res_min_cnter += (k - nums[record_left_ptr]); } //Update, Accumulate

        nums[record_left_ptr] = k; //Update, Overwrite

        while ((record_left_ptr - 1) >= 0) //Left-pointer
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[(record_left_ptr - 1)] <= nums[record_left_ptr]) { ; }
            else
            {
                res_min_cnter += (nums[(record_left_ptr - 1)] - nums[record_left_ptr]); //Keep updating, accumulating

                nums[(record_left_ptr - 1)] = nums[record_left_ptr]; //Keep updating, overwriting
            }

            (record_left_ptr--); //Keep updating, traversing

        } //Left-pointer

        while ((record_right_ptr + 1) < len_nums) //Right-pointer
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[(record_right_ptr + 1)] >= nums[record_right_ptr]) { ; }
            else
            {
                res_min_cnter += (nums[record_right_ptr] - nums[(record_right_ptr + 1)]); //Keep updating, accumulating

                nums[(record_right_ptr + 1)] = nums[record_right_ptr]; //Keep updating, overwriting
            }

            (record_right_ptr++); //Keep updating, traversing

        } //Right-pointer

        return res_min_cnter;
    }
};
