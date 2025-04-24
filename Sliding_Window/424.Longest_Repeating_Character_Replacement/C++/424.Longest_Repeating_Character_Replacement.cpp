class Solution {
public:
    int characterReplacement(string s, int k) 
    {
        //=================================//
        // Input type:                     //
        //   - string (s string)           //
        //   - int (k-th times)            //
        // Return type:                    //
        //   - int (result maximun length) //
        //=================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record dictionary, hashmap /////
        unordered_map<char, int> record_map;

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record maximun summary counter /////
        int record_max_cnter = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        while (record_right_ptr < len_s) //Whole
        {
            ((record_map[s[record_right_ptr]])++); //Keep updating, accumulating

            record_max_cnter = (record_map[s[record_right_ptr]] > record_max_cnter) ? 
                                record_map[s[record_right_ptr]] : record_max_cnter; //Keep updating, overwriting

            ///// Check if the current length matched conditions or not /////
            if (((record_right_ptr - record_left_ptr + 1) - record_max_cnter) > k)
            {
                ((record_map[s[record_left_ptr]])--); (record_left_ptr++); //Keep updating, traversing
            }
            else { ; }

            res_max_cnter = ((record_right_ptr - record_left_ptr + 1) > res_max_cnter) ?
                             (record_right_ptr - record_left_ptr + 1) : res_max_cnter; //Keep updating, overwriting

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_max_cnter;
    }
};
