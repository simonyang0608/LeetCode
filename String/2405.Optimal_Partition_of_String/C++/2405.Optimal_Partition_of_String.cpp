class Solution {
public:
    int partitionString(string s) 
    {
        //==========================================//
        // Input type:                              //
        //   - string (s string)                    //
        // Return type:                             //
        //   - int (result minimun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record vector /////
        vector<int> record_vect(26, 0);

        ///// Result minimun summary counter /////
        int res_min_cnter = 1;


        /*Two-pointers based looped-traversal with recorded vector*/
        while (record_right_ptr < len_s) //Whole
        {
            ///// Cjheck if the current indexed-char existed or not /////
            if ((record_vect[(s[record_right_ptr] - 'a')] < 1)) { record_vect[(s[record_right_ptr] - 'a')] = 1; } //Keep updating, overwriting
            else
            {
                while (record_left_ptr < record_right_ptr) //Part
                {
                    record_vect[(s[(record_left_ptr++)] - 'a')] = 0; //Keep updating, overwriting
                }

                record_vect[(s[record_left_ptr] - 'a')] = 1; //Keep updating, overwriting

                (res_min_cnter++); //Keep updating, accumulating

            } //Part

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_min_cnter;
    }
};
