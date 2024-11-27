class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        //==========================================//
        // Input type:                              //
        //   - string (s string)                    //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record dictionary, hashmap /////
        unordered_map<char, bool> record_map;

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Two-pointers based loop traversal with recorded dictionary, hashmap*/
        while (record_right_ptr < len_s) //Whole
        {
            ///// Check if the current indexed-char existed or not /////
            if (record_map.find(s[record_right_ptr]) == record_map.end())
            {
                res_max_cnter = max(res_max_cnter, ((record_right_ptr - record_left_ptr) + 1)); //Keep updating, overwriting

                record_map[s[(record_right_ptr++)]] = true; //Keep updating, recording
            }

            else
            {
                res_max_cnter = max(res_max_cnter, (record_right_ptr - record_left_ptr)); //Keep updating, overwriting

                while (record_left_ptr < record_right_ptr) //Part
                {
                    record_map.erase(s[(record_left_ptr++)]); //Keep updating, erase

                    ///// Check if the current indexed-char existed or not /////
                    if (record_map.find(s[record_right_ptr]) == record_map.end()) { break; }
                    else { ; }

                } //Part
            }

        } //Whole

        return res_max_cnter;
    }
};
