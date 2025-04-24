class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>> & edges) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        // Return type:                                //
        //   - vector<int> (result vector)             //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// In-degree vector /////
        vector<int> in_degree(n, 0);

        ///// Result vector /////
        vector<int> res_vect;


        /*Greedy-based loop traversal*/
        ///// Step 1: Record indexed-nodes informations with vector /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            ((in_degree[(edges[edges_idx])[1]])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th nodes
        {
            ///// Check if the current nodes' in-degree matched conditions or not /////
            if (! in_degree[n_idx]) { res_vect.emplace_back(n_idx); } //Keep updating, recording
            else { ; }

        } //N-th nodes

        return res_vect;
    }
};
