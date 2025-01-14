class Solution {
public:
    int smallestDistancePair(vector<int> & nums, int k) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        //   - int (k-th order)               //
        // Return type:                       //
        //   - int (result distance value)    //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        ///// Record pointers (i.e. left, right) /////
        int record_right_ptr, record_left_ptr = 0;

        
        /*Binary-search based loop traversal*/
        sort(nums.begin(), nums.end()); record_right_ptr = (nums.back() - nums.front()); //Sorted operations

        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            bool record_flag = distKth(nums, len_nums, k, record_mid_ptr); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (record_flag) { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }


    bool distKth(vector<int> & nums, int & len_nums, int & k, int & record_val)
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (nums vector)   //
        //   - int ref. (length of nums vector) //
        //   - int ref. (k-th order)            //
        //   - int ref. (record value)          //
        // Return type:                         //
        //   - bool (result flag)               //
        //======================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 1;

        ///// Record summary counter /////
        int record_cnter = 0;


        /*Whole process, flow*/
        while (record_right_ptr < len_nums) //Whole
        {
            ///// Check if the current distance difference matched conditions or not #####
            if ((nums[record_right_ptr] - nums[record_left_ptr]) <= record_val) { ; }
            else
            {
                while ((record_left_ptr < record_right_ptr) && ((nums[record_right_ptr] - nums[record_left_ptr]) > record_val)) //Part
                {
                    (record_left_ptr++); //Keep updating, traversing

                } //Part
            }

            record_cnter += (record_right_ptr - record_left_ptr); //Keep updating, accumulating

            ///// Check if the current summary counter exceeds k-th order or not /////
            if (record_cnter >= k) { return true; }

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return false;
    }
};
