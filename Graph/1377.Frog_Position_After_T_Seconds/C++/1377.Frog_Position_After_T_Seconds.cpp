class Solution {
public:
    double frogPosition(int n, vector<vector<int>> & edges, int t, int target) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        //   - int (t seconds)                         //
        //   - int (target node value)                 //
        // Return type:                                //
        //   - double (result probability)             //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Root-child vector /////
        vector<vector<int>> root_child_vect((n + 1));

        ///// Visit vector /////
        vector<bool> visit_vect((n + 1), false);

        ///// Probability vector /////
        vector<double> prob_vect((n + 1), 0.0);

        ///// Record queue /////
        queue<int> record_queue;


        /*Breath-first search based loop traversal with recorded vectors*/
        ///// Step 1: Record indexed-nodes informations with vectors /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_vect[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1]); //Keep updating, recording
            (root_child_vect[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded vectors /////
        visit_vect[1] = true; //Update, Overwrite

        prob_vect[1] = 1.0; //Update, Overwrite

        record_queue.emplace(1); //Update, Record

        while ((! record_queue.empty()) && (t--)) //Cycled-times
        {
            for (int queue_idx = (record_queue.size()); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int curr_node = record_queue.front(); record_queue.pop(); //Current node

                int edge_cnter = 0; //Edge summary counter

                for (const int & next_node: root_child_vect[curr_node]) //Next-nodes
                {
                    ///// Check if the next node is visited or not /////
                    if (visit_vect[next_node]) { continue; }

                    (edge_cnter++); //Keep updating, accumulating

                } //Next-nodes

                for (const int & next_node: root_child_vect[curr_node]) //Next-nodes
                {
                    ///// Check if the next node is visited or not /////
                    if (visit_vect[next_node]) { continue; }

                    visit_vect[next_node] = true; //Keep updating, overwriting

                    prob_vect[next_node] = (prob_vect[curr_node] * (1.0 / edge_cnter)); //Keep updating, overwriting

                    record_queue.emplace(next_node); //Keep updating, recording

                } //Next-nodes

                ///// Check if the frog stayed at the same vertex or not /////
                if (edge_cnter) { prob_vect[curr_node] = 0.0; } //Keep updating, overwriting
                else { ; }

            } //Queue-size

        } //Cycled-times

        return prob_vect[target];
    }
};
