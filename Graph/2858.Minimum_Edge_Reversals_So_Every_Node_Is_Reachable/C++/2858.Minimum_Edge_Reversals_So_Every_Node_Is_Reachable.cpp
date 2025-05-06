class Solution {
public:
    vector<int> minEdgeReversals(int n, vector<vector<int>> & edges) 
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

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<pair<int, int>>> root_child_map;

        ///// Record queue /////
        queue<int> record_queue;

        ///// Result vector /////
        vector<int> res_vect(n, 0);


        /*Breath-first search based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes informations with dictionary, hashmap /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1], 1); //Keep updating, recording
            (root_child_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0], (-1)); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        bfs_prev(root_child_map, record_queue, n, res_vect); //BFS function call (i.e. previous step)

        bfs_post(root_child_map, record_queue, n, res_vect); //BFS function call (i.e. post-final step)

        return res_vect;
    }


    void bfs_prev(unordered_map<int, vector<pair<int, int>>> & root_child_map, queue<int> & record_queue, 
                  const int & n, vector<int> & res_vect)
    {
        //======================================================================================//
        // Input type:                                                                          // 
        //   - unordered_map<int, vector<pair<int, int>>> ref. (root-child dictionary, hashmap) //
        //   - queue<int> ref. (record queue)                                                   //
        //   - const int ref. (n-th nodes)                                                      //
        //   - vector<int> ref. (result vector)                                                 //
        // Return type:                                                                         //
        //   - void (no return)                                                                 //
        //======================================================================================//

        /*Initialize*/
        ///// Visit vector /////
        vector<bool> visit_vect(n, false);

        /*Whole process, flow*/
        record_queue.emplace(0); //Update, Record

        visit_vect[0] = true; //Update, Overwrite

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int record_node = record_queue.front(); record_queue.pop(); //Keep updating, popped

                for (pair<int, int> & next_pair: root_child_map[record_node]) //Next-nodes
                {
                    ///// Check if the next node is visited or not /////
                    if (visit_vect[next_pair.first]) { continue; }

                    res_vect[0] += (next_pair.second < 0) ? 1 : 0; //Keep updating, accumulating

                    visit_vect[next_pair.first] = true; //Keep updating, overwriting

                    record_queue.emplace(next_pair.first); //Keep updating, recording

                } //Next-nodes

            } //Queue-size

        } //Cycled-times

        return;
    }


    void bfs_post(unordered_map<int, vector<pair<int, int>>> & root_child_map, queue<int> & record_queue, 
                  const int & n, vector<int> & res_vect)
    {
        //======================================================================================//
        // Input type:                                                                          // 
        //   - unordered_map<int, vector<pair<int, int>>> ref. (root-child dictionary, hashmap) //
        //   - queue<int> ref. (record queue)                                                   //
        //   - const int ref. (n-th nodes)                                                      //
        //   - vector<int> ref. (result vector)                                                 //
        // Return type:                                                                         //
        //   - void (no return)                                                                 //
        //======================================================================================//

        /*Initialize*/
        ///// Visit vector /////
        vector<bool> visit_vect(n, false);

        /*Whole process, flow*/
        record_queue.emplace(0); //Update, Record

        visit_vect[0] = true; //Update, Overwrite

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int record_node = record_queue.front(); record_queue.pop(); //Keep updating, popped

                for (pair<int, int> & next_pair: root_child_map[record_node]) //Next-nodes
                {
                    ///// Check if the next node is visited or not /////
                    if (visit_vect[next_pair.first]) { continue; }

                    int next_node = next_pair.first; int next_scl = next_pair.second; //Next nodes informations

                    visit_vect[next_node] = true; //Keep updating, overwriting

                    res_vect[next_node] = (res_vect[record_node] + ((next_scl > 0) ? 1 : (-1))); //Keep updating, overwriting

                    record_queue.emplace(next_node); //Keep updating, recording

                } //Next-nodes

            } //Queue-size

        } //Cycled-times

        return;
    }
};
