class Solution {
public:
    int minimumLength(string s) 
    {
        //=================================//
        // Input type:                     //
        //   - string (s string)           //
        // Return type:                    //
        //   - int (result minimun length) //
        //=================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_s - 1);


        /*Two-pointers based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Two-pointers
        {
            ///// Check if the current indexed-char is the same or not /////
            if (s[record_left_ptr] == s[record_right_ptr])
            {
                while (((record_left_ptr + 1) < len_s) && (s[record_left_ptr] == s[(record_left_ptr + 1)])) //Part
                {
                    (record_left_ptr++); //Keep updating, traversing

                } //Part

                while (((record_right_ptr - 1) >= 0) && (s[record_right_ptr] == s[(record_right_ptr - 1)])) //Part
                {
                    (record_right_ptr--); //Keep updating, traversing

                } //Part

                (record_left_ptr++); (record_right_ptr--); //Keep updating, traversing
            }

            else { break; }

        } //Two-pointers

        return (record_left_ptr <= record_right_ptr) ? (record_right_ptr - record_left_ptr + 1) : 0;
    }
};
