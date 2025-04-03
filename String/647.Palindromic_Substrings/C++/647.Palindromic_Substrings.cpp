class Solution {
public:
    int countSubstrings(string s) 
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

        ///// Result summary counter /////
        int res_cnter = len_s;


        /*Two-pointers based loop traversal*/
        for (int s_idx = 0; (s_idx < (len_s - 1)); (s_idx++)) //Whole
        {
            ///// Check if the previous index exceed boundary or not /////
            if ((s_idx - 1) >= 0) { isPalindrome(len_s, s, (s_idx - 1), (s_idx + 1), res_cnter); } //Function call
            else { ; }

            isPalindrome(len_s, s, s_idx, (s_idx + 1), res_cnter); //Function call

        } //Whole

        return res_cnter;
    }


    void isPalindrome(const int & len_s, const string & s, int prev_idx, int post_idx, int & res_cnter)
    {
        //=========================================//
        // Input type:                             //
        //   - const int ref. (length of s string) //
        //   - const string ref. (s string)        //
        //   - int (previous index)                //
        //   - int (post index)                    //
        //   - int ref. (result summary cnter)     //
        // Return type:                            //
        //   - void (no return)                    //
        //=========================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = prev_idx, record_right_ptr = post_idx;

        /*Whole process, flow*/
        while (((record_left_ptr >= 0) && (record_right_ptr < len_s)) && (s[record_left_ptr] == s[record_right_ptr])) //Part
        {
            (res_cnter++); (record_left_ptr--); (record_right_ptr++); //Keep updating, traversing

        } //Part
    }
};
