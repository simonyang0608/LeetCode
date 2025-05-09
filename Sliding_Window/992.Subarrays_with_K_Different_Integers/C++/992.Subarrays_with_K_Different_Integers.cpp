class Solution {
public:
    int subarraysWithKDistinct(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th differences)         //
        // Return type:                       //
        //   - int (result summary counter)   //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        return (sldWindow(len_nums, nums, k) - sldWindow(len_nums, nums, (k - 1)));
    }


    int sldWindow(const int & len_nums, const vector<int> & nums, int k)
    {
        //============================================//
        // Input type:                                //
        //   - const int ref. (length of nums vector) //
        //   - const vector<int> ref. (nums vector)   //
        //   - int (k-th differences)                 //
        // Return type:                               //
        //   - int (result summary counter)           //
        //============================================//

        /*Initialize*/
        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        while (record_right_ptr < len_nums) //Whole
        {
            ///// Check if the current summary counter matched conditions or not /////
            if ((++(record_map[nums[record_right_ptr]])) == 1) { (record_cnter++); } //Keep updating, accumulating
            else { ; }

            while (record_cnter > k) //Part
            {
                ///// Check if the current summary counter matched conditions or not /////
                if (! (--(record_map[nums[record_left_ptr]]))) { (record_cnter--); } //Keep updating, reducing
                else { ; }

                (record_left_ptr++); //Keep updating, traversing
            }

            res_max_cnter += (record_right_ptr - record_left_ptr + 1); //Keep updating, accumulating

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_max_cnter;
    }
};
