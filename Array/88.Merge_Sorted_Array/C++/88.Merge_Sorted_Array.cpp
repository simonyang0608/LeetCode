class Solution {
public:
    void merge(vector<int> & nums1, int m, vector<int> & nums2, int n) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (nums1 vector) //
        //   - int (m-th order)                //
        //   - vector<int> ref. (nums2 vector) //
        //   - int (n-th order)                //
        // Return type:                        //
        //   - void (no return)                //
        //=====================================//

        /*Initialize*/
        ///// Pointers (i.e. nums1, nums2 vectors) /////
        int nums1_ptr = 0, nums2_ptr = 0;

        /*Two-pointers based loop traversal*/
        ///// Step 1: Remove the last n-th value from vector /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th
        {
            nums1.pop_back(); //Keep updating, popped

        } //N-th

        ///// Step 2: Looped-traversal for the updated vector /////
        while ((nums1_ptr < nums1.size()) && (nums2_ptr < n)) //Intervals
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (nums1[nums1_ptr] > nums2[nums2_ptr])
            {
                nums1.insert((nums1.begin() + nums1_ptr), nums2[nums2_ptr]); //Keep updating, recording

                (nums2_ptr++); //Keep updating, traversing
            }
            else { ; }

            (nums1_ptr++); //Keep updating, traversing

        } //Intervals

        ///// Step 3: Post-process, Final completions /////
        while (nums2_ptr < n) //Remainings
        {
            nums1.emplace_back(nums2[nums2_ptr]); //Keep updating, recording

            (nums2_ptr++); //Keep updating, traversing

        } //Remainings
    }
};
