class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>> & edges) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        // Return type:                                //
        //   - int (result summary counter)            //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<int>> record_map;

        ///// Visit vector /////
        vector<int> visit_vect(n, 0);

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record neighbors informations with dictionary, hashmap /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (record_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1]); //Keep updating, recording
            (record_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th nodes
        {
            ///// Check if the current nodes is visited or not /////
            if (! visit_vect[n_idx])
            {
                int vertex = 0; int edge = 0; //Vertex, Edge

                dfsTraversal(record_map, visit_vect, n_idx, vertex, edge); //Recursion function call

                res_cnter += ((vertex * (vertex - 1)) == edge) ? 1 : 0; //Keep updating, accumulating
            }
            else { ; }

        } //N-th nodes

        return res_cnter;
    }


    void dfsTraversal(unordered_map<int, vector<int>> & record_map, vector<int> & visit_vect, int & record_val, int & vertex, int & edge)
    {
        //=======================================================================//
        // Input type:                                                           //
        //   - unordered_map<int, vector<int>> ref. (record dictionary, hashmap) //
        //   - vector<int> ref. (visit vector)                                   //
        //   - int ref. (record value)                                           //
        //   - int ref. (vertex)                                                 //
        //   - int ref. (edge)                                                   //
        // Return type:                                                          //
        //   - void (no return)                                                  //
        //=======================================================================//
        (vertex++); //Update, Accumulate

        visit_vect[record_val] = 1; //Update, Overwrite

        for (int & next_val: record_map[record_val]) //Whole
        {
            (edge++); //Keep update, accumulate

            ///// Check if the next nodes is visited or not /////
            if (! visit_vect[next_val]) { dfsTraversal(record_map, visit_vect, next_val, vertex, edge); }

        } //Whole
    }
};
