class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> & edges) 
    {
        //=============================================//
        // Input type:                                 //
        //   - int (n-th nodes)                        // 
        //   - vector<vector<int>> ref. (edges vector) //
        // Return type:                                // 
        //   - vector<int> (result vector)             //
        //=============================================//
        if (n == 1) { return {0}; } //Issue, Boundary-case handling
        else if (n == 2) { return {0, 1}; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of edges vector /////
        int len_edges = edges.size();

        ///// Record vector /////
        vector<int> record_vect(n, 0);

        ///// Record dictionary, hashmap /////
        map<int, vector<int>> record_map;

        for (int edges_idx = 0; (edges_idx < len_edges); (edges_idx++))
        {
            (record_map[(edges[edges_idx])[0]]).emplace_back((edges[edges_idx])[1]);
            (record_map[(edges[edges_idx])[1]]).emplace_back((edges[edges_idx])[0]);

            record_vect[(edges[edges_idx])[0]] += 1;
            record_vect[(edges[edges_idx])[1]] += 1;
        }

        ///// Record deque /////
        deque<int> record_dq;

        ///// Record size /////
        int record_size, record_front_val;

        ///// Result vector /////
        vector<int> res_vect;


        /*Greedy-based loop traversal with recorded deque*/
        ///// Step 1: Record extern root with 1 edges /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //Whole
        {
            ///// Check if the current indexed-root matched conditions or not /////
            if (record_vect[n_idx] == 1) { record_dq.push_back(n_idx); } //Keep updating, recording
            else { ; }

        } //Whole

        ///// Step 2: Looped-traversal with recorded deque /////
        while (n > 2) //Trim-times
        {
            record_size = record_dq.size(); //Record size

            n -= record_size; //Update, Reduce

            for (int record_times = 0; (record_times < record_size); (record_times++)) //Cycled-times
            {
                record_front_val = record_dq.front();

                for (int & record_val: record_map[record_front_val]) //Part
                {
                    ///// Check if the current remain edges matched conditions or not /////
                    if (record_vect[record_val] == 1) { continue; }

                    if ((--(record_vect[record_val])) == 1) { record_dq.push_back(record_val); } //Keep updating, recording
                    else { ; }

                } //Part

                record_dq.pop_front(); //Keep updating, popped

            } //Cycled-times

        } //Trim-times

        ///// Step 3: Post-process, Final completions /////
        while (! record_dq.empty()) //Remains
        {
            res_vect.emplace_back(record_dq.front()); //Keep updating, recording

            record_dq.pop_front(); //Keep updating, popped

        } //Remains

        return res_vect;
    }
};
