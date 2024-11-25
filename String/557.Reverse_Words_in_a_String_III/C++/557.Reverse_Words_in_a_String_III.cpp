class Solution {
public:
    string reverseWords(string s) 
    {
        //============================//
        // Input type:                //
        //   - string (s string)      //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of s atring /////
        int len_s = s.size();

        ///// Record vector /////
        vector<char> record_vect;

        for (int record_idx = 0; (record_idx < len_s); (record_idx++))
        {
            record_vect.emplace_back(s[record_idx]);
        }

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record window /////
        int record_wdw;

        ///// Result string /////
        string res_str;


        /*Two-pointers based loop traversal*/
        ///// Step 1: Looped-traversal /////
        while (record_right_ptr < len_s) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (((record_right_ptr + 1) >= len_s) || (record_vect[(record_right_ptr + 1)] == ' '))
            {
                record_wdw = (((record_right_ptr + 1) - record_left_ptr) / 2); //Record window

                for (int record_idx = 0; (record_idx < record_wdw); (record_idx++)) //Halfed-window
                {
                    swap(record_vect[(record_left_ptr++)], record_vect[(record_right_ptr - record_idx)]); //Keep updating, swap

                } //Halfed-window

                record_right_ptr += 2; //Keep updating, traversing
                record_left_ptr = record_right_ptr; //Keep updating, overwriting
            }

            else
            {
                (record_right_ptr++); //Keep updating, traversing
            }

        } //Whole

        ///// Step 2: Post-process, Final completions /////
        for (int record_idx = 0; (record_idx < len_s); (record_idx++)) //Whole
        {
            res_str += record_vect[record_idx]; //Keep updating, overwriting

        } //Whole

        return res_str;
    }
};
