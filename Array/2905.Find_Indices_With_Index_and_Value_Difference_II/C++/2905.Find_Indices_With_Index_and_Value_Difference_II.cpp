class Solution {
public:
    vector<int> findIndices(vector<int> & nums, int indexDifference, int valueDifference) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (index differences)        //
        //   - int (value differences)        //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = indexDifference;

        ///// Record maximun, minimun value /////
        int record_max_val = (-1), record_min_val = (1e9 + 1);

        ///// Record maximun, minimun index /////
        int record_max_idx, record_min_idx;


        /*Two-pointers based loop traversal*/
        while (record_right_ptr < len_nums) //Whole
        {
            ///// Check if the current indexed-value is larger or not /////
            if (nums[record_left_ptr] > record_max_val) { record_max_val = nums[record_left_ptr]; record_max_idx = record_left_ptr; } //Keep updating, overwriting
            else { ; }

            ///// Check if the current indexed-value is smaller or not /////
            if (nums[record_left_ptr] < record_min_val) { record_min_val = nums[record_left_ptr]; record_min_idx = record_left_ptr; } //Keep updating, overwriting
            else { ; }

            ///// Check if the current differences matched conditions or not /////
            if (abs(nums[record_right_ptr] - record_min_val) >= valueDifference) { return {record_min_idx, record_right_ptr}; }
            else { ; }

            if (abs(record_max_val - nums[record_right_ptr]) >= valueDifference) { return {record_max_idx, record_right_ptr}; }
            else { ; }

            (record_left_ptr++); (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return {(-1), (-1)};
    }
};
