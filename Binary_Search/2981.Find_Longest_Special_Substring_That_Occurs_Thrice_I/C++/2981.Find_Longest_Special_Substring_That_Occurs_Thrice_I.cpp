class Solution {
public:
    int maximumLength(string s) 
    {
        //=================================//
        // Input type:                     //
        //   - string (s string)           //
        // Return type:                    //
        //   - int (result maximun length) //
        //=================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_s - 2);

        
        /*Binary-search based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) / 2); //Record middle pointer

            bool record_flag = occurThrice(len_s, s, record_mid_ptr); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (record_flag) { record_left_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

        } //Binary-search

        return (! record_left_ptr) ? (-1) : record_left_ptr;
    }


    bool occurThrice(const int & len_s, const string & s, const int & record_mid_ptr)
    {
        //============================================//
        // Input type:                                //
        //   - const int ref. (length of s string)    //
        //   - const string ref. (s string)           //
        //   - const int ref. (record middle pointer) //
        // Return type:                               //
        //   - bool (result flag)                     //
        //============================================//

        /*Initialize*/
        ///// Record dictionary, hashmap /////
        unordered_map<string, int> record_map;

        /*Whole process, flow*/
        ///// Step 1: Record indexed-string with dictionary, hashmap /////
        for (int record_idx = 0; (record_idx <= (len_s - record_mid_ptr)); (record_idx++)) //Whole
        {
            ((record_map[(s.substr(record_idx, record_mid_ptr))])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the recorded dictionary, hashmap /////
        for (auto record_ele = record_map.begin(); (record_ele != record_map.end()); (record_ele++)) //Whole
        {
            set<char> record_set((record_ele->first).begin(), (record_ele->first).end()); //Record set

            ///// Check if the current string is specialized or not /////
            if (record_set.size() != 1) { continue; }

            ///// Check if the current summary counter matched conditions or not /////
            if ((record_ele->second) >= 3) { return true; }

        } //Whole

        return false;
    }
};
