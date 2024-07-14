class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        //==========================//
        // Input type:              //
        //   - string (s string)    //
        //   - string (goal string) //
        // Return type:             //
        //   - bool (result flag)   //
        //==========================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record indexed-string /////
        string record_str;


        /*Greedy-based loop traversal with recorded pointer*/
        while (record_trav_ptr < len_s) //Whole
        {
            s += (s[(record_trav_ptr++)]); //Keep updating, accumulating

            record_str = s.substr(record_trav_ptr, len_s); //Record indexed-string

            ///// Check if the current indexed-string matched conditions or not /////
            if (! (record_str.compare(goal))) { return true; }
            else { ; }

        } //Whole

        return false;
    }
};
