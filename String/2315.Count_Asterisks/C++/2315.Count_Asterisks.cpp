class Solution {
public:
    int countAsterisks(string s) 
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

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*One-pass record based loop traversal*/
        while (record_trav_ptr < len_s) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (s[record_trav_ptr] == '|')
            {
                while (((record_trav_ptr + 1) < len_s) && (s[(record_trav_ptr + 1)] != '|')) { (record_trav_ptr++); } //Keep updating, traversing

                record_trav_ptr += 2; //Keep updating, traversing
            }

            else
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if (s[record_trav_ptr] == '*') { (res_cnter++); } //Keep updating, accumulating
                else { ; }

                (record_trav_ptr++); //Keep updating, traversing
            }

        } //Whole

        return res_cnter;
    }
};
