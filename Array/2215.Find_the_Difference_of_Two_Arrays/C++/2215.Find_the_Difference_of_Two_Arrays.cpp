class Solution {
public:
    vector<vector<int>> findDifference(vector<int> & nums1, vector<int> & nums2) 
    {
        //=========================================//
        // Input type:                             //
        //   - vector<int> ref. (nums1 vector)     //
        //   - vector<int> ref. (nums2 vector)     //
        // Return type:                            //
        //   - vector<vector<int>> (result vector) //
        //=========================================//

        /*Initialize*/
        ///// Length of nums vectors (i.e. 1, 2) /////
        int len_nums1 = nums1.size(), len_nums2 = nums2.size();

        ///// Record dictionary, hashmaps (i.e. 1, 2) /////
        unordered_map<int, bool> record_map1, record_map2;

        ///// Result vectors (i.e. 1, 2) /////
        vector<int> res_vect1, res_vect2;


        /*Hashmap-based loop traversal*/
        ///// Step 1: Record indexed-value with dictionary, hashmaps /////
        for (int nums1_idx = 0; (nums1_idx < len_nums1); (nums1_idx++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map1[nums1[nums1_idx]]) { continue; }

            record_map1[nums1[nums1_idx]] = true; //Keep updating, recording

        } //Whole

        for (int nums2_idx = 0; (nums2_idx < len_nums2); (nums2_idx++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map2[nums2[nums2_idx]]) { continue; }

            record_map2[nums2[nums2_idx]] = true; //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the recorded dictionary, hashmaps /////
        for (auto record_ele = record_map1.begin(); (record_ele != record_map1.end()); (record_ele++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map2[(record_ele->first)]) { continue; }

            res_vect1.emplace_back((record_ele->first)); //Keep updating, recording

        } //Whole

        for (auto record_ele = record_map2.begin(); (record_ele != record_map2.end()); (record_ele++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map1[(record_ele->first)]) { continue; }

            res_vect2.emplace_back((record_ele->first)); //Keep updating, recording
             
        } //Whole

        return {res_vect1, res_vect2};
    }
};
