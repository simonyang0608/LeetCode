class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int> & vals) 
    {
        //====================================//
        // Input type:                        //
        //   - string (s string)              //
        //   - string (chars string)          //
        //   - vector<int> ref. (vals vector) //
        // Return type:                       //
        //   - int (result maximun costs)     //
        //====================================//

        /*Initialize*/
        ///// Length of strings (i.e. s, chars) /////
        int len_s = s.size(), len_chars = chars.size();

        ///// Record dictionary, hashmap /////
        map<char, int> record_map;

        ///// Record maximun costs /////
        int record_max_cost = 0;

        ///// Result maximun costs /////
        int res_max_cost = ((-1) * 1e9); 


        /* kadane's-based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-char with dictionary, hashmap /////
        for (int record_idx = 0; (record_idx < len_chars); (record_idx++)) //Whole
        {
            record_map[chars[record_idx]] = vals[record_idx]; //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ///// Check if the current indexed-char existed or not /////
            if (record_map.find(s[s_idx]) != record_map.end()) { record_max_cost += record_map[s[s_idx]]; } //Keep updating, accumulating
            else { record_max_cost += ((s[s_idx] - 'a') + 1); } //Keep updating, accumulating

            res_max_cost = max(res_max_cost, record_max_cost); //Keep updating, overwriting

            ///// Check if the current costs needs to be reset or not /////
            if (record_max_cost < 0) { record_max_cost &= 0; } //Keep updating, reset
            else { ; }

        } //Whole

        return (res_max_cost < 0) ? 0 : res_max_cost;
    }
};
