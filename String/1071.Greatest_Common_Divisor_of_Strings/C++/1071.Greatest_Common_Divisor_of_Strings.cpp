class Solution {
public:
    string gcdOfStrings(string str1, string str2) 
    {
        //============================//
        // Input type:                //
        //   - string (str1 string)   //
        //   - string (str2 string)   //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of strings (i.e. str1, str2) /////
        int len_str1 = str1.size(), len_str2 = str2.size();

        ///// Result string /////
        string res_str;


        /*Math-GCD based loop traversal*/
        for (int record_idx = 1; (record_idx <= len_str1); (record_idx++)) //Str-1
        {
            ///// Check if the current length is common dividor or not /////
            if ((len_str1 % record_idx) || (len_str2 % record_idx)) { continue; }

            string record_str = str1.substr(0, record_idx); //Record string

            string target_str1; string target_str2; //Target strings (i.e. str1, str2)

            for (int str1_idx = 0; (str1_idx < (len_str1 / record_idx)); (str1_idx++)) //Str-1
            {
                target_str1 += record_str; //Keep updating, recording

            } //Str-1

            ///// Check if the target string matched conditions or not /////
            if (target_str1 != str1) { continue; }

            for (int str2_idx = 0; (str2_idx < (len_str2 / record_idx)); (str2_idx++)) //Str-2
            {
                target_str2 += record_str; //Keep updating, recording

            } //Str-2

            ///// Check if the target string matched conditions or not /////
            if (target_str2 != str2) { continue; }

            res_str = record_str; //Keep updating, overwriting

        } //Str-1

        return res_str;
    }
};
