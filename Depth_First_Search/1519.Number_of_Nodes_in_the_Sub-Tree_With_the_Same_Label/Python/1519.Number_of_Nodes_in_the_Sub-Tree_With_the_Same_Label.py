class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>> & edges, string labels) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        //   - string (labels string)                  //
        // Return type:                                //
        //   - vector<int> (result vector)             //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<int>> record_map;

        ///// Record value /////
        int record_val = 0;

        ///// Visit, Result vectors /////
        vector<int> visit_vect(n, 0), res_vect(n, 0);


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (record_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1]); //Keep updating, recording
            (record_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0]); //Keep updating, recording

        } //Whole

        vector<int> char_vect = dfsTraversal(record_map, record_val, labels, visit_vect, res_vect); //Recursion function call

        return res_vect;
    }


    vector<int> dfsTraversal(unordered_map<int, vector<int>> & record_map, int & record_val, string & labels, vector<int> & visit_vect, vector<int> & res_vect)
    {
        //=======================================================================//
        // Input type:                                                           //
        //   - unordered_map<int, vector<int>> ref. (record dictionary, hashmap) //
        //   - int ref. (record value)                                           //
        //   - string (labels string)                                            //
        //   - vector<vector<int>> ref. (visit vector)                           //
        //   - vector<int> ref. (result vector)                                  //
        // Return type:                                                          //
        //   - vector<int> (char vector)                                         //
        //=======================================================================//

        /*Initialize*/
        ///// Char vector /////
        vector<int> char_vect(26, 0);

        /*Whole process, flow*/
        ///// Check if the current indexed-node is visited or not /////
        if (! visit_vect[record_val])
        {
            visit_vect[record_val] = 1; //Update, Overwrite

            ((char_vect[(labels[record_val] - 'a')])++); //Update, Accumulate

            for (int & next_val: record_map[record_val]) //Whole
            {
                vector<int> record_char_vect = dfsTraversal(record_map, next_val, labels, visit_vect, res_vect); //Record char vector

                for (int record_idx = 0; (record_idx < 26); (record_idx++)) //Whole
                {
                    char_vect[record_idx] += record_char_vect[record_idx]; //Keep updating, accumulating

                } //Whole

            } //Whole

            res_vect[record_val] += char_vect[(labels[record_val] - 'a')]; //Update, Accumulate
        }

        return char_vect;
    }
};
