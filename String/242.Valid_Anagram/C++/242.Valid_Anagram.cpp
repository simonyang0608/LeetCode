class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        //========================//
        // Input type:            //
        //   - string (s string)  //
        //   - string (t string)  //
        // Return type:           //
        //   - bool (result flag) //
        //========================//

        /*Initialize*/
        ///// Length of strings (i.e. s, t) /////
        int len_s = s.size(), len_ts = t.size();

        ///// Record vectors (i.e. s, t) /////
        vector<int> record_vect_s(26, 0), record_vect_ts(26, 0);


        /*Two-pass record based loop traversal*/
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ((record_vect_s[(s[s_idx] - 'a')])++); //Keep updating, recording

        } //Whole

        for (int t_idx = 0; (t_idx < len_ts); (t_idx++)) //Whole
        {
            ((record_vect_ts[(t[t_idx] - 'a')])++); //Keep updating, recording

        } //Whole

        return (record_vect_s == record_vect_ts) ? true : false;
    }
};
