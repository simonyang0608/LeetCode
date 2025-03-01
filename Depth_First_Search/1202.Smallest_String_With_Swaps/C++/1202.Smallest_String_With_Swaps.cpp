class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> & pairs) 
    {
        //=============================================//
        // Input type:                                 //
        //   - string (s string)                       //
        //   - vector<vector<int>> ref. (pairs vector) //
        // Return type:                                //
        //   - string (result string)                  //
        //=============================================//

        /*Initialize*/
        ///// Length of pair vector, s string /////
        int len_pairs = pairs.size(), len_s = s.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Visit dictionary, hashmap /////
        map<int, bool> visit_map;

        ///// Result string /////
        string res_str(s);


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record nodes informations with dictionary, hashmap /////
        for (int pairs_idx = 0; (pairs_idx < len_pairs); (pairs_idx++)) //Whole
        {
            (root_child_map[(pairs[pairs_idx])[0]]).emplace_back((pairs[pairs_idx])[1]); //Keep updating, recording
            (root_child_map[(pairs[pairs_idx])[1]]).emplace_back((pairs[pairs_idx])[0]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int s_idx = 0; (s_idx < len_s); (s_idx++)) //Whole
        {
            ///// Check if the current node is visited or not /////
            if (visit_map[s_idx]) { continue; }

            vector<int> index_vect; vector<char> char_vect; //Index, Char vectors

            int record_cnter = 0;

            dfsTraversal(s, root_child_map, visit_map, index_vect, char_vect, s_idx, record_cnter); //Recursion function call

            sort(index_vect.begin(), index_vect.end()); sort(char_vect.begin(), char_vect.end()); //Sorted operations

            for (int record_idx = 0; (record_idx < record_cnter); (record_idx++)) //Whole
            {
                res_str[index_vect[record_idx]] = char_vect[record_idx]; //Keep updating, overwriting

            } //Whole

        } //Whole

        return res_str;
    }


    void dfsTraversal(const string & s, unordered_map<int, vector<int>> & root_child_map, map<int, bool> & visit_map,
                      vector<int> & index_vect, vector<char> & char_vect, int & record_node, int & record_cnter)
    {
        //===========================================================================//
        // Input type:                                                               //
        //   - const string ref. (s string)                                          //
        //   - unordered_map<int, vector<int>> ref. (root-child dictionary, hashmap) //
        //   - map<int, bool> ref. (visit dictionary, hashmap)                       //
        //   - vector<int> ref. (index vector)                                       //
        //   - vector<char> ref. (char vector)                                       //
        //   - int ref. (record node)                                                //
        //   - int ref. (record summary counter)                                     //
        // Return type:                                                              //
        //   - void (no return)                                                      //
        //===========================================================================//
        if (visit_map[record_node]) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        visit_map[record_node] = true; //Update, Record

        index_vect.emplace_back(record_node); char_vect.emplace_back(s[record_node]); //Update, Record

        (record_cnter++); //Update, Accumulate

        for (int & next_node: root_child_map[record_node]) //Whole
        {
            dfsTraversal(s, root_child_map, visit_map, index_vect, char_vect, next_node, record_cnter); //Recursion function call

        } //Whole
    }
};
