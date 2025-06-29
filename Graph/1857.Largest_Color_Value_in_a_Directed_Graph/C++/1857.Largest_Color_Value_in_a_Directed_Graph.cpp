class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>> & edges) 
    {
        //=============================================//
        // Input type:                                 //
        //   - string (colors string)                  //
        //   - vector<vector<int>> ref. (edges vector) //
        // Return type:                                //
        //   - int (result maximun summary counter)    //
        //=============================================//

        /*Initialize*/
        ///// Length of colors vector /////
        int len_colors = colors.size();

        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Root-child vector /////
        vector<vector<int>> root_child_vect(len_colors);

        ///// In-degree vector /////
        vector<int> in_degree(len_colors, 0);

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<int>> record_dp(len_colors, vector<int>(26, 0));

        ///// Record queue /////
        queue<int> record_queue;

        ///// Record nodes summary counter /////
        int record_node_cnter = 0;

        ///// Result maximun summary counter /////
        int res_max_cnter = 0;


        /*Breath-first search based loop traversal with recorded vectors*/
        ///// Step 1: Record indexed-nodes informations with vectors /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_vect[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1]); //Keep updating, recording

            ((in_degree[(edges[edges_idx])[1]])++); //Keep updating, overwriting

        } //Whole

        for (int node_idx = 0; (node_idx < len_colors); (node_idx++)) //N-th nodes
        {
            ///// Check if the current nodes in-degrees matched conditions or not /////
            if (in_degree[node_idx]) { continue; }

            record_queue.emplace(node_idx); //Keep updating, recording

        } //N-th nodes

        ///// Step 2: Looped-traversal with recorded vectors /////
        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int curr_node = record_queue.front(); record_queue.pop(); //Current node

                (record_node_cnter++); //Keep updating, accumulating

                (((record_dp[curr_node])[(colors[curr_node] - 'a')])++); //Keep updating, accumulating

                res_max_cnter = ((record_dp[curr_node])[(colors[curr_node] - 'a')] > res_max_cnter) ?
                                 (record_dp[curr_node])[(colors[curr_node] - 'a')] : res_max_cnter; //Keep updating, overwriting

                for (const int & next_node: root_child_vect[curr_node]) //Next-nodes
                {
                    for (int char_idx = 0; (char_idx < 26); (char_idx++)) //Whole
                    {
                        (record_dp[next_node])[char_idx] = ((record_dp[curr_node])[char_idx] > (record_dp[next_node])[char_idx]) ?
                                                            (record_dp[curr_node])[char_idx] : (record_dp[next_node])[char_idx]; //Keep updating, overwriting

                    } //Whole

                    ///// Check if the current nodes in-degrees matched conditions or not /////
                    if (! (--(in_degree[next_node]))) { record_queue.emplace(next_node); } //Keep updating, recording
                    else { ; }

                } //Next-nodes

            } //Queue-size

        } //Cycled-times

        return (record_node_cnter == len_colors) ? res_max_cnter : (-1);
    }
};
