class Solution {
public:
    int maxDistance(vector<int> & nums1, vector<int> & nums2) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums1 vector) //
        //   - vector<int> ref. (nums2 vector) //
        // Return type:                        //
        //   - int (result maximun distance)   //
        //=====================================//

        /*Initialize*/
        ///// Length of nums1 vector /////
        int len_nums1 = nums1.size();

        ///// Result maximun distance /////
        int res_max_dist = 0;


        /*Binary-search based loop traversal*/
        for (int nums1_idx = 0; (nums1_idx < len_nums1); (nums1_idx++)) //Whole
        {
            binarySearch(nums2, nums1_idx, nums1[nums1_idx], res_max_dist); //Binary-search function call

        } //Whole

        return res_max_dist;
    }


    void binarySearch(vector<int> & nums2, int & record_idx, int & record_val, int & res_max_dist)
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums2 vector)    //
        //   - int ref. (record index)            //
        //   - int ref. (record value)            //
        //   - int ref. (result maximun distance) //
        // Return type:                           //
        //   - int (result maximun distance)      //
        //========================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right, middle) /////
        int record_mid_ptr, record_left_ptr = 0, record_right_ptr = (nums2.size() - 1);

        /*Whole process, flow*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Keep updating, overwriting

            ///// Check if the current indexed-value matched conditions or not /////
            if (nums2[record_mid_ptr] >= record_val)
            {
                ///// Check if the current indexes matched conditions or not /////
                if (record_mid_ptr >= record_idx) { res_max_dist = max(res_max_dist, (record_mid_ptr - record_idx)); } //Keep updating, overwriting
                else { ; }

                record_left_ptr = (record_mid_ptr + 1); //Keep updating, overwriting
            }
            else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
        }

    } //Binary-search
};
