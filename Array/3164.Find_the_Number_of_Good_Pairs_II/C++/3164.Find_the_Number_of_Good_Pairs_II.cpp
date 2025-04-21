class Solution {
public:
    long long numberOfPairs(vector<int> & nums1, vector<int> & nums2, int k) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<int> ref. (nums1 vector)    //
        //   - vector<int> ref. (nums2 vector)    //
        //   - int (k-th value)                   //
        // Return type:                           //
        //   - long long (result summary counter) //
        //========================================//

        /*Initialize*/
        ///// Length of vectors (i.e. nums1, nums2) /////
        int len_nums1 = nums1.size(), len_nums2 = nums2.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Result summary counter /////
        long long res_cnter = 0;


        /*Hashmap-based loop traversal*/
        ///// Step 1: Record indexed-value informations with dictionary, hashmap /////
        for (int nums1_idx = 0; (nums1_idx < len_nums1); (nums1_idx++)) //Whole
        {
            int record_val = nums1[nums1_idx]; //Record value

            for (int record_idx = 1; ((record_idx * record_idx) <= record_val); (record_idx++)) //Part
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((record_idx * record_idx) == record_val) { ((record_map[record_idx])++); } //Keep updating, recording

                else if (! (record_val % record_idx))
                {
                    ((record_map[(record_val / record_idx)])++); //Keep updating, recording
                    ((record_map[record_idx])++); //Keep updating, recording
                }
                else { ; }

            } //Part

        } //Whole

        ///// Step 2: Looped-traversal for the recorded dictionary, hashmap /////
        for (int nums2_idx = 0; (nums2_idx < len_nums2); (nums2_idx++)) //Whole
        {
            int record_prod = (nums2[nums2_idx] * k); //Record product

            ///// Check if the current indexed-value existed or not /////
            if ((record_map[record_prod])) { res_cnter += (record_map[record_prod]); } //Keep updating, accumulating
            else { ; }

        } //Whole

        return res_cnter;
    }
};
