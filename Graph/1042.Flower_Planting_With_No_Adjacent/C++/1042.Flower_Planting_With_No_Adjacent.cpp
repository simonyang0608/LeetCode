class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>> & paths) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (paths vector) //
        // Return type:                                //
        //   - vector<int> (result vector)             //
        //=============================================//

        /*Initialize*/
        ///// Length of paths vector /////
        int len_paths = paths.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<int>> root_child_map;

        ///// Result vector /////
        vector<int> res_vect(n, 0);


        /*Greedy-based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes information with dictionary, hashmap /////
        for (int paths_idx = 0; (paths_idx < len_paths); (paths_idx++)) //Whole
        {
            (root_child_map[((paths[paths_idx])[0] - 1)]).emplace_back(((paths[paths_idx])[1] - 1)); //Keep updating, recording
            (root_child_map[((paths[paths_idx])[1] - 1)]).emplace_back(((paths[paths_idx])[0] - 1)); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th nodes
        {
            vector<bool> color_vect(5, false); //Color vector

            for (const int & next_node: root_child_map[n_idx]) { color_vect[res_vect[next_node]] = true; } //Keep updating, overwriting

            for (int color_idx = 4; (color_idx > 0); (color_idx--)) //Colors
            {
                ///// Check if the current indexed-color matched conditions or not /////
                if (! color_vect[color_idx]) { res_vect[n_idx] = color_idx; } //Keep updating, overwriting
                else { ; }

            } //Colors

        } //N-th nodes

        return res_vect;
    }
};
