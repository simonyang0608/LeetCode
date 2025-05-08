class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>> & richer, vector<int> & quiet) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (richer vector) //
        //   - vector<int> ref. (quiet vector)          //
        // Return type:                                 //
        //   - vector<int> (result vector)              //
        //==============================================//

        /*Initialize*/
        ///// Length of vectors (i.e. richer, quiet) /////
        int len_richer = richer.size(), len_quiet = quiet.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Edge-rank vector /////
        vector<int> edge_rank_vect(len_quiet, 0);

        ///// Record queue /////
        queue<pair<int, int>> record_queue;

        ///// Result vector /////
        vector<int> res_vect(quiet.begin(), quiet.end());


        /*Breath-first search based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes informations with dictionary, hashmap /////
        for (int quiet_idx = 0; (quiet_idx < len_quiet); (quiet_idx++)) //Whole
        {
            record_map[quiet[quiet_idx]] = quiet_idx; //Keep updating, recording

        } //Whole

        for (int richer_idx = 0; (richer_idx < len_richer); (richer_idx++)) //Whole
        {
            (root_child_map[(richer[richer_idx])[0]]).emplace_back((richer[richer_idx])[1]); //Keep updating, recording

            ((edge_rank_vect[(richer[richer_idx])[1]])++); //Keep updating, accumulating

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int record_idx = 0; (record_idx < len_quiet); (record_idx++)) //Whole
        {
            ///// Check if the current summary counter matched conditions or not /////
            if (! edge_rank_vect[record_idx])
            {
                record_queue.emplace(record_idx, quiet[record_idx]); //Keep updating, recording
 
                res_vect[record_idx] = record_idx; //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        while (! record_queue.empty()) //Cycled-times
        {
            for(int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int record_node = (record_queue.front()).first; int record_quiet = (record_queue.front()).second; //Record node, quiet

                record_queue.pop(); //Keep updating, popped

                for (int & next_node: root_child_map[record_node]) //Next-nodes
                {
                    ///// Check if the current quietness matched conditions or not /////
                    if (res_vect[next_node] > record_quiet) { res_vect[next_node] = record_quiet; } //Keep updating, overwriting
                    else { ; }

                    ((edge_rank_vect[next_node])--); //Keep updating, reducing

                    ///// Check if the current summary counter matched conditions or not /////
                    if (! edge_rank_vect[next_node])
                    {
                        record_queue.emplace(next_node, res_vect[next_node]); //Keep updating, recording
                        
                        res_vect[next_node] = record_map[res_vect[next_node]]; //Keep updating, overwriting
                    }
                    else { ; }

                } //Next-nodes

            } //Queue-size

        } //Cycled-times

        return res_vect;
    }
};
