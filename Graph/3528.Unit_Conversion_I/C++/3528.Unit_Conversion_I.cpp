class Solution {
public:
    vector<int> baseUnitConversions(vector<vector<int>> & conversions) 
    {
        //===================================================//
        // Input type:                                       //
        //   - vector<vector<int>> ref. (conversions vector) //
        // Return type:                                      //
        //   - vector<int> (result vector)                   //
        //===================================================//

        /*Initialize*/
        ///// Length of conversions vector /////
        int len_conversions = conversions.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, vector<pair<int, int>>> root_child_map;

        ///// Record node, module /////
        int record_node = 0, record_module = (1e9 + 7);

        ///// Result vector /////
        vector<int> res_vect((len_conversions + 1), 1);


        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes informations with dictionary, hashmap /////
        for (int conversions_idx = 0; (conversions_idx < len_conversions); (conversions_idx++)) //Whole
        {
            (root_child_map[(conversions[conversions_idx])[0]]).emplace_back((conversions[conversions_idx])[1], 
                                                                             (conversions[conversions_idx])[2]); //Keep updating, recording
                                                                              
        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        dfsTraversal(root_child_map, record_node, record_module, 1, res_vect); //Recursion function call

        return res_vect;
    }


    void dfsTraversal(unordered_map<int, vector<pair<int, int>>> & root_child_map, int & record_node, 
                      const int & record_module, long long record_prod, vector<int> & res_vect)
    {
        //======================================================================================//
        // Input type:                                                                          //
        //   - unordered_map<int, vector<pair<int, int>>> ref. (root-child dictionary, hashmap) //
        //   - int ref. (record node)                                                           //
        //   - const int ref. (record module)                                                   //
        //   - long long (record product value)                                                 //
        //   - vector<int> ref. (result vector)                                                 //
        // Return type:                                                                         //
        //   - void (no return)                                                                 //
        //======================================================================================//

        /*Whole process, flow*/
        for (pair<int, int> & next_pair: root_child_map[record_node]) //Next-nodes
        {
            int next_node = next_pair.first; long long next_prod = ((record_prod % record_module) * next_pair.second); //Next node, product value

            next_prod %= record_module; //Keep updating, overwriting

            res_vect[next_node] = next_prod; //Keep updating, overwriting

            dfsTraversal(root_child_map, next_node, record_module, next_prod, res_vect); //Recursion function call

        } //Next-nodes

        return;
    }
};
