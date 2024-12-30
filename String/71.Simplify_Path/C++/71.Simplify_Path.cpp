class Solution {
public:
    string simplifyPath(string path) 
    {
        //============================//
        // Input type:                //
        //   - string (path string)   //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of path string /////
        int len_path = path.size();

        ///// Record stack /////
        stack<string> record_stack;

        ///// Result string /////
        string res_str;


        /*Stack-based loop traversal*/
        for (int path_idx = 0; (path_idx < len_path); (path_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (path[path_idx] == '/') { continue; }

            string record_str; //Record string

            while ((path_idx < len_path) && (path[path_idx] != '/')) //Part
            {
                record_str += path[(path_idx++)]; //Keep updating, recording

            } //Part

            ///// Check if the current indexed-char matched conditions or not /////
            if (record_str == ".") { continue; }

            if (record_str == "..")
            {
                ///// Check if the current stack is empty or not /////
                if (! record_stack.empty()) { record_stack.pop(); } //Keep updating, popped
                else { ; }

                continue;
            }

            record_stack.push(record_str); //Keep updating, recording

        } //Whole

        ///// Check if the current stack is empty or not /////
        if (record_stack.empty()) { res_str += "/"; } //Updatr, Record
        else
        {
            while (! record_stack.empty()) //Whole
            {
                string record_str = (record_stack.top()); record_stack.pop(); //Record string

                reverse(record_str.begin(), record_str.end()); //Reverse operations

                res_str += record_str; //Keep updating, recording

                res_str += "/"; //Keep updating, recording

            } //Whole

            reverse(res_str.begin(), res_str.end()); //Reverse operations
        }

        return res_str;
    }
};
