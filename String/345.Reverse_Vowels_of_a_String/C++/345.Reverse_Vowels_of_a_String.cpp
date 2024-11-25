class Solution {
public:
    string reverseVowels(string s) 
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

        ///// Record vector /////
        vector<char> record_vect;

        for (int record_idx = 0; (record_idx < len_s); (record_idx++))
        {
            record_vect.emplace_back(s[record_idx]);
        }

        ///// Record dictionary, hashmap /////
        unordered_map<char, bool> record_map;

        record_map['a'] = true;
        record_map['A'] = true;
        record_map['e'] = true;
        record_map['E'] = true;
        record_map['i'] = true;
        record_map['I'] = true;
        record_map['o'] = true;
        record_map['O'] = true;
        record_map['u'] = true;
        record_map['U'] = true;

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_s - 1);

        ///// Record char /////
        char record_char;

        ///// Result string /////
        string res_str;


        /*Two-pointers based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Looped-traversal with recorded dictionary, hashmap /////
        while (record_left_ptr <= record_right_ptr) //Part
        {
            ///// Check if the current indexed-char existed or not /////
            if (record_map.find(s[record_left_ptr]) == record_map.end())
            {
                ///// Check if the current indexed-char existed or not /////
                if (record_map.find(s[record_right_ptr]) == record_map.end())
                {
                    (record_right_ptr--); //Keep updating, traversing
                }
                else { ; }

                (record_left_ptr++); //Keep updating, traversing
            }

            else
            {
                ///// Check if the current indexed-char existed or not /////
                if (record_map.find(s[record_right_ptr]) == record_map.end()) { ; }
                else
                {
                    record_char = record_vect[record_right_ptr]; //Keep updating, overwriting

                    record_vect[record_right_ptr] = record_vect[record_left_ptr]; //Keep updating, overwriting
                    record_vect[record_left_ptr] = record_char; //Keep updating, overwriting

                    (record_left_ptr++); //Keep updating, traversing
                }

                (record_right_ptr--); //Keep updating, traversing
            }

        } //Part

        ///// Step 2: Post-process, Final completions /////
        for (int record_idx = 0; (record_idx < len_s); (record_idx++)) //Whole
        {
            res_str += record_vect[record_idx]; //Keep updating, overwriting

        } //Whole

        return res_str;
    }
};
