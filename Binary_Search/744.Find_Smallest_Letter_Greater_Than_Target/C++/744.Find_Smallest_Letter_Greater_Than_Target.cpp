class Solution {
public:
    char nextGreatestLetter(vector<char> & letters, char target) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<char> ref. (letters vector) //
        //   - char (target letter)               //
        // Return type:                           //
        //   - char (result letter)               //
        //========================================//

        /*Initialize*/
        ///// Length of letters vector /////
        int len_letters = letters.size();

        ///// Record target value /////
        int record_target = (target - 'a');

        ///// Record pointers (i.e. middle, left, right) /////
        int record_mid_ptr, record_left_ptr = 0, record_right_ptr = (len_letters - 1);


        /*Binary-search based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            ///// check if the current indexed-char matched conditions or not /////
            if ((letters[record_mid_ptr] - 'a') <= record_target) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting

        } //Binary-search
 
        ///// Check if the current indexed-char matched conditions or not /////
        if (record_left_ptr == (len_letters - 1))
        {
            if ((letters[record_left_ptr] - 'a') > record_target) { return letters[record_left_ptr]; }

            return letters[0];
        }

        return letters[record_left_ptr];
    }
};
