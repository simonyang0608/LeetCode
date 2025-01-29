class Solution {
public:
    bool checkInclusion(string s1, string s2) 
    {
        //========================//
        // Input type:            //
        //   - string (s1 string) //
        //   - string (s2 string) //
        // Return type:           //
        //   - bool (result flag) //
        //========================//

        /*Initialize*/
        ///// Length of strings (i.e. s1, s2) /////
        int len_s1 = s1.size(), len_s2 = s2.size();

        if (len_s1 > len_s2) { return false; } //Issue, Boundary-case handling

        ///// Record dictionary, hashmap /////
        unordered_map<char, int> record_map;

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record length /////
        int record_length = 0;

        ///// Result minimun summary counter /////
        int res_min_cnter = (1e4 + 1);


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-char with dictionary, hashmap /////
        for (int s1_idx = 0; (s1_idx < len_s1); (s1_idx++)) //Whole
        {
            ((record_map[s1[s1_idx]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap*/
        while (record_right_ptr < len_s2) //Whole
        {
            ///// Check if the current indexed-char existed or not /////
            if ((--(record_map[s2[record_right_ptr]])) >= 0) { (record_length++); } //Keep updating, accumulating
            else { ; }

            while (record_length >= len_s1) //Part
            {
                ///// Check if the current indexed-char retrieved or not /////
                if ((++(record_map[s2[record_left_ptr]])) > 0)
                {
                    ///// Check if the current window-size is smaller or not /////
                    if ((record_right_ptr - record_left_ptr + 1) < res_min_cnter)
                    {
                        res_min_cnter = (record_right_ptr - record_left_ptr + 1); //Keep updating, overwriting
                    }
                    else { ; }

                    (record_length--); //Keep updating, reducing
                }
                else { ; }

                (record_left_ptr++); //Keep updating, traversing

            } //Part

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return (res_min_cnter == len_s1) ? true : false;
    }
};
