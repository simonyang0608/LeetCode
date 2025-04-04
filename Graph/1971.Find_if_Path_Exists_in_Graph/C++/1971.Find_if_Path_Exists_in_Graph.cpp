class Solution {
public:
    bool validPath(int n, vector<vector<int>> & edges, int source, int destination) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        //   - int (source node)                       //
        //   - int (destination node)                  //
        // Return type:                                //
        //   - bool (result flag)                      //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Visit vector /////
        vector<bool> visit_vect(n, false);


        /*Recursion-based DFS loop traversal*/
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1]); //Keep updating, recording
            (root_child_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0]); //Keep updating, recording

        } //Whole

        return dfsTraversal(root_child_map, source, destination, visit_vect);
    }


    bool dfsTraversal(unordered_map<int, vector<int>> & root_child_map, int & record_node, 
                      const int & destination, vector<bool> & visit_vect)
    {
        //===========================================================================//
        // Input type:                                                               //
        //   - unordered_map<int, vector<int>> ref. (root-child dictionary, hashmap) //
        //   - int ref. (record node)                                                //
        //   - const int ref. int (destination node)                                 //
        //   - vector<bool> ref. (visit vector)                                      //
        // Return type:                                                              //
        //   - bool (result flag)                                                    //
        //===========================================================================//

        /*Whole process, flow*/
        ///// Check if the current node is visited or not /////
        if (! visit_vect[record_node])
        {
            visit_vect[record_node] = true; //Update, Overwrite

            ///// Check if the current node reach target or not /////
            if (record_node == destination) { return true; }

            for (int & next_node: root_child_map[record_node]) //Whole
            {
                ///// Check if the current node is the path or not /////
                if (dfsTraversal(root_child_map, next_node, destination, visit_vect)) { return true; }
                 
            } //Whole
        }

        return false;
    }
};
