class Solution {
public:
    int maxVowels(string s, int k) 
    {
        //==========================================//
        // Input type:                              //
        //   - string (s string)                    //
        //   - int (k-th length)                    //
        // Return type:                             //
        //   - int (result maximun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record dictionary, hashmap /////
        map<char, bool> record_map;

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Sliding-window based loop traversal*/
        ///// Step 1: Looped-traversal for the first fixed-window size /////
        record_map['a'] = true; record_map['e'] = true; record_map['i'] = true; //Update, Record
        record_map['o'] = true; record_map['u'] = true; //Update, Record

        for (int s_idx = 0; (s_idx < k); (s_idx++)) //Fixed-window size
        {
            record_cnter += (record_map[s[s_idx]]) ? 1 : 0; //Keep updating, accumulating

        } //Fixed-window size

        ///// Step 2: Looped-traversal for the remainings /////
        res_max_cnter = max(res_max_cnter, record_cnter); //Update, Overwrite

        for (int s_idx = k; (s_idx < len_s); (s_idx++)) //Remainings
        {
            record_cnter -= (record_map[s[s_idx - k]]) ? 1 : 0; //Keep updating, reducing

            record_cnter += (record_map[s[s_idx]]) ? 1 : 0; //Keep updating, accumulating

            res_max_cnter = max(res_max_cnter, record_cnter); //Keep updating, overwriting

        } //Remainings

        return res_max_cnter;
    }
};
