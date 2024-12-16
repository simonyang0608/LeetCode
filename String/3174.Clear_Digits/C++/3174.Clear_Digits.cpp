class Solution {
public:
    string clearDigits(string s) 
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

        ///// Record stack /////
        stack<char> record_stack;

        ///// Result string /////
        string res_s;


        /*Stack-based loop traversal*/
        ///// Step 1: Record indexed-char with stack /////
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (! (isdigit(s[s_idx])))
            {
                record_stack.push(s[s_idx]); //Keep updating, recording
            }
            else { record_stack.pop(); } //Keep updating, popped

        } //Whole

        ///// Step 2: Looped-traversal with recorded stack /////
        while (! record_stack.empty()) //Remains
        {
            res_s += (record_stack.top()); //Keep updating, recording

            record_stack.pop(); //Keep updating, popped

        } //Remains

        reverse(res_s.begin(), res_s.end()); //Reverse operation

        return res_s;
    }
};
