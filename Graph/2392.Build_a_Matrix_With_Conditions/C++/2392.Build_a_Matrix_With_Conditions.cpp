class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>> & rowConditions, vector<vector<int>> & colConditions) 
    {
        //=====================================================//
        // Input type:                                         //
        //   - int (k-th nodes)                                //
        //   - vector<vector<int>> ref. (rowConditions vector) //
        //   - vector<vector<int>> ref. (colConditions vector) //
        // Return type:                                        //
        //   - vector<vector<int>> (result vector)             //
        //=====================================================//

        /*Initialize*/
        ///// Length of vectors (i.e. rowConditions, colConditions) /////
        int len_rowConditions = rowConditions.size(), len_colConditions = colConditions.size();

        ///// Record dictionary, hashmaps (i.e. rows, columns) /////
        unordered_map<int, vector<int>> record_map_rows, record_map_cols;

        ///// Positions dictionary, hashmap /////
        unordered_map<int, pair<int, int>> pos_map;

        ///// Record queue /////
        queue<int> record_queue;

        ///// Edge-rank vector /////
        vector<int> edge_rank_vect(k, 0);

        ///// Result vector /////
        vector<vector<int>> res_vect(k, vector<int>(k, 0));


        /*Breath-first search based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Looped-traversal for the indexed-nodes informations within rows positions /////
        for (int rowConditions_idx = 0; (rowConditions_idx < len_rowConditions); (rowConditions_idx++)) //Whole
        {
            int next_node = ((rowConditions[rowConditions_idx])[0] - 1); //Next node

            (record_map_rows[((rowConditions[rowConditions_idx])[1] - 1)]).emplace_back(next_node); //Keep updating, recording

            ((edge_rank_vect[next_node])++); //Keep updating, accumulating
        }

        bool record_flag_rows = bfsTraversal(record_map_rows, k, edge_rank_vect, pos_map, record_queue, 'r'); //Record flag (i.e. rows)

        if (! record_flag_rows) { return {}; } //Issue, Boundary-case handling

        ///// Step 2: Looped-traversal for the indexed-nodes informations within columns positions /////
        for (int colConditions_idx = 0; (colConditions_idx < len_colConditions); (colConditions_idx++)) //Whole
        {
            int next_node = ((colConditions[colConditions_idx])[0] - 1); //Next node

            (record_map_cols[((colConditions[colConditions_idx])[1] - 1)]).emplace_back(next_node); //Keep updating, recording

            ((edge_rank_vect[next_node])++); //Keep updating, accumulating

        } //Whole

        bool record_flag_cols = bfsTraversal(record_map_cols, k, edge_rank_vect, pos_map, record_queue, 'c'); //Record flag (i.e. columns)

        if (! record_flag_cols) { return {}; } //Issue, Boundary-case handling

        for (auto record_ele = pos_map.cbegin(); (record_ele != pos_map.cend()); (record_ele++)) //Whole
        {
            (res_vect[(record_ele->second).first])[(record_ele->second).second] = ((record_ele->first) + 1); //Keep updating, overwriting

        } //Whole

        return res_vect;
    }


    bool bfsTraversal(unordered_map<int, vector<int>> & record_map_pos, const int & k, vector<int> & edge_rank_vect, 
                      unordered_map<int, pair<int, int>> & pos_map, queue<int> & record_queue, char record_chr)
    {
        //========================================================================================//
        // Input type:                                                                            //
        //   - unordered_map<int, vector<int>> ref. (record dictionary, hashmap (i.e. positions)) //
        //   - const int ref. (k-th nodes)                                                        //
        //   - vector<int> ref. (edge-rank vector)                                                //
        //   - unordered_map<int, pair<int, int>> ref. (positions dictionary, hashmap)            //
        //   - queue<int> ref. (record queue)                                                     //
        //   - char (record char)                                                                 //
        // Return type:                                                                           //
        //   - bool (result flag)                                                                 //
        //========================================================================================//

        /*Initialize*/
        ///// Record positions index /////
        int record_pos_idx = (k - 1);

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Whole process, flow*/
        ///// Step 1: Record indexed-nodes informations with vector /////
        for (int record_idx = 0; (record_idx < k); (record_idx++)) //Whole
        {
            ///// Check if the current summary counter matched conditions or not /////
            if (! edge_rank_vect[record_idx])
            {
                (res_cnter++); //Keep updating, accumulating

                ///// Check if the current char matched conditions or not /////
                if (record_chr == 'r') { (pos_map[record_idx]).first = (record_pos_idx--); } //Keep updating, recording
                else { (pos_map[record_idx]).second = (record_pos_idx--); } //Keep updating, recording

                record_queue.emplace(record_idx); //Keep updating, recording
            }
            else { ; }

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int record_node = record_queue.front(); record_queue.pop(); //Keep updating, popped

                for (int & next_node: record_map_pos[record_node]) //Next-nodes
                {
                    ///// Check if the current summary counter matched conditions or not /////
                    if (! (--(edge_rank_vect[next_node])))
                    {
                        (res_cnter++); //Keep updating, accumulating

                        ///// Check if the current char matched conditions or not /////
                        if (record_chr == 'r') { (pos_map[next_node]).first = (record_pos_idx--); } //Keep updating, recording
                        else { (pos_map[next_node]).second = (record_pos_idx--); } //Keep updating, recording

                        record_queue.emplace(next_node); //Keep updating, recording
                    }
                    else { ; }

                } //Next-nodes

            } //Queue-size

        } //Cycled-times

        return (res_cnter == k) ? true : false;
    }
};
