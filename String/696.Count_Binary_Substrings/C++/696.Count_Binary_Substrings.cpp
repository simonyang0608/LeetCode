class Solution {
public:
    int countBinarySubstrings(string s) 
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

        ///// Record summary counters (i.e. 0s, 1s) /////
        int record_cnter_zeros = 0, record_cnter_ones = 0;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Greedy-based loop traversal with recorded summary counter*/
        while (record_trav_ptr < len_s) //Whole
        {
            ///// Check if the current indexed-char is 0 or 1 /////
            if (s[record_trav_ptr] == '0')
            {
                ///// Check if the current summary counter need to be reset or not /////
                if (record_cnter_zeros) { record_cnter_zeros &= 0; } //Update, Reset
                else { ; }

                while ((record_trav_ptr < len_s) && (s[record_trav_ptr] == '0')) //Part
                {
                    (record_cnter_zeros++); //Keep updating, accumulating

                    ///// Check if the current summary counter matched conditions or not /////
                    if (record_cnter_ones)
                    {
                        (record_cnter_ones--); //Keep updating, reducing

                        (res_cnter++); //Keep updating, accumulating
                    }
                    else { ; }

                    (record_trav_ptr++); //Keep updating, accumulating

                } //Part
            }

            else
            {
                ///// Check if the current summary counter need to be reset or not /////
                if (record_cnter_ones) { record_cnter_ones &= 0; } //Update, Reset
                else { ; }

                while ((record_trav_ptr < len_s) && (s[record_trav_ptr] == '1')) //Part
                {
                    (record_cnter_ones++); //Keep updating, accumulating

                    ///// Check if the current summary counter matched conditions or not /////
                    if (record_cnter_zeros)
                    {
                        (record_cnter_zeros--); //Keep updating, reducing

                        (res_cnter++); //Keep updating, accumulating
                    }
                    else { ; }

                    (record_trav_ptr++); //Keep updating, accumulating

                } //Part
            }

        } //Whole

        return res_cnter;
    }
};
