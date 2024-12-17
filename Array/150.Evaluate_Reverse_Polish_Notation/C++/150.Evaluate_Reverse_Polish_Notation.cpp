class Solution {
public:
    int evalRPN(vector<string> & tokens) 
    {
        //=========================================//
        // Input type:                             //
        //   - vector<string> ref. (tokens vector) //
        // Return type:                            //
        //   - int (result summary value)          //
        //=========================================//

        /*Initialize*/
        ///// Length of tokens vector /////
        int len_tokens = tokens.size();

        ///// Record stack /////
        stack<string> record_stack;

        record_stack.push(tokens[0]);

        ///// Record values (i.e. first, second) /////
        int record_fst_val, record_scnd_val;

        ///// Result summary value /////
        int res_sum_val = stoi(tokens[0]);


        /*Stack-based loop traversal*/
        for (int tokens_idx = 1; (tokens_idx < len_tokens); (tokens_idx++)) //Whole
        {
            ///// Check if the current indexed-string matched conditions or not /////
            if ((isdigit((tokens[tokens_idx])[0])) || (isdigit((tokens[tokens_idx])[1]))) { record_stack.push(tokens[tokens_idx]); } //Keep updating, recording
            else
            {
                ///// Check if the current size, length enough or not /////
                if (record_stack.size() >= 2)
                {
                    record_scnd_val = stoi(record_stack.top()); //Update, overwrite

                    record_stack.pop(); //Update, popped

                    record_fst_val = stoi(record_stack.top()); //Update, overwrite

                    record_stack.pop(); //Update, popped

                    ///// Check if the current indexed-string matched conditions or not /////
                    if (tokens[tokens_idx] == "+") { res_sum_val = (record_fst_val + record_scnd_val); } //Keep updating, overwriting
                    else if (tokens[tokens_idx] == "-") { res_sum_val = (record_fst_val - record_scnd_val); } //Keep updating, overwriting
                    else if (tokens[tokens_idx] == "*") { res_sum_val = (record_fst_val * record_scnd_val); } //Keep updating, overwriting
                    else { res_sum_val = (record_fst_val / record_scnd_val); } //Keep updating, overwriting

                    record_stack.push(to_string(res_sum_val)); //Keep updating, recording
                }
                else { ; }
            }

        } //Whole

        return res_sum_val;
    }
};
