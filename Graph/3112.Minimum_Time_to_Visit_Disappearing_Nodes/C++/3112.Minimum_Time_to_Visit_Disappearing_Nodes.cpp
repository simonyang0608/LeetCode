class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>> & edges, vector<int> & disappear) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        //   - vector<int> ref. (disappear vector)     //
        // Return type:                                //
        //   - vector<int> (result vector)             //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<pair<int, int>>> root_child_map;

        ///// Record heap, priority-queue /////
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> record_pq;

        ///// Edge rank vector /////
        vector<int> edge_rank_vect(n, INT_MAX);

        ///// Result vector /////
        vector<int> res_vect(n, (-1));


        /*Dijkstras' based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes informations with dictionary, hashmap /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1], (edges[edges_idx])[2]); //Keep updating, recording
            (root_child_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0], (edges[edges_idx])[2]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        record_pq.emplace(0, 0); //Update, Record

        edge_rank_vect[0] = 0; //Update, Overwrite

        while (! record_pq.empty()) //Cycled-times
        {
            int record_times = (record_pq.top()).first; int record_node = (record_pq.top()).second; //Record times, node

            record_pq.pop(); //Keep updating, popped

            ///// Check if the current times matched conditions or not /////
            if (record_times != edge_rank_vect[record_node]) { continue; }

            res_vect[record_node] = record_times; //Keep updating, overwriting

            for (pair<int, int> & next_pair: root_child_map[record_node]) //Next-nodes
            {
                int next_node = next_pair.first; int next_times = (record_times + next_pair.second); //Next node, times

                ///// Check if the next times matched conditions or not /////
                if (next_times >= disappear[next_node]) { continue; }

                ///// Check if the next times matched conditions or not /////
                if (edge_rank_vect[next_node] > next_times)
                {
                    edge_rank_vect[next_node] = next_times; //Keep updating, overwriting

                    record_pq.emplace(next_times, next_node); //Keep updating, recording
                }
                else { ; }

            } //Next-nodes

        } //Cycled-times

        return res_vect;
    }
};
