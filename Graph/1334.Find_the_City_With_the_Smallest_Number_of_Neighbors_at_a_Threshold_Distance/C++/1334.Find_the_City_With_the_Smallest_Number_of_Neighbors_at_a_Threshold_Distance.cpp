class Solution {
public:
    int findTheCity(int n, vector<vector<int>> & edges, int distanceThreshold) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        //   - int (distanceThreshold value)           //
        // Return type:                                //
        //   - int (result maximun node)               //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<pair<int, int>>> root_child_map;

        ///// Result minimun summary counter, maximun node /////
        int res_min_cnter = INT_MAX, res_max_node = (-1);


        /*Dijkstras' based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes informations with dictionary, hashmap /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1], (edges[edges_idx])[2]); //Keep updating, recording
            (root_child_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0], (edges[edges_idx])[2]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th nodes
        {
            int record_cnter = dijkstra(root_child_map, n_idx, n, distanceThreshold); //Record summary counter

            ///// Check if the current summary counter matched conditions or not /////
            if (record_cnter <= res_min_cnter)
            {
                res_min_cnter = record_cnter; //Keep updating, overwriting

                res_max_node = n_idx; //Keep updating, overwriting
            }
            else { ; }

        } //N-th nodes

        return res_max_node;
    }


    int dijkstra(unordered_map<int, vector<pair<int, int>>> & root_child_map, const int & record_node, 
                 const int & n, const int & distanceThreshold)
    {
        //======================================================================================//
        // Input type:                                                                          //
        //   - unordered_map<int, vector<pair<int, int>>> ref. (root-child dictionary, hashmap) //
        //   - const int ref. (record node)                                                     //
        //   - const int ref. (n-th nodes)                                                      //
        //   - const int ref. (distanceThreshold value)                                         //
        // Return type:                                                                         //
        //   - int (result summary counter)                                                     //
        //======================================================================================//

        /*Initialize*/
        ///// Edge rank vector /////
        vector<int> edge_rank_vect(n, INT_MAX);

        ///// Record heap, priority-queue /////
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> record_pq;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Whole process, flow*/
        record_pq.emplace(0, record_node); //Update, Record

        edge_rank_vect[record_node] = 0; //Update, Record

        while (! record_pq.empty()) //Cycled-times
        {
            int curr_dist = (record_pq.top()).first; int curr_node = (record_pq.top()).second; //Current distance, node

            record_pq.pop(); //Keep updating, popped

            ///// Check if the current node matched conditions or not /////
            if (curr_dist != edge_rank_vect[curr_node]) { continue; }

            for (pair<int, int> & next_pair: root_child_map[curr_node]) //Next-nodes
            {
                int next_node = next_pair.first; int next_dist = (curr_dist + next_pair.second); //Next node, distance

                ///// Check if the next nodes informations matched conditions or not /////
                if (edge_rank_vect[next_node] > next_dist)
                {
                    edge_rank_vect[next_node] = next_dist; //Keep updating, recording

                    record_pq.emplace(next_dist, next_node); //Keep updating, recording
                }
                else { ; }

            } //Next-nodes

        } //Cycled-times

        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th nodes
        {
            ///// Check if the current node matched conditions or not /////
            if (n_idx == record_node) { continue; }

            ///// Check if the current node information matched conditions or not /////
            if (edge_rank_vect[n_idx] <= distanceThreshold) { (res_cnter++); } //Keep updating, accumulating
            else { ; }

        } //N-th nodes

        return res_cnter;
    }
};
