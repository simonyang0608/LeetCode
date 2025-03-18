class Solution {
public:
    bool isSubsequence(string s, string t)
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

        ///// Record traversal pointers (i.e. s, t) /////
        int record_trav_ptrs = 0, record_trav_ptrt = 0;


        /*Two-pointers based loop traversal*/
        while (record_trav_ptrt < len_ts) //Whole
        {
            ///// Check if the current indexed-char is the same or not /////
            if ((record_trav_ptrs < len_s) && (s[record_trav_ptrs] == t[record_trav_ptrt])) { (record_trav_ptrs++); } //Keep updating, traversing
            else { ; }

            (record_trav_ptrt++); //Keep updating, traversing

        } //Whole

        return (record_trav_ptrs >= len_s) ? true : false;   
    }
};
