class Solution {
public:
    int minimumHammingDistance(vector<int> & source, vector<int> & target, vector<vector<int>> & allowedSwaps) 
    {
        //====================================================//
        // Input type:                                        //
        //   - vector<int> ref. (source vector)               //
        //   - vector<int> ref. (target vector)               //
        //   - vector<vector<int>> ref. (allowedSwaps vector) //
        // Return type:                                       //
        //   - int (result minimun summary counter)           //
        //====================================================//

        /*Initialize*/
        ///// Length of source vector /////
        int len_source = source.size();

        ///// Length of allowedSwaps vector /////
        int len_allowedSwaps = allowedSwaps.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Visit dictionary, hashmap /////
        map<int, bool> visit_map;

        ///// Result minimun summary counter /////
        int res_min_cnter = 0;


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record nodes informations with dictionary, hashmap /////
        for (int allowedSwaps_idx = 0; (allowedSwaps_idx < len_allowedSwaps); (allowedSwaps_idx++)) //Whole
        {
            (root_child_map[(allowedSwaps[allowedSwaps_idx])[0]]).emplace_back((allowedSwaps[allowedSwaps_idx])[1]); //Keep updating, recording
            (root_child_map[(allowedSwaps[allowedSwaps_idx])[1]]).emplace_back((allowedSwaps[allowedSwaps_idx])[0]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int source_idx = 0; (source_idx < len_source); (source_idx++)) //Whole
        {
            ///// Check if the current node is visited or not /////
            if (visit_map[source_idx]) { continue; }

            vector<int> record_vect; //Record vector

            unordered_map<int, int> record_map; //Record dictionary, hashmap

            dfsTraversal(root_child_map, record_vect, source_idx, visit_map); //Recursion function call

            for (const int & record_idx: record_vect) //Whole
            {
                ((record_map[source[record_idx]])++); //Keep updating, recording

            } //Whole

            for (const int & record_idx: record_vect) //Whole
            {
                ///// Check if the current summary counter is less than 0 or not /////
                if ((--(record_map[target[record_idx]])) < 0) { (res_min_cnter++); } //Keep updating, recording
                else { ; }

            } //Whole

        } //Whole

        return res_min_cnter;
    }


    void dfsTraversal(unordered_map<int, vector<int>> & root_child_map, vector<int> & record_vect, 
                      int & record_node, map<int, bool> & visit_map)
    {
        //===========================================================================//
        // Input type:                                                               //
        //   - unordered_map<int, vector<int>> ref. (root-child dictionary, hashmap) //
        //   - vector<int> ref. (record vector)                                      //
        //   - int ref. (record node)                                                //
        //   - map<int, bool> ref. (visit dictionary, hashmap)                       //
        // Return type:                                                              //
        //   - void (no return)                                                      //
        //===========================================================================//
        if (visit_map[record_node]) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        visit_map[record_node] = true; //Update, Record

        record_vect.emplace_back(record_node); //Update, Record

        for (int & next_node: root_child_map[record_node]) //Whole
        {
            dfsTraversal(root_child_map, record_vect, next_node, visit_map); //Recursion function call

        } //Whole
    }
};
