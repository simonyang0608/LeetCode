class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>> & dislikes) 
    {
        //================================================//
        // Input type:                                    //
        //   - int (n-th nodes)                           //
        //   - vector<vector<int>> ref. (dislikes vector) //
        // Return type:                                   //
        //   - bool (result flag)                         //
        //================================================//

        /*Initialize*/
        ///// Length of dislikes vector /////
        int len_dislikes = dislikes.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Record vector /////
        vector<int> record_vect(n, (-1));

        ///// Result minimun summary counter /////
        int res_min_cnter = INT_MAX;


        /*Breath-first search based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes informations with dictionary, hashmap /////
        for (int dislikes_idx = 0; (dislikes_idx < len_dislikes); (dislikes_idx++)) //Whole
        {
            (root_child_map[((dislikes[dislikes_idx])[0] - 1)]).emplace_back(((dislikes[dislikes_idx])[1] - 1)); //Keep updating, recording
            (root_child_map[((dislikes[dislikes_idx])[1] - 1)]).emplace_back(((dislikes[dislikes_idx])[0] - 1)); //Keep updating, recording
        }

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th nodes
        {
            ///// Check if the current node is visited or not /////
            if (record_vect[n_idx] != (-1)) { continue; }

            record_vect[n_idx] = 0; //Keep updating, overwriting

            bool record_flag = bfsTraversal(root_child_map, record_vect, n_idx); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (! record_flag) { return false; }

        } //N-th nodes

        return true;
    }


    bool bfsTraversal(unordered_map<int, vector<int>> & root_child_map, vector<int> & record_vect, 
                      int & record_node)
    {
        //===========================================================================//
        // Input type:                                                               //
        //   - unordered_map<int, vector<int>> ref. (root-child dictionary, hashmap) //
        //   - vector<int> ref. (record vector)                                      //
        //   - int ref. (record node)                                                //
        // Return type:                                                              //
        //   - bool (result flag)                                                    //
        //===========================================================================//

        /*Whole process, flow*/
        queue<int> record_queue; record_queue.emplace(record_node); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            int curr_node = record_queue.front(); record_queue.pop(); //Current node

            for (int & next_node: root_child_map[curr_node]) //Next-nodes
            {
                ///// Check if the next node is visited or not /////
                if (record_vect[next_node] == (-1))
                {
                    record_vect[next_node] = (1 - record_vect[curr_node]); //Keep updating, overwriting

                    record_queue.emplace(next_node); //Keep updating, recording
                }

                else if (record_vect[next_node] == record_vect[curr_node]) { return false; }

            } //Next-nodes

        } //Cycled-times

        return true;
    }
};
