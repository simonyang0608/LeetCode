class Solution {
public:
    int magnificentSets(int n, vector<vector<int>> & edges) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (edges vector) //
        // Return type:                                //
        //   - int (result maximun groups)             //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Root-child vector /////
        vector<vector<int>> root_child_vect(n);

        ///// Record queue /////
        queue<int> record_queue;

        ///// Result vector /////
        vector<int> res_vect(n, 0);


        /*Breath-first search based loop traversal with recorded vector*/
        ///// Step 1: Record indexed-nodes informations with vector /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_vect[((edges[edges_idx])[0] - 1)]).emplace_back(((edges[edges_idx])[1] - 1)); //Keep updating, recording
            (root_child_vect[((edges[edges_idx])[1] - 1)]).emplace_back(((edges[edges_idx])[0] - 1)); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th nodes
        {
            ///// Check if the current group status matched conditions or not /////
            if (! bfsTraversal(root_child_vect, n, n_idx, record_queue, res_vect))
            {
                return (-1);
            }

        } //N-th nodes

        return accumulate(res_vect.begin(), res_vect.end(), 0);
    }


    bool bfsTraversal(const vector<vector<int>> & root_child_vect, const int & n, const int & record_node, 
                      queue<int> & record_queue, vector<int> & res_vect)
    {
        //========================================================//
        // Input type:                                            //
        //   - const vector<vector<int>> ref. (root-child vector) //
        //   - const int ref. (n-th nodes)                        //
        //   - const int ref. (record node)                       //
        //   - queue<int> ref. (record queue)                     //
        //   - vector<int> ref. (result vector)                   //
        // Return type:                                           //
        //   - bool (result flag)                                 //
        //========================================================//

        /*Initialize*/
        ///// Group vector /////
        vector<int> gp_vect(n, 0);

        ///// Base node /////
        int base_node = record_node;

        ///// Maximun groups /////
        int max_gp = 1;


        /*Whole process, flow*/
        gp_vect[record_node] = 1; //Update, Overwrite

        record_queue.emplace(record_node); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int curr_node = record_queue.front(); //Current node

                base_node = (curr_node < base_node) ? curr_node : base_node; //Keep updating, overwriting

                record_queue.pop(); //Keep updating, popped

                for (const int & next_node: root_child_vect[curr_node]) //Next-nodes
                {
                    ///// Check if the next node is visited or not /////
                    if (! gp_vect[next_node])
                    {
                        gp_vect[next_node] = (gp_vect[curr_node] + 1); //Keep updating, overwriting

                        max_gp = (gp_vect[next_node] > max_gp) ? gp_vect[next_node] : max_gp; //Keep updating, overwriting

                        record_queue.emplace(next_node); //Keep updating, recording
                    }
                    else
                    {
                        ///// Check if the current group status matched conditions or not /////
                        if (abs((gp_vect[next_node] - gp_vect[curr_node])) != 1) { return false; }
                    }

                } //Next-nodes

            } //Queue-size

        } //Cycled-times

        res_vect[base_node] = (max_gp > res_vect[base_node]) ? max_gp : res_vect[base_node]; //Update, Overwrite

        return true;
    }
};
