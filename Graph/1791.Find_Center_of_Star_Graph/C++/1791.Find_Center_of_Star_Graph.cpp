class Solution {
public:
    int findCenter(vector<vector<int>> & edges) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (edges vector) //
        // Return type:                                //
        //   - int (result maximun node)               //
        //=============================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record main, sub-node /////
        int record_main_node, record_sub_node;

        ///// Result maximun edges /////
        int res_max_edges = (-1);

        ///// Result maximun node /////
        int res_max_node;


        /*One-pass record based loop traversal with recorded dictionary, hashmap*/
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            record_main_node = (edges[edges_idx])[0]; //Record main node
            record_sub_node = (edges[edges_idx])[1]; //Record sub node

            ///// Check if the current node existed or not /////
            if (record_map.find(record_main_node) == record_map.end()) { record_map[record_main_node] = 1; } //Keep updating, recording
            else { record_map[record_main_node] += 1; } //Keep updating, recording

            ///// Check if the current edges is larger or not /////
            if (record_map[record_main_node] > res_max_edges)
            {
                res_max_edges = record_map[record_main_node]; //Keep updating, overwriting
                res_max_node = record_main_node; //Keep updating, overwriting
            }
            else { ; }

            ///// Check if the current node existed or not /////
            if (record_map.find(record_sub_node) == record_map.end()) { record_map[record_sub_node] = 1; } //Keep updating, recording
            else { record_map[record_sub_node] += 1; } //Keep updating, recording

            ///// Check if the current edges is larger or not /////
            if (record_map[record_sub_node] > res_max_edges)
            {
                res_max_edges = record_map[record_sub_node]; //Keep updating, overwriting
                res_max_node = record_sub_node; //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return res_max_node;
    }
};
