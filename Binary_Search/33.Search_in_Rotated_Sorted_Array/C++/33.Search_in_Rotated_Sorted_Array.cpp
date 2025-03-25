class Solution {
public:
    int search(vector<int> & nums, int target) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (target value)             //
        // Return type:                       //
        //   - int (result target index)      //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_nums - 1);


        /*Binary-search based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            ///// Check if the current indexed-value matched conditions or not /////
            if (nums[record_mid_ptr] == target) { return record_mid_ptr; }

            ///// Check if the current indexed-value is left-sorted or not /////
            if (nums[record_left_ptr] <= nums[record_mid_ptr])
            {
                ///// Check the current ranges status /////
                if ((nums[record_left_ptr] <= target) && (target < nums[record_mid_ptr]))
                {
                    record_right_ptr = (record_mid_ptr - 1); //Keep updating, overwriting
                }
                else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            }

            else
            {
                ///// Check the current ranges status /////
                if ((nums[record_mid_ptr] < target) && (target <= nums[record_right_ptr]))
                {
                    record_left_ptr = (record_mid_ptr + 1); //Keep updating, overwriting
                }
                else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            }

        } //Binary-search

        return (-1);
    }
};
