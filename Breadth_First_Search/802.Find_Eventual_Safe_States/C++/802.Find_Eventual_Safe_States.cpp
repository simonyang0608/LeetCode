class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>> & graph) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (graph vector) //
        // Return type:                                //
        //   - vector<int> (result vector)             //
        //=============================================//

        /*Initialize*/
        ///// Length of graph vector /////
        int len_graph = graph.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Edge summary counter vector /////
        vector<int> edge_cnter_vect(len_graph, 0);

        ///// Record queue /////
        queue<int> record_queue;

        ///// Result vector /////
        vector<int> res_vect;


        /*Breath-first search based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes information with dictionary, hashmap /////
        for (int graph_idx = 0; (graph_idx < len_graph); (graph_idx++)) //Whole
        {
            for (int sub_idx = ((graph[graph_idx]).size() - 1); (sub_idx >= 0); (sub_idx--)) //Sub
            {
                (root_child_map[(graph[graph_idx])[sub_idx]]).emplace_back(graph_idx); //Keep updating, recording

                ((edge_cnter_vect[graph_idx])++); //Keep updating, recording

            } //Sub

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int graph_idx = 0; (graph_idx < len_graph); (graph_idx++)) //Whole
        {
            ///// Check if the current node matched conditions or not /////
            if (! edge_cnter_vect[graph_idx]) { record_queue.emplace(graph_idx); } //Keep updating, recording
            else { ; }

        } //Whole

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int record_node = record_queue.front(); record_queue.pop(); //Record node

                res_vect.emplace_back(record_node); //Keep updating, recording

                for (const int & next_node: root_child_map[record_node]) //Part
                {
                    ///// Check if the current summary counter matched conditions or not /////
                    if (! (--(edge_cnter_vect[next_node]))) { record_queue.emplace(next_node); } //Keep updating, recording
                    else { ; }

                } //Part

            } //Queue-size

        } //Cycled-times

        sort(res_vect.begin(), res_vect.end()); //Sorted-operations

        return res_vect;
    }
};
