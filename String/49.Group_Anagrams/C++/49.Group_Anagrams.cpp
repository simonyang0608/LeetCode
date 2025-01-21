class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> & strs) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<string> ref. (strs vector)      //
        // Return type:                               //
        //   - vector<vector<string>> (result vector) //
        //============================================//

        /*Initialize*/
        ///// Length of strs vector /////
        int len_strs = strs.size();

        ///// Record dictionary, hashmap /////
        unordered_map<string, vector<string>> record_map;

        ///// Result vector /////
        vector<vector<string>> res_vect;


        /*Hashmap-based loop traversal with recorded vector*/
        ///// Step 1: Record indexed-string with dictionary, hashmap /////
        for (int strs_idx = 0; (strs_idx < len_strs); (strs_idx++)) //Whole
        {
            string record_str = strs[strs_idx]; string res_str; //Record, Result string

            vector<int> record_vect(26, 0); //Record vector

            for (const char & record_chr: record_str) //Whole
            {
                ((record_vect[(record_chr - 'a')])++); //Keep updating, recording

            } //Whole

            for (int record_idx = 0; (record_idx < 26); (record_idx++)) //Whole
            {
                ///// Check if the current indexed-char existed or not /////
                if (record_vect[record_idx]) { res_str += ((char)(record_idx + 97) + to_string(record_vect[record_idx])); } //Keep updating, recording
                else { ; }

            } //Whole

            (record_map[res_str]).emplace_back(record_str); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (auto record_ele = record_map.begin(); (record_ele != record_map.end()); (record_ele++)) //Whole
        {
            res_vect.push_back(record_ele->second); //Keep updating, recording

        } //Whole

        return res_vect;
    }
};
