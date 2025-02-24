class Solution {
public:
    string countAndSay(int n) 
    {
        //============================//
        // Input type:                //
        //   - int (n-th order)       //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Record string /////
        string record_str = "1";

        ///// Result string /////
        string res_str = record_str;


        /*String-based loop traversal*/
        for (int n_idx = 2; (n_idx <= n); (n_idx++)) //N-th times
        {
            ///// Check if the current string is empty or not /////
            if (! res_str.empty()) { res_str.clear(); } //Keep updating, reset
            else { ; }

            int record_trav_ptr = 0; int len_str = record_str.size(); //Record traversal pointer, length of string

            while (record_trav_ptr < len_str) //Whole
            {
                int record_cnter = 1; //Record summary counter

                while (((record_trav_ptr + 1) < len_str) && (record_str[record_trav_ptr] == record_str[(record_trav_ptr + 1)])) //Part
                {
                    (record_cnter++); (record_trav_ptr++); //Keep updating, traversing
                }

                res_str += (to_string(record_cnter) + record_str[record_trav_ptr]); //Keep updating, accumulating

                (record_trav_ptr++); //Keep updating, traversing

            } //Whole

            record_str = res_str; //Keep updating, overwriting

        } //N-th times

        return res_str;
    }
};
