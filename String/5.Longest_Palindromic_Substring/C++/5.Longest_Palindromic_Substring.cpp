class Solution {
public:
    string longestPalindrome(string s) 
    {
        //============================//
        // Input type:                //
        //   - string (s string)      //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Result two-pointers (i.e. left, right) /////
        int res_left_ptr = 0, res_right_ptr = 0;


        /*Two-pointer based loop traversal*/
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            mid2edge(len_s, s, s_idx, s_idx, res_left_ptr, res_right_ptr); //First middle-edge function call
            mid2edge(len_s, s, s_idx, (s_idx + 1), res_left_ptr, res_right_ptr); //Second middle-edge function call
             
        } //Whole

        return s.substr(res_left_ptr, ((res_right_ptr - res_left_ptr) + 1));
    }


    void mid2edge(int & len_s, string & s, int record_left_ptr, int record_right_ptr, int & res_left_ptr, int & res_right_ptr)
    {
        //=====================================//
        // Input type:                         //
        //   - int ref. (length of s string)   //
        //   - string ref. (s string)          //
        //   - int (record left pointer)       //
        //   - int (record right pointer)      //
        //   - int ref. (result left pointer)  //
        //   - int ref. (result right pointer) //
        // Rerurn type:                        //
        //   - void (no return)                //
        //=====================================//

        /*Whole process, flow*/
        while (((record_left_ptr >= 0) && (record_right_ptr < len_s)) && (s[record_left_ptr] == s[record_right_ptr])) //Part
        {
            ///// Check if the current length is larger or not /////
            if ((record_right_ptr - record_left_ptr) > (res_right_ptr - res_left_ptr))
            {
                res_left_ptr = record_left_ptr; //Keep updating, overwriting
                res_right_ptr = record_right_ptr; //Keep updating, overwriting
            }
            else { ; }

            (record_left_ptr--); //Keep updating, traversing
            (record_right_ptr++); //Keep updating, traversing

        } //Part
    }
};
