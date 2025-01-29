class Solution {
public:
    string minWindow(string s, string t) 
    {
        //============================//
        // Input type:                //
        //   - string (s string)      //
        //   - string (t string)      //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of strings (i.e. s, t) /////
        int len_s = s.size(), len_st = t.size();

        ///// Record dictionary, hashmap /////
        unordered_map<char, int> record_map;

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record length /////
        int record_length = 0;

        ///// Result minimun summary counter /////
        int res_min_cnter = (1e5 + 1);

        ///// Result minimun string /////
        string res_min_str;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-char with dictionary, hashmap /////
        for (int st_idx = 0; (st_idx < len_st); (st_idx++)) //Whole
        {
            ((record_map[t[st_idx]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        while (record_right_ptr < len_s) //Whole
        {
            ///// Check if the current indexed-char existed or not /////
            if ((--(record_map[s[record_right_ptr]])) >= 0) { (record_length++); } //Keep updating, accumulating
            else { ; }

            while (record_length >= len_st) //Part
            {
                ///// Check if the current indexed-char retrieved or not /////
                if ((++(record_map[s[record_left_ptr]])) > 0)
                {
                    ///// Check if the current window-size is smaller or not /////
                    if ((record_right_ptr - record_left_ptr + 1) < res_min_cnter)
                    {
                        res_min_cnter = (record_right_ptr - record_left_ptr + 1); //Keep updating, overwriting

                        res_min_str = s.substr(record_left_ptr, res_min_cnter); //Keep updating, overwriting
                    }
                    else { ; }

                    (record_length--); //Keep updating, reducing
                }
                else { ; }

                (record_left_ptr++); //Keep updating, traversing

            } //Part

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_min_str;
    }   
};
