class Solution {
public:
    int findMin(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result minimun value)     //
        //====================================//

        /*Initialize*/
        ///// Record pointers (i.e. middle, left, right) /////
        int record_mid_ptr, record_left_ptr = 0, record_right_ptr = (nums.size() - 1);

        ///// Result minimun value /////
        int res_min_val = 5001;


        /*Binary-search based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Whole
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            ///// Check if the current indexed-value matched conditions or not ////
            if (nums[record_left_ptr] <= nums[record_mid_ptr])
            {
                res_min_val = min(res_min_val, nums[record_left_ptr]); //Keep updating, overwriting

                record_left_ptr = (record_mid_ptr + 1); //Keep updating, overwriting
            }

            else
            {
                res_min_val = min(res_min_val, nums[record_mid_ptr]); //Keep updating, overwriting

                record_right_ptr = (record_mid_ptr - 1); //Keep updating, overwriting
            }

        } //Whole

        return res_min_val;
    }
};
