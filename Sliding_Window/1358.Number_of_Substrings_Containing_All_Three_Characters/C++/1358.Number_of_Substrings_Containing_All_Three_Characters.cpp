class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        //==================================//
        // Input type:                      //
        //   - string (s string)            //
        // Return type:                     //
        //   - int (result summary counter) //
        //==================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        while (record_right_ptr < len_s) //Right pointer
        {
            ((record_map[s[record_right_ptr]])++); //Keep updating, recording

            ///// Check if the current size matched conditions or not /////
            if (record_map.size() >= 3)
            {
                while (record_map.size() >= 3) //Part
                {
                    ((record_map[s[record_left_ptr]])--); //Keep updating, reducing

                    ///// Check if the current summary counter is zero or not /////
                    if (! record_map[s[record_left_ptr]]) { record_map.erase(s[record_left_ptr]); } //Keep updating, deleting
                    else { ; }

                    (record_left_ptr++); //Keep updating, traversing

                } //Part
            }
            else { ; }

            res_cnter += record_left_ptr; //Keep updating, accumulating

            (record_right_ptr++); //Keep updating, traversing

        } //Right pointer

        return res_cnter;
    }
};
