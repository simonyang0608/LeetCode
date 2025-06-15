class Solution {
public:
    bool isBipartite(vector<vector<int>> & graph) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (graph vector) //
        // Return type:                                //
        //   - bool (result flag)                      //
        //=============================================//

        /*Initialize*/
        ///// Length of graph vector /////
        int len_graph = graph.size();

        ///// Color vector /////
        vector<int> color_vect(len_graph, 0);

        ///// Record queue /////
        queue<int> record_queue;


        /*Breath-first search based loop traversal*/
        for (int record_idx = 0;(record_idx < len_graph); (record_idx++)) //N-th nodes
        {
            ///// Check if the current node is visited or not /////
            if (color_vect[record_idx]) { continue; }

            ///// Check if the whole nodes is bipartite or not /////
            if (! is_bipartite(graph, color_vect, record_idx, record_queue))
            {
                return false;
            }

        } //N-th nodes

        return true;
    }


    bool is_bipartite(const vector<vector<int>> & graph, vector<int> & color_vect,
                      const int & record_node, queue<int> & record_queue)
    {
        //===================================================//
        // Input type:                                       //
        //   - const vector<vector<int>> ref. (graph vector) //
        //   - vector<int> ref. (color vector)               //
        //   - const int ref. (record node)                  //
        //   - queue<int> ref. (record queue)                //
        // Return type:                                      //
        //   - bool (result flag)                            //
        //===================================================//

        /*Whole process, flow*/
        color_vect[record_node] = 1; //Update, Overwrite

        record_queue.emplace(record_node); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int curr_node = record_queue.front(); record_queue.pop(); //Keep updating, popped

                for (const int & next_node: graph[curr_node]) //Next-nodes
                {
                    ///// Check if the next-node is visited or not /////
                    if (! color_vect[next_node])
                    {
                        color_vect[next_node] = (color_vect[curr_node] * (-1)); //Keep updating, overwriting

                        record_queue.emplace(next_node); //Keep updating, recording
                    }
                    else
                    {
                        ///// Check if the whole nodes is bipartite or not /////
                        if (color_vect[next_node] == color_vect[curr_node]) { return false; }
                    }

                } //Next-nodes

            } //Queue-size

        } //Cycled-times

        return true;
    }
};
