class Solution {
public:
    int minimumTime(int n, vector<vector<int>> & relations, vector<int> & time) 
    {
        //=================================================//
        // Input type:                                     //
        //   - int (n-th nodes)                            //
        //   - vector<vector<int>> ref. (relations vector) //
        //   - vector<int> ref. (time vector)              //
        // Return type:                                    //
        //   - int (result minimun months)                 //
        //=================================================//

        /*Initialize*/
        ///// Length of relations vector /////
        int len_relations = relations.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Edge-rank, summary counter vectors /////
        vector<int> edge_rank_vect(n, 0), edge_cnter_vect(n, 0);

        ///// Record queue /////
        queue<pair<int, int>> record_queue;


        /*Breath-first search based loop traversal*/
        ///// Step 1: Record nodes informations with dictionary, hashmap, vectors /////
        for (int relations_idx = 0; (relations_idx < len_relations); (relations_idx++)) //Whole
        {
            (root_child_map[((relations[relations_idx])[0] - 1)]).emplace_back(((relations[relations_idx])[1] - 1)); //Keep updating, recording
 
            ((edge_cnter_vect[((relations[relations_idx])[1] - 1)])++); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap, vectors /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th nodes
        {
            ///// Check if the current nodes edges is 0 or not /////
            if (! edge_cnter_vect[n_idx])
            {
                edge_rank_vect[n_idx] = time[n_idx]; //Keep updating, overwriting

                record_queue.emplace(n_idx, edge_rank_vect[n_idx]); //Keep updating, recording
            }
            else { ; }

        } //N-th nodes

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int record_node = (record_queue.front()).first; int record_rank = (record_queue.front()).second; //Record node, rank

                record_queue.pop(); //Keep updating, popped

                for (const int & next_node: root_child_map[record_node]) //Next-nodes
                {
                    ///// Check if the current nodes edge-rank is larger or not /////
                    if (record_rank > edge_rank_vect[next_node]) { edge_rank_vect[next_node] = record_rank; } //Keep updating, overwriting
                    else { ; }

                    ///// Check if the current nodes edges is end of visited or not /////
                    if (! (--(edge_cnter_vect[next_node])))
                    {
                        edge_rank_vect[next_node] += time[next_node]; //Keep updating, overwriting

                        record_queue.emplace(next_node, edge_rank_vect[next_node]); //Keep updating, recording
                    }
                    else { ; }

                } //Next-nodes

            } //Queue-size

        } //Cycled-times

        return *max_element(edge_rank_vect.begin(), edge_rank_vect.end());
    }
};
