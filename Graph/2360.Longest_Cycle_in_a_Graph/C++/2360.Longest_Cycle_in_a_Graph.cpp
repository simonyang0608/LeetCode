class Solution {
public:
    int longestCycle(vector<int> & edges) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (edges vector) //
        // Return type:                        //
        //   - int (result maximun length)     //
        //=====================================//

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Length vector /////
        vector<int> length_vect(len_edges, (-1));

        ///// Visit vector /////
        vector<bool> visit_vect(len_edges, false);

        ///// Result maximun length /////
        int res_max_length = (-1);


        /*Recursion-based DFS loop traversal with recorded vectors*/
        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++)) //Whole
        {
            ///// Check if the current node is visited or not /////
            if (visit_vect[edges_idx]) { continue; }
 
            int record_length = 0; //Record length

            dfsTraversal(edges, length_vect, visit_vect, edges_idx, record_length, res_max_length); //Recursion function call

        } //Whole

        return res_max_length;
    }


    void dfsTraversal(const vector<int> & edges, vector<int> & length_vect, vector<bool> & visit_vect,
                      const int & record_node, int & record_length, int & res_max_length)
    {
        //=================================================//
        // Input type:                                     //
        //   - const vector<int> ref. edges (edges vector) //
        //   - vector<int> ref. (length vector)            //
        //   - vector<bool> ref. (visit vector)            //
        //   - const int ref. (record nodes)               //
        //   - int ref. (record length)                    //
        //   - int ref. (result maximun length)            //
        // Return type:                                    //
        //   - void (no return)                            //
        //=================================================//
        if (record_node == (-1)) { return; } //Issue, Boundary-case handling

        /*Whole process, flow*/
        ///// Check if the current node is visited or not /////
        if (! visit_vect[record_node])
        {
            visit_vect[record_node] = true; //Update, Record

            length_vect[record_node] = record_length; //Update, Overwrite

            (record_length++); //Update, Accumulate

            dfsTraversal(edges, length_vect, visit_vect, edges[record_node], record_length, res_max_length); //Recursion function call
        }

        else
        {
            ///// Check if the length counter of current node matched conditions or not /////
            if (length_vect[record_node] != (-1))
            {
                res_max_length = max(res_max_length, (record_length - length_vect[record_node])); //Update, Overwrite
            }
            else { ; }

            return;
        }

        length_vect[record_node] = (-1); //Update, Overwrite

        return;
    }
};
