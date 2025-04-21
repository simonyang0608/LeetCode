class Solution {
public:
    int countHillValley(vector<int> & nums) 
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

        ///// Record dictionary, hashmap /////
        unordered_map<int, unordered_map<int, bool>> record_map;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Two-pointers based loop traversal with recorded dictionary, hashmap*/
        for (int nums_idx = 1; (nums_idx < (len_nums - 1)); (nums_idx++)) //Whole
        {
            int record_left_ptr = (nums_idx - 1); int record_right_ptr = (nums_idx + 1); //Record two-pointers (i.e. left, right)

            while ((record_left_ptr >= 0) && (nums[record_left_ptr] == nums[nums_idx])) //Left-half pointer
            {
                (record_left_ptr--); //Keep updating, traversing

            } //Left-half pointer

            while ((record_right_ptr < len_nums) && (nums[record_right_ptr] == nums[nums_idx])) //Right-half pointer
            {
                (record_right_ptr++); //Keep updating, traversing

            } //Right-half pointer

            ///// Check if the current indexes exceed boundary or not /////
            if ((record_left_ptr < 0) || (record_right_ptr >= len_nums)) { continue; }

            ///// Check if the current indexed-values matched conditions or not /////
            if ((nums[record_left_ptr] > nums[nums_idx]) && (nums[record_right_ptr] > nums[nums_idx]))
            {
                ///// Check if the current indexed-values existed or not /////
                if (! (record_map[record_left_ptr])[record_right_ptr])
                {
                    (record_map[record_left_ptr])[record_right_ptr] = true; //Keep updating, recording

                    (res_cnter++); //Keep updating, accumulating
                }
                else { ; }
            }

            else if ((nums[record_left_ptr] < nums[nums_idx]) && (nums[record_right_ptr] < nums[nums_idx]))
            {
                ///// Check if the current indexed-values existed or not /////
                if (! (record_map[record_left_ptr])[record_right_ptr])
                {
                    (record_map[record_left_ptr])[record_right_ptr] = true; //Keep updating, recording

                    (res_cnter++); //Keep updating, accumulating
                }
                else { ; }
            }

            else { ; }

        } //Whole

        return res_cnter;
    }
};
