class Solution {
public:
    string customSortString(string order, string s) 
    {
        //============================//
        // Input type:                //
        //   - string (order string)  //
        //   - string (s string)      //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of strings (i.e. order, s) /////
        int len_order = order.size(), len_s = s.size();

        ///// Record dictionary, hashmap /////
        unordered_map<char, int> record_map;

        ///// Result string /////
        string res_str;


        /*Hashmap-based loop traversal*/
        ///// Step 1: Record indexed-char with dictionary, hashmap /////
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ((record_map[s[s_idx]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the recorded dictionary, hashmap /////
        for (int order_idx = 0; (order_idx < len_order); (order_idx++)) //Whole
        {
            while ((--(record_map[order[order_idx]])) >= 0) //Part
            {
                res_str += order[order_idx]; //Keep updating, recording

            } //Part

        } //Whole

        for (auto record_ele = record_map.begin(); (record_ele != record_map.end()); (record_ele++)) //Whole
        {
            while ((--(record_ele->second)) >= 0) //Part
            {
                res_str += (record_ele->first); //Keep updating, recording

            } //Part

        } //Whole

        return res_str;
    }
};
