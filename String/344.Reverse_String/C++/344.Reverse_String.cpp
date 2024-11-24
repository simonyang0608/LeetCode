class Solution {
public:
    void reverseString(vector<char> & s) 
    {
        //==================================//
        // Input type:                      //
        //   - vector<char> ref. (s vector) //
        // Return type:                     //
        //   - void (no return)             //
        //==================================//

        /*Initialize*/
        ///// Length of s vector /////
        int trav_len_s, len_s = s.size();
        trav_len_s = (len_s / 2);

        ///// Record s char /////
        char record_s;


        /*One-pass swap based loop traversal*/
        for (int s_idx = 0; (s_idx < trav_len_s); (s_idx++)) //Part
        {
            record_s = s[s_idx]; //Record s char

            s[s_idx] = s[((len_s - 1) - s_idx)]; //Keep updating, swap
            s[((len_s - 1) - s_idx)] = record_s; //Keep updating, swap

        } //Part
    }
};
