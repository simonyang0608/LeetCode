class Solution {
public:
    int minimumSize(vector<int> & nums, int maxOperations) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (maximun operations)       //
        // Return type:                       //
        //   - int (result minimun value)     //
        //====================================//

        /*Initialize*/
        ///// Length, Maximun of nums vector /////
        int len_nums = nums.size(), max_nums = *max_element(nums.begin(), nums.end());

        ///// Record pointers (i.e. middle, left, right) /////
        int record_mid_ptr, record_left_ptr = 1, record_right_ptr = max_nums;


        /*Binary-search based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            int record_cnter = 0; //Record summary counter

            for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
            {
                record_cnter += ((nums[nums_idx] - 1) / record_mid_ptr); //Keep updating, accumulating

            } //Whole

            ///// Check if the current summary counter is smaller or not /////
            if (record_cnter <= maxOperations) { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

            ///// Check if the current summary counter needs to be reset or not /////
            if (record_cnter) { record_cnter &= 0; } //Keep updating, reset
            else { ; }

        } //Binary-search

        return record_left_ptr;
    }
};
