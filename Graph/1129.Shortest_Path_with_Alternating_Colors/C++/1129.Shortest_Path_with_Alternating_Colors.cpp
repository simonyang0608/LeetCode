class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>> & redEdges, vector<vector<int>> & blueEdges) 
    {
        //=================================================//
        // Input type:                                     //
        //   - int (n-th nodes)                            // 
        //   - vector<vector<int>> ref. (redEdges vector)  //
        //   - vector<vector<int>> ref. (blueEdges vector) //
        // Return type:                                    //
        //   - vector<int> (result vector)                 //
        //=================================================//

        /*Initialize*/
        ///// Length of vectors (i.e. red, blue-edges) /////
        int len_redEdges = redEdges.size(), len_blueEdges = blueEdges.size();

        ///// Root-child vector /////
        vector<vector<pair<int, char>>> root_child_vect(n);

        ///// Visit vector /////
        vector<vector<bool>> visit_vect(n, vector<bool>(2));

        ///// Record queue /////
        queue<pair<int, char>> record_queue;

        //// Record steps /////
        int record_steps = 0;

        ///// Result vector /////
        vector<int> res_vect(n, (-1));


        /*Breath-first search based loop traversal with recorded vectors*/
        ///// Step 1: Record indexed-nodes informations with vectors /////
        for (int redEdges_idx = 0; (redEdges_idx < len_redEdges); (redEdges_idx++)) //Whole
        {
            root_child_vect[(redEdges[redEdges_idx])[0]].emplace_back((redEdges[redEdges_idx])[1], 'r'); //Keep updating, recording

        } //Whole

        for (int blueEdges_idx = 0; (blueEdges_idx < len_blueEdges); (blueEdges_idx++)) //Whole
        {
            root_child_vect[(blueEdges[blueEdges_idx])[0]].emplace_back((blueEdges[blueEdges_idx])[1], 'b'); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded vectors /////
        record_queue.emplace(0, 'n'); //Update, Record

        res_vect[0] = record_steps; //Update, Overwrite

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int curr_node = (record_queue.front()).first; int curr_chr = (record_queue.front()).second; //Current node, char

                record_queue.pop(); //Keep updating, popped

                for (const pair<int, char> & next_pair: root_child_vect[curr_node]) //Next-nodes
                {
                    int next_node = next_pair.first; char next_chr = next_pair.second; //Next node, char

                    ///// Check if the current char matched conditions or not /////
                    if (curr_chr == next_chr) { continue; }

                    int next_idx = (next_chr == 'r') ? 0 : 1; //Next color index

                    ///// Check if the next color index is visited or not /////
                    if ((visit_vect[next_node])[next_idx]) { continue; }

                    (visit_vect[next_node])[next_idx] = true; //Keep updating, overwriting

                    ///// Check if the next node steps matched conditions or not /////
                    if (res_vect[next_node] == (-1)) { res_vect[next_node] = (record_steps + 1); } //Keep updating, recording
                    else { ; }

                    record_queue.emplace(next_node, next_chr); //Keep updating, recording

                } //Next-nodes

            } //Queue-size

            (record_steps++); //Keep updating, traversing

        } //Cycled-times

        return res_vect;
    }
};
