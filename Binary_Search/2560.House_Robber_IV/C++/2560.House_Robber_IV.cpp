class Solution {
public:
    int minCapability(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th order)               //
        // Return type:                       //
        //   - int (result minimun capacity)  //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Sort-nums vector /////
        vector<int> sort_nums(nums.begin(), nums.end());

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_nums - 1);


        /*Binary-search based loop traversal*/
        sort(sort_nums.begin(), sort_nums.end()); //Sorted operations

        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            bool record_flag = robKth(nums, len_nums, k, sort_nums[record_mid_ptr]); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (record_flag) { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        return sort_nums[record_left_ptr];
    }


    bool robKth(vector<int> & nums, int & len_nums, int & k, int & record_val)
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums vector)  //
        //   - int ref (length of nums vector) //
        // Return type:                        //
        //   - int (result minimun capacity)   //
        //=====================================//

        /*Initialize*/
        ///// Record traversal pointer, summary counter /////
        int record_trav_ptr = 0, record_cnter = 0;

        /*Whole process, flow*/
        while (record_trav_ptr < len_nums) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (record_val >= nums[record_trav_ptr]) { (record_trav_ptr += 2); (record_cnter++); } //Keep updating, accumulating
            else { (record_trav_ptr++); } //Keep updating, traversing

        } //Whole

        return (record_cnter >= k) ? true : false;
    }
};
