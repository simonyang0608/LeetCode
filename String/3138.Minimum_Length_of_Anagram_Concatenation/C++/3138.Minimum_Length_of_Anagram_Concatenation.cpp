class Solution {
public:
    int minAnagramLength(string s) 
    {
        //=================================//
        // Input type:                     //
        //   - string (s string)           //
        // Return type:                    //
        //   - int (result minimun length) //
        //=================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size(); 

        /*Vector-counting based loop traversal*/
        for (int s_idx = 1; (s_idx <= len_s); (s_idx++)) //Whole
        {
            ///// Check if the current length is dividable or not /////
            if ((len_s % s_idx)) { continue; }

            ///// Check if it's the minimun concatenated-anagrams or not /////
            if (isConcateAnag(len_s, s, s_idx)) { return s_idx; }

        } //Whole

        return len_s;
    }


    bool isConcateAnag(const int & len_s, const string & s, const int & record_cnter)
    {
        //=============================================//
        // Input type:                                 //
        //   - const int ref. (length of s string)     //
        //   - const string ref. (s string)            //
        //   - const int ref. (record summary counter) //
        // Return type:                                //
        //   - bool (result flag)                      //
        //=============================================//

        /*Initialize*/
        ///// Record vector /////
        vector<int> record_vect(26, 0);

        ///// Record string /////
        string record_str = s.substr(0, record_cnter);


        /*Whole process, flow*/
        ///// Step 1: Looped-traversal for the fixed-window size
        for (const char & record_chr: record_str) { ((record_vect[(record_chr - 'a')])++); } //Keep updating, recording

        ///// Step 2: Looped-traversal for the remainings /////
        for (int record_idx = record_cnter; (record_idx < len_s); (record_idx += record_cnter)) //Remainings
        {
            vector<int> sub_vect(26, 0); //Sub vector

            record_str = s.substr(record_idx, record_cnter); //Keep updating, overwriting

            for (const char & record_chr: record_str) { ((sub_vect[(record_chr - 'a')])++); } //Keep updating, recording

            ///// Check if the current vector matched conditions or not /////
            if (record_vect != sub_vect) { return false; }

        } //Remainings

        return true;
    }
};
