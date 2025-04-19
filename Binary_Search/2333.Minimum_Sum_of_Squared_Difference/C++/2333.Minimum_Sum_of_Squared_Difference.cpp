class Solution {
public:
    long long minSumSquareDiff(vector<int> & nums1, vector<int> & nums2, int k1, int k2) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (nums1 vector)  //
        //   - vector<int> ref. (nums2 vector)  //
        //   - int (k1-th value)                //
        //   - int (k2-th value)                //
        // Return type:                         //
        //   - long long (result summary value) //
        //======================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums1.size();

        ///// Total of k-th value /////
        long long k_total = (static_cast<long long>(k1) + static_cast<long long>(k2));

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Result summary value /////
        long long res_sum_val = 0;


        /*Binary-search based loop traversal with recorded vector*/
        ///// Step 1: Record indexed-difference with vector /////
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            nums1[nums_idx] = abs((nums1[nums_idx] - nums2[nums_idx])); //Keep updating, overwriting

            record_right_ptr = (nums1[nums_idx] > record_right_ptr) ? nums1[nums_idx] : record_right_ptr; //Keep updating, overwriting

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        sort(nums1.begin(), nums1.end()); //Sorted-operations

        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            bool record_flag = isValid(len_nums, nums1, record_mid_ptr, k_total); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (record_flag) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        ///// Step 3: Post-process, Final completions /////
        if (! record_left_ptr) { return 0; } //Issue, Boundary-case handling

        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums1[nums_idx] > record_left_ptr)
            {
                k_total -= (nums1[nums_idx] - record_left_ptr); //Keep updating, reducing

                nums1[nums_idx] = record_left_ptr; //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        if (k_total > 0)
        {
            for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((nums1[nums_idx] == record_left_ptr) && (k_total > 0))
                {
                    ((nums1[nums_idx])--); (k_total--); //Keep updating, reducing
                }
                else { ; }

            } //Whole
        }
        else { ; }

        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            res_sum_val += (static_cast<long long>(nums1[nums_idx]) * static_cast<long long>(nums1[nums_idx])); //Keep updating, accumulating

        } //Whole

        return res_sum_val;
    }


    bool isValid(const int & len_nums, const vector<int> & nums1, const int & record_val, 
                 const long long & k_total)
    {
        //=============================================//
        // Input type:                                 //
        //   - const int ref. (length of nums vector)  //
        //   - const vector<int> ref. (nums1 vector)   //
        //   - const int ref. (record value)           //
        //   - const long long ref. (k-th total value) //
        // Return type:                                //
        //   - bool (result flag)                      //
        //=============================================//

        /*Initialize*/
        ///// Result summary value /////
        long long res_sum_val = 0;

        /*Whole process, flow*/
        for (int nums_idx = 0; (nums_idx < len_nums); (nums_idx++)) //Whole
        {
            res_sum_val += (nums1[nums_idx] <= record_val) ? 0 : (nums1[nums_idx] - record_val); //Keep updating, accumulating

            ///// Check if the current summary value matched conditions or not /////
            if (res_sum_val > k_total) { return false; }

        } //Whole

        return true;
    }
};
