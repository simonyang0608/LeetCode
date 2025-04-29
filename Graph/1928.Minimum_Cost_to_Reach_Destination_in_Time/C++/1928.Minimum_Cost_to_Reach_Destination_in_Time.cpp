class Solution {
public:
    int minCost(int maxTime, vector<vector<int>> & edges, vector<int> & passingFees) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (maximun times)                     //
        //   - vector<vector<int>> ref. (edges vector) //
        //   - vector<int> ref. (passingFees vector)   //
        // Return type:                                //
        //   - int (result minimun fees)               //
        //=============================================//

        /*Initialize*/
        ///// Length of edges, total nodes /////
        int len_edges = edges.size(), total_nodes = passingFees.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<pair<int, int>>> root_child_map;

        ///// Record heap, priority-queue /////
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> record_pq;

        ///// Edge, Fee-rank vectors /////
        vector<int> edge_rank_vect(total_nodes, INT_MAX), fee_rank_vect(total_nodes, INT_MAX);


        /*Dijkstras' based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes informations with dictionary, hashmap /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1], (edges[edges_idx])[2]); //Keep updating, recording
            (root_child_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0], (edges[edges_idx])[2]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        record_pq.push({passingFees[0], 0, 0}); //Update, Record

        edge_rank_vect[0] = 0; fee_rank_vect[0] = passingFees[0]; //Update, Overwrite

        while (! record_pq.empty()) //Cycled-times
        {
            int record_fee = (record_pq.top())[0]; int record_node = (record_pq.top())[1]; //Record fee, node

            int record_times = (record_pq.top())[2]; record_pq.pop(); //Keep updating, popped

            ///// Check if the current node reached target or not /////
            if (record_node == (total_nodes - 1)) { return record_fee; }

            for (pair<int, int> & next_pair: root_child_map[record_node]) //Next-nodes
            {
                ///// Check if the next times matched conditions or not /////
                if ((record_times + next_pair.second) > maxTime) { continue; }

                int next_node = next_pair.first; int next_fee = (record_fee + passingFees[next_node]); //Next node, fee

                int next_times = (record_times + next_pair.second); //Next times

                ///// Check if the next nodes informations matched conditions or not /////
                if ((edge_rank_vect[next_node] > next_times) || (fee_rank_vect[next_node] > next_fee))
                {
                    edge_rank_vect[next_node] = next_times; //Keep updating, overwriting

                    fee_rank_vect[next_node] = next_fee; //Keep updating, overwriting

                    record_pq.push({next_fee, next_node, next_times}); //Keep updating, recording
                }
                else { ; }

            } //Next-nodes

        } //Cycled-times

        return (-1);
    }
};
