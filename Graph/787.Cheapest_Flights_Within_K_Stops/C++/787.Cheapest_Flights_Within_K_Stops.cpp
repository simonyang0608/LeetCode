class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>> & flights, int src, int dst, int k) 
    {
        //===============================================//
        // Input type:                                   //
        //   - int (n-th nodes)                          //
        //   - vector<vector<int>> ref. (flights vector) //
        //   - int (src node)                            //
        //   - int (dst node)                            //
        //   - int (k-th stops)                          //
        // Return type:                                  //
        //   - int (result minimun prices)               //
        //===============================================//

        /*Initialize*/
        ///// Length of flights vector /////
        int len_flights = flights.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<pair<int, int>>> root_child_map;

        ///// Record heap, priority-queue /////
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> record_pq;

        ///// Edge, Stop-rank vectors /////
        vector<int> edge_rank_vect(n, INT_MAX), stop_rank_vect(n, INT_MAX);


        /*Dijkstras' based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes informations with dictionary, hashmap /////
        for (int flights_idx = 0; (flights_idx < len_flights); (flights_idx++)) //Whole
        {
            (root_child_map[(flights[flights_idx])[0]]).emplace_back((flights[flights_idx])[1], (flights[flights_idx])[2]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        record_pq.push({0, src, 0}); //Update, Record

        edge_rank_vect[src] = 0; stop_rank_vect[src] = 0; //Update, Overwrite

        while (! record_pq.empty()) //Cycled-times
        {
            int record_wgt = (record_pq.top())[0]; int record_node = (record_pq.top())[1]; //Record weight, node

            int record_stops = (record_pq.top())[2]; record_pq.pop(); //Keep updating, popped

            ///// Check if the current node reached target or not /////
            if (record_node == dst) { return record_wgt; }

            for (pair<int, int> & next_pair: root_child_map[record_node]) //Next-nodes
            {
                ///// Check if the next stops exceed boundary or not /////
                if ((record_stops + 1) > (k + 1)) { continue; }

                int next_node = next_pair.first; int next_wgt = (record_wgt + next_pair.second); //Next nodes informations

                int next_stops = (record_stops + 1); //Next stops

                ///// Check if the next nodes informations matched conditions or not /////
                if ((edge_rank_vect[next_node] > next_wgt) || (stop_rank_vect[next_node] > next_stops))
                {
                    edge_rank_vect[next_node] = next_wgt; stop_rank_vect[next_node] = next_stops; //Keep updating, overwriting

                    record_pq.push({next_wgt, next_node, next_stops}); //Keep updating, recording
                }
                else { ; }

            } //Next-nodes

        } //Cycled-times

        return (-1);
    }
};
