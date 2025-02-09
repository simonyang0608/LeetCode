class Solution {
public:
    string reorganizeString(string s) 
    {
        //============================//
        // Input type:                //
        //   - string (s string)      //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record dictionary, hashmap /////
        unordered_map<char, int> record_map;

        ///// Record vector /////
        vector<pair<int, char>> record_vect;

        ///// Record traversal pointer /////
        int record_trav_ptr = 1;


        /*Greedy-based loop traversal with recorded dictionary, hashmap, vector*/
        ///// Step 1: Record indexed-char with dictionary, hashmap, vector /////
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ((record_map[s[s_idx]])++); //Keep updating, recording

        } //Whole

        for (auto record_ele = record_map.begin(); (record_ele != record_map.end()); (record_ele++)) //Whole
        {
            record_vect.emplace_back((record_ele->second), (record_ele->first)); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap, vector /////
        sort(record_vect.begin(), record_vect.end(), [&](const pair<int, char> & pair_1, const pair<int, char> & pair_2)
        {
            return (pair_1.first < pair_2.first);

        }); //Sorted operations

        for (int record_idx = 0; (record_idx < record_vect.size()); (record_idx++)) //Whole
        {
            int record_cnter = (record_vect[record_idx]).first; char record_chr = (record_vect[record_idx]).second; //Record summary counter, char

            if ((record_cnter - 1) > (len_s - record_cnter)) { return ""; } //Issue, Boundary-case handling

            for (int cnter_idx = 0; (cnter_idx < record_cnter); (cnter_idx++)) //Whole
            {
                ///// Check if the current traversal pointer exceed boundary or not /////
                if (record_trav_ptr >= len_s) { record_trav_ptr &= 0; } //Keep updating, reset
                else { ; }

                s[record_trav_ptr] = record_chr; //Keep updating, overwriting

                record_trav_ptr += 2; //Keep updating, traversing

            } //Whole

        } //Whole

        return s;
    }
};
