class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>> & edges) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        // Return type:                                //
        //   - int (result minimun length)             //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Root-child vector /////
        vector<vector<int>> root_child_vect(n);

        ///// Record queue /////
        queue<pair<int, int>> record_queue;

        ///// Result minimun length /////
        int res_min_length = INT_MAX;


        /*Breath-first search based loop traversal with recorded vectors*/
        ///// Step 1: Record indexed-nodes informations with vectors /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_vect[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1]); //Keep updating, recording
            (root_child_vect[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded vectors /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th nodes
        {
            bfsTraversal(n, root_child_vect, n_idx, record_queue, res_min_length); //BFS function call

        } //N-th nodes

        return (res_min_length == INT_MAX) ? (-1) : res_min_length;
    }


    void bfsTraversal(const int & n, const vector<vector<int>> & root_child_vect, const int & record_node,
                      queue<pair<int, int>> & record_queue, int & res_min_length)
    {
        //========================================================//
        // Input type:                                            //
        //   - const int ref. n (n-th nodes)                      //
        //   - const vector<vector<int>> ref. (root-child vector) //
        //   - const int ref. (record node)                       //
        //   - queue<pair<int, int>> ref. (record queue)          //
        //   - int ref. (result minimun length)                   //
        // Return type:                                           //
        //   - void (no return)                                   //
        //========================================================//

        /*Initialize*/
        ///// Length vector /////
        vector<int> length_vect(n, (-1));

        /*Whole process, flow*/
        length_vect[record_node] = 0; //Update, Overwrite

        record_queue.emplace(record_node, (-1)); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            int curr_node = (record_queue.front()).first; //Current node
            int curr_parent = (record_queue.front()).second; //Current parent

            record_queue.pop(); //Keep updating, popped

            for (const int & next_node: root_child_vect[curr_node]) //Next-nodes
            {
                ///// Check if the next-node is visited or not /////
                if (length_vect[next_node] == (-1))
                {
                    length_vect[next_node] = (length_vect[curr_node] + 1); //Keep updating, overwriting

                    record_queue.emplace(next_node, curr_node); //Keep updating, recording
                }
                else
                {
                    if (next_node != curr_parent)
                    {
                        res_min_length = min(res_min_length, (length_vect[next_node] + (length_vect[curr_node] + 1))); //Keep updating, overwriting
                    }
                    else { ; }
                }

            } //Next-nodes

        } //Cycled-times

        return;
    }
};
