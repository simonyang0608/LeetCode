class Solution {
public:
    int numberOfComponents(vector<vector<int>> & properties, int k) 
    {
        //==================================================//
        // Input type:                                      //
        //   - vector<vector<int>> ref. (properties vector) //
        //   - int (k-th threshold)                         //
        // Return type:                                     //
        //   - int (result summary counter)                 //
        //==================================================//

        /*Initialize*/
        ///// Length of properties vector /////
        int len_properties = properties.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<int, int> root_child_map;

        ///// Edge-rank vector /////
        vector<int> edge_rank_vect(len_properties, 1);

        ///// Result set /////
        unordered_set<int> res_set;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Disjoint-set based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes informations with dictionary, hashmap /////
        for (int record_idx = 0; (record_idx < len_properties); (record_idx++)) //Whole
        {
            root_child_map[record_idx] = record_idx; //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int record_idx = 0; (record_idx < (len_properties - 1)); (record_idx++)) //Major
        {
            for (int sub_idx = (record_idx + 1); (sub_idx < len_properties); (sub_idx++)) //Minor
            {
                int distj_node1 = distJSet(root_child_map, record_idx); //Record dist-joint node-1
                int distj_node2 = distJSet(root_child_map, sub_idx); //Record dist-joint node-2

                ///// Check if the current dist-joint node matched conditions or not /////
                if (distj_node1 == distj_node2) { continue; }

                unordered_set<int> record_set1((properties[record_idx]).begin(), (properties[record_idx]).end()); //Record set-1
                unordered_set<int> record_set2; //Record set-2

                int record_cnter = 0; //Record summary counter

                for (const int & record_val: properties[sub_idx]) //Whole
                {
                    ///// Check if the current indexed-node is visited or not /////
                    if (record_set2.count(record_val)) { continue; }

                    ///// Check if the current indexed-node is intersected or not /////
                    if (record_set1.count(record_val)) { (record_cnter++); } //Keep updating, accumulating
                    else { ; }

                    record_set2.insert(record_val); //Keep updating, recording

                } //Whole           

                ///// Check if the current summary counter matched conditions or not /////
                if (record_cnter >= k)
                {
                    ///// Check which is the dist-joint node belongs to /////
                    if (edge_rank_vect[distj_node1] >= edge_rank_vect[distj_node2])
                    {
                        root_child_map[distj_node2] = distj_node1; edge_rank_vect[distj_node1] += edge_rank_vect[distj_node2]; //Keep updating, recording
                    }
                    else
                    {
                        root_child_map[distj_node1] = distj_node2; edge_rank_vect[distj_node2] += edge_rank_vect[distj_node1]; //Keep updating, recording
                    }
                }
                else { ; }

            } //Minor

        } //Major

        for (int record_idx = 0; (record_idx < len_properties); (record_idx++)) //Whole
        {
            int distj_node3 = distJSet(root_child_map, record_idx); //Record dist-joint node-3

            ///// Check if the current indexed-node is visited or not /////
            if (res_set.count(distj_node3)) { continue; }

            res_set.insert(distj_node3); (res_cnter++); //Keep updating, accumulating

        } //Whole

        return res_cnter;
    }


    int distJSet(unordered_map<int, int> & root_child_map, const int & record_node)
    {
        //===================================================================//
        // Input type:                                                       //
        //   - unordered_map<int, int> ref. (root-child dictionary, hashmap) //
        //   - const int ref. (record node)                                  //
        // Return type:                                                      //
        //   - int (result node)                                             //
        //===================================================================//

        /*Whole process, flow*/
        ///// Check if the current node matched conditions or not /////
        if (root_child_map[record_node] != record_node)
        {
            root_child_map[record_node] = distJSet(root_child_map, root_child_map[record_node]); //Recursion function call
        }

        return root_child_map[record_node];
    }
};
