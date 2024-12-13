class Solution {
public:
    int countHomogenous(string s) 
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

        ///// Record module /////
        int record_module = (1e9 + 7);

        ///// Record summary counter /////
        long long record_cnter = 1;

        ///// Result summary counter /////
        long long res_cnter = 0;


        /*Sliding-window based loop traversal*/
        while (record_trav_ptr < len_s) //Whole
        {
            while (((record_trav_ptr + 1) < len_s) && (s[record_trav_ptr] == s[(record_trav_ptr + 1)])) //Part
            {
                (record_cnter++); //Keep updating, accumulating

                (record_trav_ptr++);

            } //Part

            res_cnter += (((record_cnter * (record_cnter + 1)) / 2) % record_module); //Keep updating, accumulating

            ///// Check if the current summary counter needs to be reset or not /////
            if (record_cnter > 1) { record_cnter = 1; } //Upadte, Reset
            else { ; }

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return (int)(res_cnter);
    }
};
