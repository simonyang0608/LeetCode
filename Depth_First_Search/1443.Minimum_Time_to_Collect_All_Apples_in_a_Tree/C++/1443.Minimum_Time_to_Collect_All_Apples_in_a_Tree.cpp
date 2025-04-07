class Solution {
public:
    int minTime(int n, vector<vector<int>> & edges, vector<bool> & hasApple) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        //   - vector<bool> ref. (hasApple vector)     //
        // Return type:                                //
        //   - int (result minimun times)              //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Visit vector /////
        vector<bool> visit_vect(n, false);


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        visit_vect[0] = true; //Update, Overwrite

        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1]); //Keep updating, recording
            (root_child_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0]); //Keep updating, recording

        } //Whole

        return dfsTraversal(root_child_map, 0, visit_vect, hasApple);
    }


    int dfsTraversal(unordered_map<int, vector<int>> & root_child_map, int record_node, 
                     vector<bool> & visit_vect, const vector<bool> & hasApple)
    {
        //===========================================================================//
        // Input type:                                                               //
        //   - unordered_map<int, vector<int>> ref. (root-child dictionary, hashmap) //
        //   - int (record node)                                                     //
        //   - vector<bool> ref. (visit vector)                                      //
        //   - const vector<bool> ref. (hasApple vector)                             //
        // Return type:                                                              //
        //   - int (result minimun times)                                            //
        //===========================================================================//

        /*Initialize*/
        ///// Result summary counter /////
        int res_cnter = 0;

        /*Whole process, flow*/
        for (int & next_node: root_child_map[record_node]) //Whole
        {
            ///// Check if the next node existed or not /////
            if (! visit_vect[next_node])
            {
                visit_vect[next_node] = true; //Keep updating, overwriting

                int record_cnter = dfsTraversal(root_child_map, next_node, visit_vect, hasApple); //Record summary counter

                ///// Check if the current status matched conditions or not /////
                if (record_cnter || hasApple[next_node]) { res_cnter += (record_cnter + 2); } //Keep updating, accumulating
            }

        } //Whole

        return res_cnter;
    }
};
