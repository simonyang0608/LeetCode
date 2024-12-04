class Solution {
public:
    int maxStarSum(vector<int> & vals, vector<vector<int>> & edges, int k) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<int> ref. (vals vector)          // 
        //   - vector<vector<int>> ref. (edges vector) //
        //   - int (k-th edges)                        //
        // Return type:                                //
        //   - int (result maximun summary score)      //
        //=============================================//

        /*Initialize*/
        ///// Length of edges, vals vector /////
        int len_edges = edges.size(), len_vals = vals.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<int>> record_map;

        for (int vals_idx = 0; (vals_idx < len_vals); (vals_idx++))
        {
            record_map[vals_idx] = {};
        }

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record maximun summary /////
        int record_max_sum = 0;

        ///// Result maximun summary /////
        int res_max_sum = *max_element(vals.begin(), vals.end());


        /*Greedy-based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes, weights with dictionary, hashmap /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            (record_map[(edges[edges_idx])[0]]).emplace_back(vals[(edges[edges_idx])[1]]); //Keep updating, recording
            (record_map[(edges[edges_idx])[1]]).emplace_back(vals[(edges[edges_idx])[0]]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int vals_idx = 0; (vals_idx < len_vals); (vals_idx++)) //Whole
        {
            record_max_sum += vals[vals_idx]; //Keep updating, accumulating

            sort((record_map[vals_idx]).begin(), (record_map[vals_idx]).end(), [](const int & val_1, const int & val_2)
            {
                return (val_1 > val_2);
            }); //Sorted operations

            while ((record_trav_ptr < (record_map[vals_idx]).size()) && (record_trav_ptr < k)) //Positive-part
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((record_map[vals_idx])[record_trav_ptr] <= 0) { break; }

                record_max_sum += (record_map[vals_idx])[(record_trav_ptr++)]; //Keep updating, accumulating

            } //Positive-part

            res_max_sum = max(res_max_sum, record_max_sum); //Keep updating, overwriting

            ///// Check if the current maximun summary needs to be reset or not /////
            if (record_max_sum) { record_max_sum &= 0; } //Update, Reset
            else { ; }

            ///// Check if the current traversal pointer needs to be reset or not /////
            if (record_trav_ptr) { record_trav_ptr &= 0; } //Update, Reset
            else { ; }

        } //Whole

        return res_max_sum;
    }
};
