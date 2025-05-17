class Solution {
public:
    int makeConnected(int n, vector<vector<int>> & connections) 
    {
        //===================================================//
        // Input type:                                       //
        //   - int (n-th nodes)                              //
        //   - vector<vector<int>> ref. (connections vector) //
        // Return type:                                      //
        //   - int (result minimun operations)               //
        //===================================================//
        if ((n - 1) > connections.size()) { return (-1); } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of connections vector /////
        int len_connections = connections.size();

        ///// Root-child vector /////
        vector<vector<int>> root_child_vect(n);

        ///// Visit vector /////
        vector<bool> visit_vect(n, false);

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Recursion-based DFS loop traversal with recorded vector*/
        ///// Step 1: Record indexed-nodes informations with recorded vector /////
        for (int connections_idx = 0; (connections_idx < len_connections); (connections_idx++)) //Whole
        {
            (root_child_vect[(connections[connections_idx])[0]]).emplace_back((connections[connections_idx])[1]); //Keep updating, recording
            (root_child_vect[(connections[connections_idx])[1]]).emplace_back((connections[connections_idx])[0]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th nodes
        {
            ///// Check if the current node is visited or not /////
            if (visit_vect[n_idx]) { continue; }
 
            visit_vect[n_idx] = true; //Keep updating, recording

            (res_cnter++); //Keep updating, accumulating

            dfsTraversal(root_child_vect, n_idx, visit_vect); //Recursion function call

        } //N-th nodes

        return (res_cnter - 1);
    }


    void dfsTraversal(vector<vector<int>> & root_child_vect, const int & record_node, vector<bool> & visit_vect)
    {
        //===================================================//
        // Input type:                                       //
        //   - vector<vector<int>> ref. (root-child vector)  //
        //   - const int ref. (record node)                  //
        //   - vector<bool> ref. (visit vector)              //
        // Return type:                                      //
        //   - void (no return)                              //
        //===================================================//

        /*Whole process, flow*/
        for (int & next_node: root_child_vect[record_node]) //Next-nodes
        {
            ///// Check if the current node is visited or not /////
            if (visit_vect[next_node]) { continue; }

            visit_vect[next_node] = true; //Keep updating, recording

            dfsTraversal(root_child_vect, next_node, visit_vect); //Recursion function call

        } //Next-nodes

        return;
    }
};
