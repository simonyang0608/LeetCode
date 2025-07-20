class Solution {
public:
    int maxOperations(string s) 
    {
        //=====================================//
        // Input type:                         //
        //   - string (s string)               //
        // Return type:                        //
        //   - int (result maximun operations) //
        //=====================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record ones summary /////
        int record_sum_ones = 0;

        ///// Result maximun operations /////
        int res_max_oprs = 0;


        /*Greedy-based loop traversal*/
        while (record_trav_ptr < len_s) //Whole
        {
            ///// Check if the current indexed-char is ones or not /////
            if (s[record_trav_ptr] == '0')
            {
                res_max_oprs += record_sum_ones; //Keep updating, accumulating

                while (((record_trav_ptr + 1) < len_s) && (s[(record_trav_ptr + 1)] == '0')) //Part
                {
                    (record_trav_ptr++); //Keep updating, traversing

                } //Part
            }
            else { (record_sum_ones++); } //Keep updating, accumulating

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_max_oprs;
    }
};
