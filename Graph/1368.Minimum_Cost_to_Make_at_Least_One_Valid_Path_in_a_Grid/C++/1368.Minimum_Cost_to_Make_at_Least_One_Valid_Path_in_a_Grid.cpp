class Solution {
public:
    int minCost(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result minimun cost)              //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Edge-rank vector /////
        vector<vector<int>> edge_rank_vect(len_rows, vector<int>(len_cols, INT_MAX));

        ///// Record heap, priority-queue /////
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> record_pq;

        ///// Record dictionary, hashmap /////
        unordered_map<int, pair<int, int>> record_map;


        /*Dijkstras' based loop traversal with recorded dictionary, hashmap, vector*/
        ///// Step 1: Record directions, first node informations, ...///
        record_map[1] = make_pair(0, 1); record_map[2] = make_pair(0, (-1)); //Update, Record (i.e. right, left)
        record_map[3] = make_pair(1, 0); record_map[4] = make_pair((-1), 0); //Update, record (i.e. low, up)

        (edge_rank_vect[0])[0] = 0; //Update, Record

        record_pq.emplace(0, make_pair(0, 0)); //Update, Record

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap, vector /////
        while (! record_pq.empty()) //Cycled-times
        {
            int curr_cost = (record_pq.top()).first; //Current cost

            int curr_rows_idx = ((record_pq.top()).second).first; //Current rows index
            int curr_cols_idx = ((record_pq.top()).second).second; //Current columns index

            record_pq.pop(); //Keep updating, popped

            ///// Check if the current cost matched conditions or not /////
            if ((edge_rank_vect[curr_rows_idx])[curr_cols_idx] != curr_cost) { continue; }

            ///// Check if the current position matched consitions or not /////
            if ((curr_rows_idx == (len_rows - 1)) && (curr_cols_idx == (len_cols - 1)))
            {
                return curr_cost;
            }

            for (int record_idx = 1; (record_idx <= 4); (record_idx++)) //Whole
            {
                int next_rows_idx = (curr_rows_idx + (record_map[record_idx]).first); //Next rows index
                int next_cols_idx = (curr_cols_idx + (record_map[record_idx]).second); //Next columns index

                ///// Check if the next position exceed boundary or not /////
                if (((next_rows_idx < 0) || (next_rows_idx >= len_rows)) || ((next_cols_idx < 0) || (next_cols_idx >= len_cols)))
                {
                    continue;
                }

                int next_cost = curr_cost; //Next cost

                ///// Check if the current direction matched conditions or not /////
                if (record_idx == (grid[curr_rows_idx])[curr_cols_idx]) { ; }
                else { (next_cost++); } //Keep updating, accumulating

                ///// Check if the next cost matched conditions or not /////
                if (next_cost < (edge_rank_vect[next_rows_idx])[next_cols_idx])
                {
                    (edge_rank_vect[next_rows_idx])[next_cols_idx] = next_cost; //Keep updating, overwriting

                    record_pq.emplace(next_cost, make_pair(next_rows_idx, next_cols_idx)); //Keep updating, recording
                }
                else { ; }

            } //Whole

        } //Cycled-times

        return (-1);
    }
};
