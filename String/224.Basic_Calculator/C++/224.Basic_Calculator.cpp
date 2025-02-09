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

        ///// Record stack /////
        stack<int> record_stack;

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result summary value, sign /////
        int res_sum_val = 0, res_sign = 1;


        /*Stack-based loop traversal*/
        while (record_trav_ptr < len_s) //Whole
        {
            if (s[record_trav_ptr] == ' ') { (record_trav_ptr++); continue; } //Keep updating, traversing

            ///// Check if the current indexed-char is digit or not /////
            if (isdigit(s[record_trav_ptr]))
            {
                int record_sum_val = 0; //Record summary value

                while ((record_trav_ptr < len_s) && (isdigit(s[record_trav_ptr]))) //Part
                {
                    record_sum_val = ((10 * record_sum_val) + (s[record_trav_ptr] - '0')); //Keep updating, overwriting

                    (record_trav_ptr++); //Keep updating, traversing

                } //Part

                (--record_trav_ptr); //Keep updating, prev-traverse

                res_sum_val += (record_sum_val * res_sign); //Keep updating, accumulating
            }

            else if (s[record_trav_ptr] == '+')
            {
                ///// Check if the current sign matched conditions or not /////
                if (res_sign != 1) { res_sign = (+1); }
                else { ; }
            }

            else if (s[record_trav_ptr] == '-')
            {
                ///// Check if the current sign matched conditions or not /////
                if (res_sign != (-1)) { res_sign = (-1); }
                else { ; }
            }

            else if (s[record_trav_ptr] == '(')
            {
                record_stack.emplace(res_sum_val); //Keep updating, recording
                record_stack.emplace(res_sign); //Keep updating, recording

                res_sum_val &= 0; //Keep updating, reset
                res_sign = 1; //Keep updating, overwriting
            }

            else
            {
                ///// Check if the current capacity is enough or not /////
                if (record_stack.size() >= 2)
                {
                    int prev_sign = record_stack.top(); record_stack.pop(); //Previous sign
                    int prev_sum_val = record_stack.top(); record_stack.pop(); //Previous summary value

                    res_sum_val *= prev_sign; //Keep updating, product
                    res_sum_val += prev_sum_val; //Keep updating, accumulating
                }
                else { ; }
            }

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_sum_val;
    }
};
