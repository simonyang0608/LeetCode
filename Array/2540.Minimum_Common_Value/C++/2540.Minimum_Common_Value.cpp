class Solution {
public:
    int getCommon(vector<int> & nums1, vector<int> & nums2) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (nums1 vector)   //
        //   - vector<int> ref. (nums2 vector)   //
        // Return type:                          //
        //   - int (result minimun common value) //
        //=======================================//

        /*Initialize*/
        ///// Length of nums vector (i.e. nums1, nums2) /////
        int len_nums1 = nums1.size(), len_nums2 = nums2.size();

        ///// Record two-pointers (i.e. nums1, nums2) /////
        int record_nums1_ptr = 0, record_nums2_ptr = 0;

        ///// Record indexed-values (i.e. nums1, nums2) /////
        int record_nums1_val, record_nums2_val;


        /*Two-pointers based loop traversal*/
        while ((record_nums1_ptr < len_nums1) && (record_nums2_ptr < len_nums2)) //Whole
        {
            record_nums1_val = nums1[record_nums1_ptr]; //Record indexed-value (i.e. nums1)
            record_nums2_val = nums2[record_nums2_ptr]; //Record indexed-value (i.e. nums2)

            ///// Check if the current indexed-value matched conditions or not /////
            if (record_nums1_val < record_nums2_val) { (record_nums1_ptr++); } //Keep updating, accumulating
            else if (record_nums1_val == record_nums2_val) { return record_nums1_val; }

            else { (record_nums2_ptr++); } //Keep updating, accumulating

        } //Whole

        return (-1);
    }
};
