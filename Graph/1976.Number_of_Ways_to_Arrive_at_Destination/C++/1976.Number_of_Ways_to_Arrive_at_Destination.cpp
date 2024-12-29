class Solution {
public:
    int countPaths(int n, vector<vector<int>> & roads) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        //
        //   - vector<vector<int>> ref. (roads vector) //
        // Return type:                                //
        //   - int (result minimun path summary value) //
        //=============================================//

        /*Initialize*/
        ///// Length of roads vector /////
        int len_roads = roads.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<pair<int, int>>> record_map;

        ///// Accumulate path vector /////
        vector<long long> accu_path_vect(n, 1e12);

        ///// Path summary counter vector /////
        vector<long long> path_cnter_vect(n, 0);

        ///// Record heap, priority-queue /////
        priority_queue<pair<long long, int>> record_pq;

        ///// Record value, module /////
        int record_val, record_module = (1e9 + 7);

        ///// Record distance /////
        long long record_dist;

        ///// Record accumulate distance /////
        long long record_accu_dist;


        /*Dijkstra's based loop traversal with recorded vectors, dictionary, hashmap*/
        ///// Step 1: Record root-child informations with dictionary, hashmap /////
        for (int roads_idx = 0; (roads_idx < len_roads); (roads_idx++)) //Whole
        {
            (record_map[(roads[roads_idx])[0]]).push_back(make_pair((roads[roads_idx])[1], (roads[roads_idx])[2])); //Keep updating, recording
            (record_map[(roads[roads_idx])[1]]).push_back(make_pair((roads[roads_idx])[0], (roads[roads_idx])[2])); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        record_pq.push(make_pair(0, 0)); //Update, Record

        accu_path_vect[0] = 0; //Update, Record

        path_cnter_vect[0] = 1; //Update, Record

        while (! record_pq.empty()) //Cycle-times
        {
            record_val = (record_pq.top()).second; record_dist = ((record_pq.top()).first * (-1)); record_pq.pop(); //Record values, distance, ...

            ///// Check if the current accumulated distance is valid or not /////
            if (accu_path_vect[record_val] != record_dist) { continue; }

            for (pair<int, int> & record_pair: record_map[record_val]) //Times
            {
                record_accu_dist = (accu_path_vect[record_val] + record_pair.second); //Keep updating, overwriting

                ///// Check if the next distances is smaller or not /////
                if (record_accu_dist < accu_path_vect[record_pair.first])
                {
                    record_pq.push(make_pair((record_accu_dist * (-1)), record_pair.first)); //Keep updating, recording

                    accu_path_vect[record_pair.first] = record_accu_dist; //Keep updating, overwriting

                    path_cnter_vect[record_pair.first] = path_cnter_vect[record_val]; //Keep updating, overwriting
                }
                else if (record_accu_dist == accu_path_vect[record_pair.first])
                {
                    path_cnter_vect[record_pair.first] += (path_cnter_vect[record_val] % record_module); //Keep updating, accumulating
                }

            } //Times

        } //Cycle-times

        return (path_cnter_vect[(n - 1)] % record_module);
    }
};
