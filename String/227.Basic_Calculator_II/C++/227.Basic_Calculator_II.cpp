class Solution {
public:
    int calculate(string s) 
    {
        //================================//
        // Input type:                    //
        //   - string (s string)          //
        // Return type:                   //
        //   - int (result summary value) //
        //================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record operations /////
        char record_opr = '+';

        ///// Record stack /////
        stack<int> record_stack;

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result summary value /////
        int res_sum_val = 0;


        /*Stack-based loop traversal*/
        ///// Step 1: Record indexed-char with stack /////
        while (record_trav_ptr < len_s) //Whole
        {
            ///// Check if the current indexed-char is digit or not /////
            if (s[record_trav_ptr] == ' ')
            {
                (record_trav_ptr++); //Keep updating, traversing

                continue;
            }

            if (isdigit(s[record_trav_ptr]))
            {
                int record_val = 0; //Record value

                while ((record_trav_ptr < len_s) && (isdigit(s[record_trav_ptr]))) //Part
                {
                    record_val = ((10 * record_val) + (s[record_trav_ptr] - '0')); //Keep updating, overwriting

                    (record_trav_ptr++); //Keep updating, traversing

                } //Part

                (--record_trav_ptr); //Keep updating, pre-traverse

                ///// Check which operations currently is /////
                if (record_opr == '+') { record_stack.emplace(record_val); } //Keep updating, recording
                else if (record_opr == '-') { record_stack.emplace(((-1) * record_val)); } //Keep updating, recording
                else if (record_opr == '*')
                {
                    ///// Check if the current capacity is enough or not /////
                    if (! record_stack.empty())
                    {
                        int prev_val = record_stack.top(); record_stack.pop(); //Previous value

                        prev_val *= record_val; //Keep updating, product

                        record_stack.emplace(prev_val); //Keep updating, recording
                    }
                    else { ; }
                }

                else
                {
                    ///// Check if the current capacity is enough or not /////
                    if (! record_stack.empty())
                    {
                        int prev_val = record_stack.top(); record_stack.pop(); //Previous value

                        prev_val /= record_val; //Keep updating, divide

                        record_stack.emplace(prev_val); //Keep updating, recording
                    }
                    else { ; }
                }
            }

            else if (s[record_trav_ptr] == '+')
            {
                ///// Check if the current operations matched conditions or not /////
                if (record_opr != '+') { record_opr = '+'; } //Update, Overwrite
                else { ; }
            }

            else if (s[record_trav_ptr] == '-')
            {
                ///// Check if the current operations matched conditions or not /////
                if (record_opr != '-') { record_opr = '-'; } //Update, Overwrite
                else { ; }
            }

            else if (s[record_trav_ptr] == '*')
            {
                ///// Check if the current operations matched conditions or not /////
                if (record_opr != '*') { record_opr = '*'; } //Update, Overwrite
                else { ; }
            }

            else
            {
                ///// Check if the current operations matched conditions or not /////
                if (record_opr != '/') { record_opr = '/'; } //Update, Overwrite
                else { ; }
            }

            (record_trav_ptr++);

        } //Whole

        ///// Step 2: Looped-traversal for the recorded stack /////
        while (! record_stack.empty()) //Whole
        {
            res_sum_val += record_stack.top(); //Keep updating, accumulating

            record_stack.pop(); //Keep updating, popped

        } //Whole

        return res_sum_val;
    }
};
