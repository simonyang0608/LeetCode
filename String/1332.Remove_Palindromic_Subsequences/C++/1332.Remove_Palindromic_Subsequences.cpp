class Solution {
public:
    int removePalindromeSub(string s) 
    {
        //================================//
        // Input type:                    //
        //   - string (s string)          //
        // Return type:                   //
        //   - int (result minimun steps) //
        //================================//

        /*Initialize*/
        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (s.size() - 1);

        /*Two-pointers based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Half
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (s[(record_left_ptr++)] != s[(record_right_ptr--)]) { return 2; }

        } //Half

        return 1;
    }
};
