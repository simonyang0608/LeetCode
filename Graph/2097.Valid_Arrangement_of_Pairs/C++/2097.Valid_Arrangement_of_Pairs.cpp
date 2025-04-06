class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>> & pairs) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (pairs vector) //
        // Return type:                                //
        //   - vector<vector<int>> (result vector)     //
        //=============================================//

        /*Initialize*/
        ///// Length of pairs vector /////
        int len_pairs = pairs.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Degree dictionary, hashmap /////
        unordered_map<int, int> degree_map;

        ///// Record stack /////
        stack<int> record_stack;

        ///// Record vector /////
        vector<int> record_vect;

        ///// Start node /////
        int start_node = (pairs[0])[0];

        ///// Result vector /////
        vector<vector<int>> res_vect;


        /*Stack-based loop traversal*/
        ///// Step 1: Record indexed-nodes information with dictionary, hashmap /////
        for (int pairs_idx = 0; (pairs_idx < len_pairs); (pairs_idx++)) //Whole
        {
            (root_child_map[(pairs[pairs_idx])[0]]).emplace_back((pairs[pairs_idx])[1]); //Keep updating, recording

            ((degree_map[(pairs[pairs_idx])[0]])++); ((degree_map[(pairs[pairs_idx])[1]])--); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (auto record_ele = degree_map.begin(); (record_ele != degree_map.end()); (record_ele++)) //Whole
        {
            ///// Check if the current summary counter matched conditions or not /////
            if ((record_ele->second) > 0) { start_node = (record_ele->first); break; }
            else { ; }

        } //Whole

        record_stack.emplace(start_node); //Update, Record

        while (! record_stack.empty()) //Cycled-times
        {
            int record_node = record_stack.top(); //Record node

            ///// Check if the next-nodes existed or not /////
            if (! (root_child_map[record_node]).empty())
            {
                record_stack.emplace((root_child_map[record_node]).back()); //Keep updating, recording

                (root_child_map[record_node]).pop_back(); //Keep updating, popped
            }
            else { record_vect.emplace_back(record_node); record_stack.pop(); } //Keep updating, popped

        } //Cycled-times

        for (int record_idx = (record_vect.size() - 1); (record_idx > 0); (record_idx--)) //Whole
        {
            res_vect.push_back({record_vect[record_idx], record_vect[(record_idx - 1)]}); //Keep updating, recording

        } //Whole

        return res_vect;
    }
};
