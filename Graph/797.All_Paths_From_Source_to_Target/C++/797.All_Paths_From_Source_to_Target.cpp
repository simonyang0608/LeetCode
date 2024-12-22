class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> & graph) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (graph vector) //
        // Return type:                                //
        //   - vector<vector<int>> (result vector)     //
        //=============================================//

        /*Initialize*/
        ///// Length of graph /////
        int len_graph = graph.size();

        (len_graph--);

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<int>> record_map;

        ///// Record vector /////
        vector<int> record_vect;

        ///// Result vector /////
        vector<vector<int>> res_vect;


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record root-neighbors with dictionary, hashmap /////
        for (int graph_idx = 0; (graph_idx < len_graph); (graph_idx++)) //Root-node
        {
            for (int & neighbors: graph[graph_idx]) //Neighbors
            {
                (record_map[graph_idx]).emplace_back(neighbors); //Keep updating, recording

            } //Neighbors

        } //Root-node

        ///// Step 2: Looped-traversal withh recorded dictionary, hashmap /////
        dfsTraversal(record_map, 0, len_graph, record_vect, res_vect); //Recursion function call

        return res_vect;
    }


    void dfsTraversal(unordered_map<int, vector<int>> & record_map, int record_val, int & final_val, vector<int> & record_vect, vector<vector<int>> & res_vect)
    {
        //=======================================================================//
        // Input type:                                                           //
        //   - unordered_map<int, vector<int>> ref. (record dictionary, hashmap) //
        //   - int (record value)                                                //
        //   - int ref. (final value)                                            //
        //   - vector<int> ref. (record vector)                                  //
        //   - vector<vector<int>> ref. (result vector)                          //
        // Return type:                                                          //
        //   - void (no return)                                                  //
        //=======================================================================//

        /*Whole process, flow*/
        record_vect.emplace_back(record_val); //Update, Record

        ///// Check if the current root node-value matched conditions or not /////
        if (record_val == final_val)
        {
            res_vect.push_back(record_vect); //Update, Record

            record_vect.pop_back(); //Update, Popped

            return;
        }

        for (int & next_val: record_map[record_val]) //Whole
        {
            dfsTraversal(record_map, next_val, final_val, record_vect, res_vect); //Recursion function call

        } //Whole

        record_vect.pop_back();
    }
};
