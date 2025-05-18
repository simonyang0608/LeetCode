class Solution {
public:
    int closestMeetingNode(vector<int> & edges, int node1, int node2) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (edges vector) //
        //   - int (node1 value)               //
        //   - int (node2 value)               //
        // Return type:                        //
        //   - int (result minimun distance)   //
        //=====================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Dist vectors (i.e. 1, 2) /////
        vector<int> dist_vect1(len_edges, 1e9), dist_vect2(len_edges, 1e9);

        ///// Record queue /////
        queue<int> record_queue;

        ///// Record minimun distance /////
        int record_min_dist = 1e9;

        ///// Result node index /////
        int res_node_idx = (-1);


        /*Breath-first search based loop traversal with recorded vectors*/
        ///// Step 1: Record indexed-nodes informations with vectors /////
        bfsTraversal(len_edges, edges, record_queue, node1, dist_vect1); //BFS function call
        bfsTraversal(len_edges, edges, record_queue, node2, dist_vect2); //BFS function call

        ///// Step 2: Looped-traversal with recorded vectors /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            int curr_max_dist = (dist_vect1[edges_idx] > dist_vect2[edges_idx]) ? 
                                 dist_vect1[edges_idx] : dist_vect2[edges_idx]; //Current maximun distance

            ///// Check if the current distance matched conditions or not /////
            if (curr_max_dist < record_min_dist)
            {
                record_min_dist = curr_max_dist; //Keep updating, overwriting

                res_node_idx = edges_idx; //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return res_node_idx;
    }


    void bfsTraversal(const int & len_edges, const vector<int> & edges, queue<int> & record_queue, 
                      const int & record_node, vector<int> & dist_vect)
    {
        //=============================================//
        // Input type:                                 //
        //   - const int ref. (length of edges vector) //
        //   - const vector<int> ref. (edges vector)   //
        //   - queue<int> ref. (record queue)          //
        //   - const int ref. (record node)            //
        //   - vector<int> ref. (distance vector)      //
        // Return type:                                //
        //   - void (no return)                        //
        //=============================================//

        /*Initialize*/
        ///// Visit vector /////
        vector<bool> visit_vect(len_edges, false);

        /*Whole process, flow*/
        record_queue.emplace(record_node); //Update, Record

        visit_vect[record_node] = true; //Update, Overwrite

        dist_vect[record_node] = 0; //Update, Overwrite
        
        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = (record_queue.size()); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int curr_node = record_queue.front(); record_queue.pop(); //Keep updating, popped

                ///// Check if the next node existed or not /////
                if (edges[curr_node] == (-1)) { continue; }

                ///// Check if the next node is visited or not /////
                if (visit_vect[edges[curr_node]]) { continue; }

                visit_vect[edges[curr_node]] = true; //Keep updating, overwriting

                dist_vect[edges[curr_node]] = (dist_vect[curr_node] + 1); //Keep updating, overwriting

                record_queue.emplace(edges[curr_node]); //Keep updating, recording

            } //Queue-size

        } //Cycled-times
    }
};
