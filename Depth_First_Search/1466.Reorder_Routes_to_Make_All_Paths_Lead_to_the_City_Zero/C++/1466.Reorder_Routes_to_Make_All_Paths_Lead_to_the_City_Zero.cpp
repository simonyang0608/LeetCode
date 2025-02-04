class Solution {
public:
    int minReorder(int n, vector<vector<int>> & connections) 
    {
        //===================================================//
        // Input type:                                       //
        //   - int (n-th nodes)                              //
        //   - vector<vector<int>> ref. (connections vector) //
        // Return type:                                      //
        //   - int (result minimun summary counter)          //
        //===================================================//

        /*Initialize*/
        ///// Length of connections vector /////
        int len_connections = connections.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Visit vector /////
        vector<bool> visit_vect(n, false);

        ///// Result minimun summary counter /////
        int res_min_cnter = 0;


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record nodes informations with dictionary, hashmap /////
        for (int connections_idx = 0; (connections_idx < len_connections); (connections_idx++)) //Whole
        {
            (root_child_map[(connections[connections_idx])[0]]).emplace_back((connections[connections_idx])[1]); //Keep updating, recording
            (root_child_map[(connections[connections_idx])[1]]).emplace_back(((-1) * (connections[connections_idx])[0])); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        dfsTraversal(root_child_map, visit_vect, 0, res_min_cnter); //Recursion function call

        return res_min_cnter;
    }


    void dfsTraversal(unordered_map<int, vector<int>> & root_child_map, vector<bool> & visit_vect, int record_val, int & res_min_cnter)
    {
        //===========================================================================//
        // Input type:                                                               //
        //   - unordered_map<int, vector<int>> ref. (root-child dictionary, hashmap) //
        //   - vector<bool> ref. (visit vector)                                      //
        //   - int (record nodes value)                                              //
        //   - int ref. (result minimun summary counter)                             //
        // Return type:                                                              //
        //   - void (no return)                                                      //
        //===========================================================================//

        /*Whole process, flow*/
        visit_vect[record_val] = true; //Update, Overwrite

        for (const int & next_val: root_child_map[record_val]) //Whole
        {
            ///// Check if the next nodes value is visited or not /////
            if (! visit_vect[abs(next_val)])
            {
                res_min_cnter += ((next_val > 0) ? 1 : 0); //Keep updating, accumulating

                dfsTraversal(root_child_map, visit_vect, abs(next_val), res_min_cnter); //Recursion function call
            }

        } //Whole
    }
};
