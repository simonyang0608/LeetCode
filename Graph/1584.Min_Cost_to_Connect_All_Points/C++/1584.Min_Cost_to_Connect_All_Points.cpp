class Solution {
public:
    int minCostConnectPoints(vector<vector<int>> & points) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (points vector) //
        // Return type:                                 //
        //   - int (result minimun summary value)       //
        //==============================================//

        /*Initialize*/
        ///// Length of points vector /////
        int len_points = points.size();

        ///// Record vector /////
        vector<vector<int>> record_vect;

        ///// Root child dictionary, hashmap /////
        map<int, int> root_child_map;

        ///// Rank vector /////
        vector<int> rank_vect(len_points, 1);

        ///// Record distance difference /////
        int record_dist_diff;

        ///// Record main-roots (1, 2) /////
        int record_mroot_1, record_mroot_2;

        ///// Record edge sumamry value /////
        int record_edge_sum = 0;

        ///// Result minimun summary value /////
        int res_min_sum = 0;


        /*Kruskal's-based loop traversal*/
        ///// Step 1: Record indexed-value with vector, dictionary, hashmap /////
        for (int points_idx = 0; (points_idx < len_points); (points_idx++)) //Points
        {
            for (int next_idx = (points_idx + 1); (next_idx < len_points); (next_idx++)) //Next
            {
                record_dist_diff = (abs(((points[points_idx])[0] - (points[next_idx])[0])) + abs(((points[points_idx])[1] - (points[next_idx])[1]))); //Keep updating, overwriting

                record_vect.push_back({record_dist_diff, points_idx, next_idx}); //Keep updating, recording

            } //Next

            root_child_map[points_idx] = points_idx; //Keep updating, recording

        } //Points
 
        ///// Step 2: Looped-traversal with recorded vector, dictionary, hashmap /////
        sort(record_vect.begin(), record_vect.end()); //Sorted operationd

        for (int record_idx = 0; (record_idx < record_vect.size()); (record_idx++)) //Whole
        {
            record_mroot_1 = findRoot(root_child_map, (record_vect[record_idx])[1]); //Keep updating, overwriting
            record_mroot_2 = findRoot(root_child_map, (record_vect[record_idx])[2]); //Keep updating, overwriting

            ///// Check if the current root matched conditions or not /////
            if (Union(record_mroot_1, record_mroot_2, rank_vect, root_child_map))
            {
                res_min_sum += ((record_vect[record_idx])[0]); //Keep updating, accumulating

                (record_edge_sum++); //Keep updating, accumulating

                ///// Check if the current edges excced boundary or not /////
                if (record_edge_sum >= (len_points - 1)) { break; }
            }

        } //Whole

        return res_min_sum;
    }


    int findRoot(map<int, int> & root_child_map, int & record_root)
    {
        //=========================================================//
        // Input type:                                             //
        //   - map<int, int> ref. (root-child dictionary, hashmap) //
        //   - int ref. (record root value)                        // 
        // Return type:                                            //
        //   - int (result root value)                             //
        //=========================================================//

        /*Whole process, flow*/
        ///// Check if the current root matched conditions or not /////
        if (root_child_map[record_root] != record_root) { root_child_map[record_root] = findRoot(root_child_map, root_child_map[record_root]); } //Recursion function call

        return root_child_map[record_root];
    }


    bool Union(int & record_mroot_1, int & record_mroot_2, vector<int> & rank_vect, map<int, int> & root_child_map)
    {
        //=========================================================//
        // Input type:                                             //
        //   - int ref. (record main-root 1)                       //
        //   - int ref. (record main-root 2)                       //
        //   - vector<int> ref. (rank vector)                      //
        //   - map<int, int> ref. (root-child dictionary, hashmap) // 
        // Return type:                                            //
        //   - bool (result flag)                                  //
        //=========================================================//
        if (record_mroot_1 == record_mroot_2) { return false; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        ///// Which is the main root /////
        if (rank_vect[record_mroot_2] > rank_vect[record_mroot_1])
        {
            root_child_map[record_mroot_1] = record_mroot_2; //Update, Overwrite

            ((rank_vect[record_mroot_2])++); //Update, Accumulate
        }
        else
        {
            root_child_map[record_mroot_2] = record_mroot_1; //Update, Overwrite

            ((rank_vect[record_mroot_1])++); //Update, Accumulate
        }

        return true;
    }
};
