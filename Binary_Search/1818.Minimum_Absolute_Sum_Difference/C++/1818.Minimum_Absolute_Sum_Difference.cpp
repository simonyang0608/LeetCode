class Solution {
public:
    int minAbsoluteSumDiff(vector<int> & nums1, vector<int> & nums2) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums1 vector)    //
        //   - vector<int> ref. (nums2 vector)    //
        // Return type:                           //
        //   - int (result minimun summary value) //
        //========================================//

        /*Initialize*/
        ///// Length of totals /////
        int len_total = nums1.size();

        ///// Sorted vector (i.e. nums1) /////
        vector<int> sort_nums1(nums1.begin(), nums1.end());

        ///// Record module /////
        int record_module = (1e9 + 7);

        ///// Record summary value /////
        long long record_sum_val = 0;

        ///// Result minimun summary value /////
        long long res_min_sum;


        /*Binary-search based loop traversal*/
        ///// Step 1: Record indexed-differences values /////
        sort(sort_nums1.begin(), sort_nums1.end()); //Sorted-operations

        for (int record_idx = 0; (record_idx < len_total); (record_idx++)) //Whole
        {
            record_sum_val += abs((nums1[record_idx] - nums2[record_idx])); //Keep updating, accumulating

        } //Whole

        ///// Step 2: Looped-traversal with recorded summary value /////
        res_min_sum = record_sum_val; //Update, Overwrite

        for (int record_idx = 0; (record_idx < len_total); (record_idx++)) //Whole
        {
            long long curr_sum_val = (record_sum_val - abs((nums1[record_idx] - nums2[record_idx]))); //Current summary value

            int record_min_diff = binarySearch(len_total, sort_nums1, nums2[record_idx]); //Record minimun difference

            curr_sum_val += record_min_diff; //Keep updating, accumulating

            res_min_sum = (curr_sum_val < res_min_sum) ? curr_sum_val : res_min_sum; //Keep updating, overwriting

        } //Whole

        return (res_min_sum % record_module);
    }


    int binarySearch(const int & len_total, const vector<int> & sort_nums1, const int & curr_val)
    {
        //==================================================//
        // Input type:                                      //
        //   - const int ref. (length of totals)            //
        //   - const vector<int> ref. (sorted nums1 vector) //
        //   - const int ref. (current value)               //
        // Return type:                                     //
        //   - int (result minimun difference)              //
        //==================================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_total - 1);

        ///// Result minimun difference /////
        int res_min_diff = INT_MAX;


        /*Whole process, flow*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            res_min_diff = min(abs((sort_nums1[record_mid_ptr] - curr_val)), res_min_diff); //Keep updating, overwriting

            ///// Check if the current indexed-value matched conditions or not /////
            if (sort_nums1[record_mid_ptr] > curr_val) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        return res_min_diff;
    }
};
