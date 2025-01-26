class Solution {
public:
    long long smallestNumber(long long num) 
    {
        //==============================//
        // Input type:                  //
        //   - long long (num value)    //
        // Return type:                 //
        //   - long long (result value) //
        //==============================//

        /*Initialize*/
        ///// Check if the current value is positive or not /////
        if (num < 0) 
        {
            string record_str = to_string((num * (-1))); //Record string

            sort(record_str.rbegin(), record_str.rend()); //Sorted operations

            return (stoll(record_str) * (-1));
        }

        ///// Record string /////
        string record_str = to_string(num);

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result string /////
        string res_str;


        /*Sorted-based loop traversal*/
        sort(record_str.begin(), record_str.end()); //Sorted operations

        if (record_str.back() == '0') { return 0; } //Issue, Boundary-case handling

        while (record_trav_ptr < record_str.size()) //Part
        {
            ///// Check if the current indexed-char is zero or not /////
            if (record_str[record_trav_ptr] == '0') { (record_trav_ptr++); } //Keep updating, traversing
            else { break; }

        } //Part

        res_str += record_str[record_trav_ptr]; //Keep updating, recording

        res_str += record_str.substr(0, record_trav_ptr); //Keep updating, recording

        res_str += record_str.substr((record_trav_ptr + 1), (record_str.size() - record_trav_ptr - 1)); //Keep updating, recording

        return stoll(res_str);
    }
};
