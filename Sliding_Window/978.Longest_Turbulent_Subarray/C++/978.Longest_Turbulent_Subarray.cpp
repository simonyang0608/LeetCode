class Solution {
public:
    int maxTurbulenceSize(vector<int> & arr) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (arr vector)        //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Record char /////
        char record_chr = 'n';

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record summary counter /////
        int record_cnter = 1;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Sliding-window based loop traversal*/
        while (record_trav_ptr < len_arr) //Whole
        {
            ///// Check if the current pointer exceed boundary or not /////
            if ((record_trav_ptr + 1) < len_arr)
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if (arr[record_trav_ptr] == arr[(record_trav_ptr + 1)])
                {
                    ///// Check if the current summary counter matched conditions or not /////
                    if (record_cnter != 1) { record_cnter = 1; record_chr = 'n'; } //Keep updating, reset
                    else { ; }
                }

                else if (arr[record_trav_ptr] > arr[(record_trav_ptr + 1)])
                {
                    ///// Check if the current indexed-char matched conditions or not /////
                    if ((record_chr == 'n') || (record_chr == 'i')) { (record_cnter++); record_chr = 'd'; } //Keep updating, reset
                    else
                    {
                        ///// Check if the current summary counter matched conditions or not /////
                        if (record_cnter != 2) { record_cnter = 2; } //Keep updating, reset
                        else { ; }
                    }
                }

                else
                {
                    ///// Check if the current indexed-char matched conditions or not /////
                    if ((record_chr == 'n') || (record_chr == 'd')) { (record_cnter++); record_chr = 'i'; } //Keep updating, reset
                    else
                    {
                        ///// Check if the current summary counter matched conditions or not /////
                        if (record_cnter != 2) { record_cnter = 2; } //Keep updating, reset
                        else { ; }
                    }
                }
            }
            else { ; }

            res_max_cnter = (record_cnter > res_max_cnter) ? record_cnter : res_max_cnter; //Keep updating, overwriting

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_max_cnter;
    }
};
