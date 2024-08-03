class Solution {
public:
    string addSpaces(string s, vector<int> & spaces) 
    {
        //======================================//
        // Input type:                          //
        //   - string (s string)                //
        //   - vector<int> ref. (spaces vector) //
        // Return type:                         //
        //   - string (result string)           //
        //======================================//

        /*Initialize*/
        ///// Length of s string, spaces vector /////
        int len_s = s.size(), len_spaces = spaces.size();

        ///// Record traversal pointers (i.e. s, spaces) /////
        int record_ptr_s = 0, record_ptr_spaces = 0;

        ///// Record space-values /////
        int record_space;

        ///// Result string /////
        string res_str;


        /*Two-pointers based loop traversal*/
        ///// Step 1: Looped-traversal for whole-cycle spaces /////
        while (record_ptr_spaces < len_spaces) //Whole
        {
            record_space = spaces[(record_ptr_spaces++)]; //Record space-values

            while (record_ptr_s < record_space) //Part
            {
                res_str += s[(record_ptr_s++)]; //Keep updating, overwriting

            } //Part

            res_str += ' '; //Keep updating, overwriting

        } //Whole

        ///// Step 2: Looped-traversal for remained-string /////
        while (record_ptr_s < len_s) //Part
        {
            res_str += s[(record_ptr_s++)]; //Keep updating, overwriting

        } //Part

        return res_str;
    }
};
