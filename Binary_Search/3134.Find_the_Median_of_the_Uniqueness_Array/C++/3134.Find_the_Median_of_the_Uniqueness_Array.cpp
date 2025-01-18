class Solution {
public:
    int medianOfUniquenessArray(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result value)             //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        long long len_nums = nums.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 1, record_right_ptr = len_nums;

        ///// Total summary counter /////
        long long total_cnter = ((len_nums * (len_nums + 1)) / 2);

        ///// Middle index /////
        long long middle_idx = (total_cnter % 2) ? (total_cnter / 2) : ((total_cnter / 2) - 1);


        /*Binary-search based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            bool record_flag = uniqueKth(nums, len_nums, middle_idx, record_mid_ptr); //Record flag

            ///// Check if the current uniques matched conditions or not /////
            if (record_flag) { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }


    bool uniqueKth(const vector<int> & nums, const int & len_nums, const long long & middle_idx, const int & record_mid_ptr)
    {
        //============================================//
        // Input type:                                //
        //   - const vector<int> ref. (nums vector)   //
        //   - const int ref. (length of nums vector) //
        //   - const long long ref. (middle index)    //
        //   - const int ref. (record middle pointer) //            
        // Return type:                               //
        //   - bool (result flag)                     //
        //============================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Result summary counter /////
        long long res_cnter = 0;


        /*Whole process, flow*/
        while (record_right_ptr < len_nums) //Whole
        {
            ((record_map[nums[record_right_ptr]])++); //Keep updating, recording

            while (record_map.size() > record_mid_ptr) //Part
            {
                ((record_map[nums[record_left_ptr]])--); //Keep updating, reducing

                ///// Check if the current indexed-value matched conditions or not /////
                if (! record_map[nums[record_left_ptr]]) { record_map.erase(nums[record_left_ptr]); } //Keep updating, deleting
                else { ; }

                (record_left_ptr++); //Keep updating, traversing

            } //Part

            res_cnter += ((record_right_ptr - record_left_ptr) + 1); //Keep updating, accumulating

            ///// Check if the current summary counter matched conditions or not /////
            if (res_cnter > middle_idx) { return true; }

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return false;
    }
};
