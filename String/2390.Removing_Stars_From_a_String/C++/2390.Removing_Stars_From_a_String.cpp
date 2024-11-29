class Solution {
public:
    string removeStars(string s) 
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
        string res_str;


        /*Stack-based loop traversal*/
        ///// Step 1: Looped-traversal for stack recording /////
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (s[s_idx] == '*')
            {
                record_stack.pop(); //Keep updating, popped

                continue;
            }

            record_stack.push(s[s_idx]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for result string recording /////
        while (! record_stack.empty()) //Whole
        {
            res_str += record_stack.top(); //Keep updating, recording

            record_stack.pop(); //Keep updating, popped

        } //Whole

        reverse(res_str.begin(), res_str.end()); //Update, Reverse

        return res_str;
    }
};
