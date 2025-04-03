class Solution {
public:
    int networkDelayTime(vector<vector<int>> & times, int n, int k) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (times vector) //
        //   - int (n-th nodes)                        //
        //   - int (k-th start node)                   //
        // Return type:                                //
        //   - int (result minimun times)              //
        //=============================================//

        /*Initialize*/
        ///// Length of times vector /////
        int len_times = times.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<pair<int, int>>> root_child_map;

        ///// Edge rank vector /////
        vector<int> edge_rank_vect(n, INT_MAX);

        ///// Record heap, priority-queue /////
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> record_pq;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Dijkstra's based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes information with dictionary, hashmap /////
        for (int times_idx = 0; (times_idx < len_times); (times_idx++)) //Whole
        {
            (root_child_map[((times[times_idx])[0] - 1)]).emplace_back(((times[times_idx])[1] - 1), 
                                                                        (times[times_idx])[2]); //Keep updating, recording
        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap
        record_pq.emplace(0, (k - 1)); edge_rank_vect[(k - 1)] = 0; //Update, Overwrite

        while (! record_pq.empty()) //Cycled-times
        {
            int record_wgt = (record_pq.top()).first; int record_node = (record_pq.top()).second; //Record weight, node

            record_pq.pop(); //Keep updating, popped

            ///// Check if the current summary counter matched conditions or not /////
            if (edge_rank_vect[record_node] != record_wgt) { continue; }

            (res_cnter++); //Keep updating, accumulating

            for (const pair<int, int> & next_pair: root_child_map[record_node]) //Next nodes
            {
                int next_node = next_pair.first; int next_wgt = (record_wgt + next_pair.second); //Next node, weight

                ///// Check if the summary counter matched conditions or not /////
                if (edge_rank_vect[next_node] > next_wgt)
                {
                    edge_rank_vect[next_node] = next_wgt; //Keep updating, overwriting

                    record_pq.emplace(next_wgt, next_node); //Keep updating, recording
                }
                else { ; }

            } //Next nodes

        } //Cycled-times

        return (res_cnter == n) ? *max_element(edge_rank_vect.begin(), edge_rank_vect.end()) : (-1);
    }
};
