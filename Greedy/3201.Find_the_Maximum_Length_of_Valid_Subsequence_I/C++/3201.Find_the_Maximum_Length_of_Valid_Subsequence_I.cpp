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

        ///// Record summary counters (i.e. all-even, all-odd, even-odd, odd-even) /////
        int all_even_cnter = 0, all_odd_cnter = 0, even_odd_cnter = 0, odd_even_cnter = 0;

        ///// Record sign /////
        int record_sign = (-1);


        /*Greedy-based loop traversal*/
        ///// Step 1: Looped-traversal for all-even, odd conditions /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (! (nums[nums_idx] % 2)) { (all_even_cnter++); } //Keep updating, accumulating
            else { (all_odd_cnter++); } //Keep updating, accumulating
        }

        ///// Step 2: Looped-traversal for even-odd conditions /////
        record_sign = 0; //Update, Reset

        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((nums[nums_idx] % 2) == record_sign)
            { 
                (even_odd_cnter++); //Keep updating, accumulating

                record_sign = (1 - record_sign); //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        ///// Step 3: Looped-traversal for odd-even conditions /////
        record_sign = 1; //Update, Reset

        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((nums[nums_idx] % 2) == record_sign)
            { 
                (odd_even_cnter++); //Keep updating, accumulating

                record_sign = (1 - record_sign); //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return max({all_even_cnter, all_odd_cnter, even_odd_cnter, odd_even_cnter});
    }
};
