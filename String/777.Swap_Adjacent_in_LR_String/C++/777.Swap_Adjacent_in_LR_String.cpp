class Solution {
public:
    bool canTransform(string start, string result) 
    {
        //============================//
        // Input type:                //
        //   - string (start string)  //
        //   - string (result string) //
        // Return type:               //
        //   - bool (result flag)     //
        //============================//

        /*Initialize*/
        ///// Length of strings (i.e. start, target) /////
        int len_string = start.size();

        ///// Record stacks (i.e. left, right) /////
        stack<char> record_left_stack, record_right_stack;


        /*Stack-based loop traversal*/
        for (int string_idx = 0; (string_idx < len_string); (string_idx++)) //Left
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (result[string_idx] == 'L') { record_left_stack.push('L'); } //Keep updating, recording
            else { ; }

            ///// Check if the current stack is empty or not /////
            if (! record_left_stack.empty())
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if ((start[string_idx] == 'R') || (result[string_idx] == 'R')) { return false; }
                else if (start[string_idx] == 'L') { record_left_stack.pop(); } //Keep updating, popped
                else { ; }
            }
            else
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if (start[string_idx] == 'L') { return false; }
                else { ; }
            }

        } //Left

        for (int string_idx = (len_string - 1); (string_idx >= 0); (string_idx--)) //Right
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (result[string_idx] == 'R') { record_right_stack.push('R'); } //Keep updating, recording
            else { ; }

            ///// Check if the current stack is empty or not /////
            if (! record_right_stack.empty())
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if ((start[string_idx] == 'L') || (result[string_idx] == 'L')) { return false; }
                else if (start[string_idx] == 'R') { record_right_stack.pop(); } //Keep updating, popped
                else { ; }
            }
            else
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if (start[string_idx] == 'R') { return false; }
                else { ; }
            }
            
        } //Right

        return (record_left_stack.empty() && record_right_stack.empty()) ? true : false;
    }
};
