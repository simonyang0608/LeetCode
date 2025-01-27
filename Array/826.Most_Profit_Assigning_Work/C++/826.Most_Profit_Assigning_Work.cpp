class Solution {
public:
    int maxProfitAssignment(vector<int> & difficulty, vector<int> & profit, vector<int> & worker) 
    {
        //==========================================//
        // Input type:                              //
        //   - vector<int> ref. (difficulty vector) //
        //   - vector<int> ref. (profit vector)     //
        //   - vector<int> ref. (worker vector)     //
        // Return type:                             //
        //   - int (result maximun summary value)   //
        //==========================================//

        /*Initialize*/
        ///// Length of vectors (i.e. difficulty, worker) /////
        int len_difficulty = difficulty.size(), len_worker = worker.size();

        ///// Record vector /////
        vector<pair<int, int>> record_vect;

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record maximun value /////
        int record_max_val = 0;

        ///// Result maximun summary value /////
        int res_max_sum = 0;


        /*Greedy-based loop traversal with sorted operations*/
        ///// Step 1: Record tasks informations with vector /////
        for (int difficulty_idx = 0; (difficulty_idx < len_difficulty); (difficulty_idx++)) //Whole
        {
            record_vect.emplace_back(difficulty[difficulty_idx], profit[difficulty_idx]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded vector /////
        sort(record_vect.begin(), record_vect.end(), [&](const pair<int, int> & pair_1, const pair<int, int> & pair_2)
        {
            return (pair_1.first < pair_2.first);

        }); //Sorted operations
        
        sort(worker.begin(), worker.end()); //Sorted operations

        for (int worker_idx = 0; (worker_idx < len_worker); (worker_idx++)) //Whole
        {
            while ((record_trav_ptr < len_difficulty) && (worker[worker_idx] >= (record_vect[record_trav_ptr]).first)) //Part
            {
                record_max_val = max(record_max_val, (record_vect[(record_trav_ptr++)]).second); //Keep updating, overwriting

            } //Part

            res_max_sum += record_max_val; //Keep updating, accumulating
        }

        return res_max_sum;
    }
};
