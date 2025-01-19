class Solution {
public:
    int longestValidParentheses(string s) 
    {
        //==========================================//
        // Input type:                              //
        //   - string (s string)                    //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record stack /////
        stack<int> record_stack;

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Stack-based loop traversal*/
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ///// Check if the current char matched conditions or not /////
            if (s[s_idx] == '(') { record_stack.emplace(s_idx); } //Keep updating, recording
            else
            {
                ///// Check if the current stack is empty or not /////
                if (record_stack.empty()) { record_trav_ptr = (s_idx + 1); } //Keep updating, overwriting
                else
                {
                    record_stack.pop(); //Keep updating, popped

                    res_max_cnter = (record_stack.empty()) ? max(res_max_cnter, ((s_idx - record_trav_ptr) + 1)) : max(res_max_cnter, (s_idx - record_stack.top())); //Keep updating, overwriting
                }
            }

        } //Whole

        return res_max_cnter;
    }
};
