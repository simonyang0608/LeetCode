class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>> & roads) 
    {
        //===================================================//
        // Input type:                                       //
        //   - int (n-th weighted importance)                // 
        //   - vector<vector<int>> ref. (roads vector)       //
        // Return type:                                      //
        //   - long long (result maximun summary importance) //
        //===================================================//

        /*Initialize*/
        ///// Length of roads vector /////
        int len_roads = roads.size();

        ///// Record vector /////
        vector<long long> record_vect(n, 0);

        ///// Result maximun summary importance /////
        long long res_max_sum = 0;


        /*Greedy-based loop traversal with recorded sorted vector*/
        ///// Step 1: Record indexed-value with vector /////
        for (int roads_idx = 0; (roads_idx < len_roads); (roads_idx++)) //Whole
        {
            (record_vect[(roads[roads_idx])[0]]) += 1; //Keep updating, accumulating
            (record_vect[(roads[roads_idx])[1]]) += 1; //Keep updating, accumulating

        } //Whole

        ///// Step 2: Looped-traversal with recorded sorted vector, hashmap /////
        sort(record_vect.begin(), record_vect.end()); //Sorted operations

        for (int n_idx = 1; (n_idx <= n); (n_idx++)) //Whole
        {
            res_max_sum += (record_vect[(n_idx - 1)] * n_idx); //Keep updating, recording

        } //Whole

        return res_max_sum;
    }
};
