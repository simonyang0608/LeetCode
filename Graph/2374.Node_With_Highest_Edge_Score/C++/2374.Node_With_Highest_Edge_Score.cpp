class Solution {
public:
    int edgeScore(vector<int> & edges) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (edges vector) //
        // Return type:                        //
        //   - int (result minimun index)      //
        //=====================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Record vector /////
        vector<long long> record_vect(len_edges, 0);

        ///// Record maximun score /////
        long long record_max_score = (-1);

        ///// Result minimun index /////
        int res_min_idx = (-1);


        /*Greedy-based loop traversal with recorded vector*/
        ///// Step 1: Record indexed-nodes informations with vector /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            record_vect[edges[edges_idx]] += edges_idx; //Keep updating, accumulating
        }

        ///// Step 2: Looped-traversal with recorded vector /////
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            ///// Check if the current summary value matched conditions or not /////
            if (record_vect[edges_idx] > record_max_score)
            {
                record_max_score = record_vect[edges_idx]; //Keep updating, overwriting

                res_min_idx = edges_idx; //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return res_min_idx;
    }
};
