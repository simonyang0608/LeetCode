class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int> & manager, vector<int> & informTime) 
    {
        //=======================================//
        // Input type:                           //
        //   - int (n employees)                 //
        //   - int (headID)                      //
        //   - vector<int> ref. (manager vector) //
        //   - vector<int> & (informTime vector) //
        // Return type:                          //
        //   - int (result maximun time)         //
        //=======================================//

        /*Initialize*/
        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<pair<int, int>>> record_map;

        /*Recursion-based DFS loop traversal with recorded dictionary, hashmap*/
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //Whole
        {
            (record_map[manager[n_idx]]).emplace_back(make_pair(n_idx, informTime[n_idx])); //Keep updating, recording

        } //Whole

        return dfsTraversal(record_map, (-1), 0); //Recursion function call
    }


    int dfsTraversal(unordered_map<int, vector<pair<int, int>>> & record_map, int record_manager, int record_time)
    {
        //==================================================================================//
        // Input type:                                                                      //
        //   - unordered_map<int, vector<pair<int, int>>> ref. (record dictionary, hashmap) //
        //   - int (record manager)                                                         //
        //   - int (record time)                                                            //
        // Return type:                                                                     //
        //   - int (result maximun time)                                                    //
        //==================================================================================//
        if (record_map.find(record_manager) == record_map.end()) { return record_time; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Temporal, Result maximun time /////
        int tmp_time, res_max_time = record_time;

        /*Whole process, flow*/
        for (pair<int, int> record_pair: record_map[record_manager]) //Whole
        {
            tmp_time = dfsTraversal(record_map, record_pair.first, (record_time + record_pair.second)); //Recursion function call

            res_max_time = (tmp_time > res_max_time) ? tmp_time : res_max_time; //Keep updating, overwriting

        } //Whole

        return res_max_time;
    }
};
