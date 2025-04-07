class Solution {
public:
    int countGoodNodes(vector<vector<int>> & edges) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (edges vector) //
        // Return type:                                //
        //   - int (result summary counter)            //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Visit dictionary, hashmap /////
        unordered_map<int, bool> visit_map;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        visit_map[0] = true; //Update, Record

        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (root_child_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1]); //Keep updating, recording
            (root_child_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0]); //Keep updating, recording

        } //Whole

        int res_sum_val = dfsTraversal(root_child_map, 0, visit_map, res_cnter); //Recursion function call

        return res_cnter;
    }


    int dfsTraversal(unordered_map<int, vector<int>> & root_child_map, int record_node, 
                     unordered_map<int, bool> & visit_map, int & res_cnter)
    {
        //===========================================================================//
        // Input type:                                                               //
        //   - unordered_map<int, vector<int>> ref. (root-child dictionary, hashmap) //
        //   - int (record node)                                                     //
        //   - unordered_map<int, bool> ref. (visit dictionary, hashmap)             //
        //   - int ref. (result summary counter)                                     //
        // Return type:                                                              //
        //   - int (total summary counter)                                           //
        //===========================================================================//

        /*Initialize*/
        ///// Record flag /////
        bool record_flag = true;

        ///// Record summary counter /////
        int record_cnter = (-1);

        ///// Total summary counter /////
        int total_cnter = 1;


        /*Whole process, flow*/
        for (int & next_node: root_child_map[record_node]) //Whole
        {
            ///// Check if the next node existed or not /////
            if (! visit_map[next_node])
            {
                visit_map[next_node] = true; //Keep updating, recording

                int sub_cnter = dfsTraversal(root_child_map, next_node, visit_map, res_cnter); //Sub-summary counter

                ///// Check if the current summary counter matched conditions or not /////
                if (record_cnter == (-1)) { record_cnter = sub_cnter; } //Keep updating, overwriting
                else
                {
                    ///// Check if the current summary counter matched conditions or not /////
                    if (sub_cnter != record_cnter)
                    {
                        ///// Check if the current flag matched conditions or not /////
                        if (record_flag) { record_flag &= false; } //Keep updating, overwriting
                    }
                }

                total_cnter += sub_cnter; //Keep updating, accumulating
            }
             
        } //Whole

        ///// Check if the current flag matched conditions or not /////
        if (record_flag) { (res_cnter++); } //Keep updating, accumulating

        return total_cnter;
    }
};
