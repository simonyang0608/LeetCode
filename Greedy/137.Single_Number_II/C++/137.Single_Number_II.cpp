class Solution {
public:
    int singleNumber(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result value)             //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;


        /*Greedy-based loop traversal*/
        sort(nums.begin(), nums.end()); //Sorted operations

        while (record_trav_ptr < len_nums) //Whole
        {
            int record_cnter = 1; //Record summary counter

            while (((record_trav_ptr + 1) < len_nums) && (nums[record_trav_ptr] == nums[(record_trav_ptr + 1)])) //Part
            {
                (record_cnter++); (record_trav_ptr++); //Keep updating, traversing

            } //Part

            ///// Check if the current summary counter less than 3 or not /////
            if (record_cnter != 3) { return nums[record_trav_ptr]; }

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return (-1);
    }
};
