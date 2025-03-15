class Solution {
public:
    string decodeString(string s) 
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

        ///// Record stack (i.e. value) /////
        stack<int> record_stack_val;

        ///// Record stack (i.e. string) /////
        stack<string> record_stack_str;

        ///// Record value /////
        int record_val = 0;

        ///// Result string /////
        string res_str;


        /*Stack-based loop traversal*/
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (s[s_idx] == '[')
            {
                record_stack_val.emplace(record_val); //Keep updating, recording

                ///// Check if the current value needs to be reset or not /////
                if (record_val) { record_val &= 0; } //Keep updating, reset
                else { ; }

                record_stack_str.emplace(res_str); //Keep updating, recording

                ///// Check if the current string needs to be reset or not /////
                if (! res_str.empty()) { res_str.clear(); } //Keep updating, reset
                else { ; }
            }

            else if (s[s_idx] == ']')
            {
                string record_str = record_stack_str.top(); //Record string

                for (int times_idx = 0; (times_idx < record_stack_val.top()); (times_idx++)) //Times
                {
                    record_str += res_str; //Keep updating, recording

                } //Times

                res_str = record_str; //Keep updating, overwriting

                record_stack_str.pop(); record_stack_val.pop(); //Keep updating, popped
            }

            else
            {
                ///// Check if the current indexed-char is-digit or not /////
                if (isdigit(s[s_idx]))
                {
                    while (isdigit(s[s_idx])) //Part
                    {
                        record_val = ((10 * record_val) + (s[s_idx] - '0')); //Record value

                        (s_idx++); //Keep updating, traversing

                    } //Part

                    (s_idx--); //Keep updating, traversing
                }
                else
                {
                    while (isalpha(s[s_idx])) //Part
                    {
                        res_str += s[s_idx]; (s_idx++); //Keep updating, traversing

                    } //Part

                    (s_idx--); //Keep updating, traversing
                }
            }

        } //Whole

        return res_str;
    }
};
