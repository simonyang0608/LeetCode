class Solution {
public:
    int trap(vector<int> & height)
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (height vector) //
        // Return type:                         //
        //   - int (result summary value)       //
        //======================================//

        /*Initialize*/
        ///// Length of height vector /////
        int len_height = height.size();

        if (len_height < 3) { return 0; } //Issue, Boundary-case handling

        ///// Record dynamic-programming (i.e. DP) vectors (i.e. left, right) /////
        vector<int> record_dp_left(len_height, 0), record_dp_right(len_height, 0);

        ///// Result summary value /////
        int res_sum_val = 0;


        /*Dynamic-programming based loop traversal*/
        record_dp_left[0] = (-1); record_dp_left[1] = height[0]; //Update, Overwrite
        record_dp_right[(len_height - 1)] = (-1); record_dp_right[(len_height - 2)] = height[(len_height - 1)]; //Update, Overwrite

        ///// Step 1: Record height boundaries (i.e. left, right) with dynamic-programming vectors /////
        for (int height_idx = 2; (height_idx < len_height); (height_idx++)) //Left-bound
        {
            record_dp_left[height_idx] = max(record_dp_left[(height_idx - 1)], height[(height_idx - 1)]); //Keep updating, overwriting

        } //Left-bound

        for (int height_idx = (len_height - 3); (height_idx >= 0); (height_idx--)) //Right-bound
        {
            record_dp_right[height_idx] = max(record_dp_right[(height_idx + 1)], height[(height_idx + 1)]); //Keep updating, overwriting

        } //Right-bound

        ///// Step 2: Looped-traversal with recorded dynamic-programming vectors /////
        for (int height_idx = 1; (height_idx < (len_height - 1)); (height_idx++)) //Whole
        {
            int record_mmax = (record_dp_left[height_idx] < record_dp_right[height_idx]) ? record_dp_left[height_idx] : record_dp_right[height_idx]; //Record minimun max-value

            ///// Check if the current height can trap water or not /////
            if (record_mmax > height[height_idx]) { res_sum_val += (record_mmax - height[height_idx]); } //Keep updating, accumulating
            else { ; }

        } //Whole

        return res_sum_val;
    }
};
