class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> & edges) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (edges vector) //
        // Return type:                                //
        //   - vector<int> (result vector)             //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Record dictionary, hashmap /////
        map<int, int> record_map;

        ///// Edge rank vector /////
        vector<int> edge_rank_vect(len_edges, 1);

        ///// Result vector /////
        vector<int> res_vect;


        /*Disjoint-set based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes with dictionary, hashmap /////
        for (int n_idx = 1; (n_idx <= len_edges); (n_idx++))
        {
            record_map[n_idx] = n_idx; //Keep updating, recording
        }

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            int fst_node = disjointNode(record_map, (edges[edges_idx])[0]); int scnd_node = disjointNode(record_map, (edges[edges_idx])[1]); //First, Second node

            ///// Check if the current nodes matched conditions or not /////
            if (fst_node == scnd_node) { res_vect = edges[edges_idx]; } //Keep updating, overwriting
            else
            {
                ///// Check if the current edges rank is smaller or not /////
                if (edge_rank_vect[(fst_node - 1)] > edge_rank_vect[(scnd_node - 1)])
                { 
                    record_map[scnd_node] = fst_node; ((edge_rank_vect[(fst_node - 1)])++); //Keep updating, recording
                }
                else { record_map[fst_node] = scnd_node; ((edge_rank_vect[(scnd_node - 1)])++); } //Keep updating, recording
            }

        } //Whole

        return res_vect;
    }


    int disjointNode(map<int, int> & record_map, const int & record_node)
    {
        //=====================================================//
        // Input type:                                         //
        //   - map<int, int> ref. (record dictionary, hashmap) //
        //   - const int ref. (record node)                    //
        // Return type:                                        //
        //   - int (result node)                               //
        //=====================================================//

        /*Whole process, flow*/
        ///// Check if the current node is root node or not /////
        if (record_map[record_node] != record_node)
        {
            record_map[record_node] = disjointNode(record_map, record_map[record_node]); //Recursion function call
        }

        return record_map[record_node];
    }
};
