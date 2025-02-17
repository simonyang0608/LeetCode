class Solution {
public:
    double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums1 vector) //
        //   - vector<int> ref. (nums2 vector) //
        // Return type:                        //
        //   - double (result value)           //
        //=====================================//

        /*Initialize*/
        ///// Length of vectors (i.e. nums1, nums2) /////
        int len_nums1 = nums1.size(), len_nums2 = nums2.size();

        ///// Length of total vectors /////
        int len_total = (len_nums1 + len_nums2);

        ///// Record pointers (i.e. left, right) /////
        int record_nums1_ptr = 0, record_nums2_ptr = 0;

        ///// Result vector /////
        vector<int> res_vect;

        ///// Result value /////
        double res_val = 0;


        /*Merge-sort based loop traversal with recorded vector*/
        ///// Step 1: Looped-traversal for the first intervals /////
        while ((record_nums1_ptr < len_nums1) && (record_nums2_ptr < len_nums2)) //Intervals
        {
            ///// Check if the current indexed-value is smaller or not /////
            if (nums1[record_nums1_ptr] < nums2[record_nums2_ptr]) { res_vect.emplace_back(nums1[(record_nums1_ptr++)]); } //Keep updating, recording
            else { res_vect.emplace_back(nums2[(record_nums2_ptr++)]); } //Keep updating, recording

        } //Intervals

        ///// Step 2: Looped-traversal for the rest remainings /////
        while (record_nums1_ptr < len_nums1) //Remainings
        {
            res_vect.emplace_back(nums1[(record_nums1_ptr++)]); //Keep updating, recording

        } //Remainings

        while (record_nums2_ptr < len_nums2) //Remainings
        {
            res_vect.emplace_back(nums2[(record_nums2_ptr++)]); //Keep updating, recording

        } //Remainings

        return (! (len_total % 2)) ? (static_cast<double>((res_vect[(len_total / 2)] + res_vect[((len_total / 2) - 1)])) / 2) :
                                      static_cast<double>(res_vect[(len_total / 2)]);
    }
};
