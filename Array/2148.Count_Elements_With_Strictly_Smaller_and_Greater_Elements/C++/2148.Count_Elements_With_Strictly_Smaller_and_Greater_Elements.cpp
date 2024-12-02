class Solution {
public:
    int countElements(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result summary counter)   //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Sorted operations /////
        sort(nums.begin(), nums.end());

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*One-pass record based loop traversal*/
        ///// Step 1: Looped-traversal for the prefix-part, half /////
        while (((record_trav_ptr + 1) < len_nums) && (nums[record_trav_ptr] == nums[(record_trav_ptr + 1)])) //Prefix-part
        {
            (record_trav_ptr++); //Keep updating, traversing

        } //Prefix-part

        (record_trav_ptr++); //Update, Traverse

        ///// Step 2: Looped-traversal for the suffix-part, half /////
        while (record_trav_ptr < len_nums) //Suffix-part
        {
            (record_cnter++); //Keep updating, accumulating

            while (((record_trav_ptr + 1) < len_nums) && (nums[record_trav_ptr] == nums[(record_trav_ptr + 1)])) //Part
            {
                (record_cnter++); //Keep updating, accumulating
                (record_trav_ptr++); //Keep updating, traversing

            } //Part

            ///// Check if the current indexed-pointer matched conditions or not /////
            if ((record_trav_ptr + 1) < len_nums)
            {
                res_cnter += record_cnter; //Keep updating, accumulating
            }
            else { ; }

            ///// Check if the current summary counter needs to be reset or not /////
            if (record_cnter) { record_cnter &= 0; } //Update, Reset
            else { ; }

            (record_trav_ptr++); //Keep updating, traversing

        } //Suffix-part

        return res_cnter;
    }
};
