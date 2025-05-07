class Solution {
public:
    string replaceDigits(string s) 
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

        ///// Result string /////
        string res_str = "";


        /*One-pass record based loop traversal*/
        for (int s_idx = 0; (s_idx < len_s); (s_idx += 2)) //Whole
        {
            res_str += s[s_idx]; //Keep updating, recording

            ///// Check if the next index exceed boundary or not /////
            if ((s_idx + 1) >= len_s) { continue; }

            res_str += (char)(((s[s_idx] - 'a') + (s[(s_idx + 1)] - '0')) + 'a'); //Keep updating, recording

        } //Whole

        return res_str;
    }
};
