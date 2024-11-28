class Solution {
public:
    string convert(string s, int numRows) 
    {
        //============================//
        // Input type:                //
        //   - string (s string)      //
        //   - int (number of rows)   //
        // Return type:               //
        //   - string (result string) //
        //============================//
        if (numRows == 1) { return s; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record traversal pointer, indexed-row /////
        int record_trav_ptr, record_row_idx = 0;

        ///// Result string /////
        string res_str;


        /*One-pass loop traversal*/
        while ((record_row_idx < len_s) && (record_row_idx < numRows)) //N-th rows
        {
            record_trav_ptr = record_row_idx; //Record traversal pointer

            while (record_trav_ptr < len_s) //Whole
            {
                res_str += s[record_trav_ptr]; //Keep updating, recording

                record_trav_ptr += ((numRows - record_row_idx) - 1); //Keep updating, traversing

                ///// Check if the current indexed-row matched conditions or not /////
                if (! record_row_idx) { record_trav_ptr += ((numRows - record_row_idx) - 1); } //Keep updating, traversing

                else if (record_row_idx == (numRows - 1))
                {
                    record_trav_ptr += (2 * record_row_idx); //Keep updating, traversing
                }

                else
                {
                    record_trav_ptr += ((numRows - record_row_idx) - 1); //Keep updating, traversing

                    ///// Check if the current indexed-pointer exceed boundary or not /////
                    if (record_trav_ptr >= len_s) { break; }

                    res_str += s[record_trav_ptr]; //Keep updating, recording

                    record_trav_ptr += (2 * record_row_idx); //Keep updating, traversing
                }

            } //Whole

            (record_row_idx++); //Keep updating, traversing

        } //N-th rows

        return res_str;
    }
};
