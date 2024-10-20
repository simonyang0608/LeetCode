/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) 
    {
        //========================================//
        // Input type:                            //
        //   - int (n-th length of numbers)       //
        // Return type:                           //
        //   - int (result target guessed-number) //
        //========================================//

        /*Initialize*/
        ///// Record two-pointers (i.e. left, right) /////
        long long record_left_ptr = 1, record_right_ptr = n;

        ///// Record middle pointer /////
        long long record_mid_ptr;

        ///// Record flag /////
        int record_flag;


        /*Binary-search based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            record_flag = guess(record_mid_ptr); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (! record_flag) { return record_mid_ptr; }
            else if (record_flag > 0) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

        } //Binary-search

        return (-1);
    }
};
