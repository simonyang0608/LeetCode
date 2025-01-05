class Solution {
public:
    double maxProbability(int n, vector<vector<int>> & edges, vector<double> & succProb, int start_node, int end_node) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        //   - vector<double> ref. (succProb vector)   //
        //   - int (start node)                        //
        //   - int (end node)                          //
        // Return type:                                //
        //   - double (result maximun probalility)     //
        //=============================================//
        
        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<pair<int, double>>> record_map;

        ///// Record heap, priority-queue /////
        priority_queue<pair<double, int>> record_pq;

        ///// Product summary-path vector /////
        vector<double> prod_path_vect(n, 0.0);

        ///// Record value /////
        int record_val;

        ///// Record distance, next distance /////
        double record_dist, next_dist;


        /*Dijkstra's based loop traversal with recorded vectors, dictionary, hashmap*/
        ///// Step 1: Record root-child formations with dictionary, hashmap /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (record_map[(edges[edges_idx])[0]]).push_back(make_pair((edges[edges_idx])[1], succProb[edges_idx])); //Keep updating, recording
            (record_map[(edges[edges_idx])[1]]).push_back(make_pair((edges[edges_idx])[0], succProb[edges_idx])); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        record_pq.push(make_pair(1.0, start_node)); //Update, Record

        prod_path_vect[start_node] = 1.0; //Update, Overwrite

        while (! record_pq.empty()) //Cycled-times
        {
            record_val = (record_pq.top()).second; record_dist = (record_pq.top()).first; //Record values, distances, ...

            record_pq.pop(); //Keep updating, popped

            ///// Check if the current node is valid or not /////
            if (prod_path_vect[record_val] != record_dist) { continue; }

            for (pair<int, double> & record_pair: record_map[record_val]) //Next-nodes
            {
                next_dist = (prod_path_vect[record_val] * record_pair.second); //Next distance

                ///// Check if the next distance is larger or not /////
                if (next_dist > prod_path_vect[record_pair.first])
                {
                    record_pq.push(make_pair(next_dist, record_pair.first)); //Keep updating, recording

                    prod_path_vect[record_pair.first] = next_dist; //Keep updating, overwriting
                }
                else { ; }

            } //Next-nodes

        } //Cycled-times

        return prod_path_vect[end_node];
    }
};
