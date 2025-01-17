class Solution {
public:
    int reachableNodes(int n, vector<vector<int>> & edges, vector<int> & restricted) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        //   - vector<int> ref. (restricted vector)    //
        // Return type:                                // 
        //   - int (result maximun summary value)      //
        //=============================================//

        /*Initialize*/
        ///// Lenght of vectors (i.e. edges, restricted) /////
        int len_edges = edges.size(), len_restricted = restricted.size();

        ///// Visit vector /////
        vector<int> visit_vect(n, 0);

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Result maximun summary value /////
        int res_max_sum = 0;


        /*Recursion-based DFS loop traversal*/
        for (int restricted_idx = 0; (restricted_idx < len_restricted); (restricted_idx++)) //Whole
        {
            visit_vect[restricted[restricted_idx]] = 1; //Keep updating, overwriting

        } //Whole

        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1]); //Keep updating, recording
            (root_child_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0]); //Keep updating, recording

        } //Whole

        dfsTraversal(root_child_map, visit_vect, 0, res_max_sum); //Recursion function call

        return res_max_sum;
    }


    void dfsTraversal(unordered_map<int, vector<int>> & root_child_map, vector<int> & visit_vect, int record_val, int & res_max_sum)
    {
        //===========================================================================//
        // Input type:                                                               //
        //   - unordered_map<int, vector<int>> ref. (root-child dictionary, hashmap) //
        //   - vector<vector<int>> ref. (visit vector)                               //
        //   - int (record node-value)                                               //
        //   - int ref. (result maximun summary value)                               //
        // Return type:                                                              // 
        //   - void (no return)                                                      //
        //===========================================================================//
        if (visit_vect[record_val]) { return; } //Issue, Boundary-case handling

        (res_max_sum++); visit_vect[record_val] = 1; //Update, Overwrite

        for (const int & next_val: root_child_map[record_val]) //Whole
        {
            dfsTraversal(root_child_map, visit_vect, next_val, res_max_sum); //Recursion function call

        } //Whole
    }
};
