class Solution {
public:
    long long dfsTraversal(unordered_map<int, vector<int>> & record_map, int & seats, int node_val, int prev_node_val, long long & res_min_cnter)
    {
        //=======================================================================//
        // Input type:                                                           //
        //   - unordered_map<int, vector<int>> ref. (record dictionary, hashmap) //
        //   - int ref. (total seats)                                            //
        //   - int (current node value)                                          //
        //   - int (previous node value)                                         //
        //   - long long ref. (result minimun summary counter)                   //
        // Return type:                                                          //
        //   - long long (result minimun summary counter)                        //
        //=======================================================================//

        /*Initialize*/
        ///// Result people, representations /////
        long long res_people = 1;

        /*Whole process, flow*/
        for (int sub_val: record_map[node_val]) //Whole
        {
            ///// Check if the current indexed-value is previous or not /////
            if (sub_val == prev_node_val) { continue; }
            else
            {
                res_people += dfsTraversal(record_map, seats, sub_val, node_val, res_min_cnter); //Recursion function call
            }

        } //Whole

        ///// Check if the current node-value is capital type or not /////
        if (node_val)
        {
            ///// Check if the current divisions matched conditions or not /////
            if ((res_people % seats)) { res_min_cnter += ((res_people / seats) + 1); } //Update, Accumulate
            else { res_min_cnter += (res_people / seats); } //Update, Accumulate
        }

        else { ; }

        return res_people;
    }


    long long minimumFuelCost(vector<vector<int>> & roads, int seats) 
    {
        //================================================//
        // Input type:                                    //
        //   - vector<vector<int>> ref. (roads vector)    //
        //   - int (total seats)                          //
        // Return type:                                   //
        //   - long long (result minimun summary counter) //
        //================================================//
        if (! (roads.size())) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of roads vector /////
        int len_roads = roads.size();

        ///// Record main, sub-node values /////
        int record_main_node_val, record_sub_node_val;

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<int>> record_map;

        ///// Result minimun summary counter /////
        long long res_min_cnter = 0;


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-value with dictionary, hashmap /////
        for (int roads_idx = 0; (roads_idx < len_roads); (roads_idx++)) //Whole
        {
            record_main_node_val = (roads[roads_idx])[0]; //Record main-node value
            record_sub_node_val = (roads[roads_idx])[1]; //Record sub-node value

            (record_map[record_main_node_val]).push_back(record_sub_node_val); //Keep updating, recording
            (record_map[record_sub_node_val]).push_back(record_main_node_val); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded hashmap /////
        int res_people = dfsTraversal(record_map, seats, 0, (-1), res_min_cnter); //Resursion function call

        return res_min_cnter;
    }
};
