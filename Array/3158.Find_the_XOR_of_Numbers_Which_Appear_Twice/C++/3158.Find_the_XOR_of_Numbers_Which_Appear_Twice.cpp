class Solution {
public:
    int duplicateNumbersXOR(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result summary value)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result summary value /////
        int res_sum_val = 0;


        /*Greedy-based loop traversal*/
        sort(nums.begin(), nums.end()); //Sorted operations

        while (record_trav_ptr < len_nums) //Whole
        {
            int record_cnter = 1; //Record summary counter

            while (((record_trav_ptr + 1) < len_nums) && (nums[record_trav_ptr] == nums[(record_trav_ptr + 1)])) //Part
            {
                (record_cnter++); (record_trav_ptr++); //Keep updating, traversing
            }

            ///// Check if the current summary counter is less than 2 or not /////
            if (record_cnter == 2) { res_sum_val ^= nums[record_trav_ptr]; } //Keep updating, accumulating
            else { ; }

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_sum_val;
    }
};
