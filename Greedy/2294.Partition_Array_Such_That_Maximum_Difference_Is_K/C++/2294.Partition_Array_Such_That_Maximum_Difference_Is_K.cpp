class Solution {
public:
    int partitionArray(vector<int> & nums, int k) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (nums vector)       //
        //   - int (k-th threshold)                 //
        // Return type:                             //
        //   - int (result minimun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result minimun summary counter /////
        int res_min_cnter = 0;


        /*Greedy-based loop traversal*/
        sort(nums.begin(), nums.end()); //Sorted operations

        while (record_trav_ptr < len_nums) //Whole
        {
            int record_val = nums[record_trav_ptr]; //Record value

            (res_min_cnter++); //Keep updating, accumulating

            while (((record_trav_ptr + 1) < len_nums) && ((nums[(record_trav_ptr + 1)] - record_val) <= k)) //Part
            {
                (record_trav_ptr++); //Keep updating, traversing

            } //Part

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_min_cnter;
    }
};
