class Solution {
public:
    vector<int> getAverages(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th radius)              //
        // Return type:                       //
        //   - vector<int> (result vector)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Total diameter /////
        int total_diameter = ((2 * k) + 1);

        ///// Centered /////
        int centered = k;

        ///// Record summary value /////
        long long record_sum_val = 0;

        ///// Result vector /////
        vector<int> res_vect(len_nums, (-1));


        /*Sliding-window based loop traversal*/
        ///// Step 1: Looped-traversal for the fixed-window size /////
        if (len_nums < total_diameter) { return res_vect; } //Issue, Boundary-case handling

        while (record_trav_ptr < total_diameter) //Fixed-window size
        {
            record_sum_val += nums[record_trav_ptr]; //Keep updating, accumulating

            (record_trav_ptr++); //Keep updating, traversing

        } //Fixed-window size

        ///// Step 2: Looped-traversal for the remainings /////
        res_vect[(centered++)] = (record_sum_val / total_diameter); //Update, Overwrite

        while (record_trav_ptr < len_nums) //Remainings
        {
            record_sum_val -= nums[(record_trav_ptr - total_diameter)]; //Keep updating, reducing

            record_sum_val += nums[record_trav_ptr]; //Keep updating, accumulating

            res_vect[(centered++)] = (record_sum_val / total_diameter); //Keep updating, overwriting

            (record_trav_ptr++); //Keep updating, traversing

        } //Remainings

        return res_vect;
    }
};
