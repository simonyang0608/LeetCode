class Solution {
public:
    vector<int> findAnagrams(string s, string p) 
    {
        //=================================//
        // Input type:                     //
        //   - string (s string)           //
        //   - string (p string)           //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// Length of strings (i.e. s, p) /////
        int len_s = s.size(), len_p = p.size();

        ///// Record dictionary, hashmap /////
        unordered_map<char, int> record_map;

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record length /////
        int record_length = 0;

        ///// Result vector /////
        vector<int> res_vect;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-char with dictionary, hashmap /////
        if (len_p > len_s) { return res_vect; } //Issue, Boundary-case handling

        for (int p_idx = 0; (p_idx < len_p); (p_idx++)) //Whole
        {
            ((record_map[p[p_idx]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap
        while (record_right_ptr < len_s) //Whole
        {
            ///// Check if the current indexed-char existed or not /////
            if ((--(record_map[s[record_right_ptr]]) >= 0)) { (record_length++); } //Keep updating, accumulating
            else { ; }

            while (record_length >= len_p) //Part
            {
                ///// Check if the current indexed-char retrieved or not /////
                if ((++(record_map[s[record_left_ptr]])) > 0)
                {
                    ///// Check if the current window-size matched conditions or not /////
                    if ((record_right_ptr - record_left_ptr + 1) == len_p) { res_vect.emplace_back(record_left_ptr); } //Keep updating, recording
                    else { ; }

                    (record_length--); //Keep updating, reducing
                }
                else { ; }

                (record_left_ptr++); //Keep updating, traversing

            } //Part

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_vect;
    }
};
