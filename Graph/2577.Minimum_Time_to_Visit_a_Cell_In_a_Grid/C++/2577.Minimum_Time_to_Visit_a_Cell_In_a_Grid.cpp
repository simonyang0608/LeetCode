class Solution {
public:
    int minimumTime(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result minimun times)             //
        //============================================//
        if (((grid[0])[1] > 1) && ((grid[1])[0] > 1)) { return (-1); } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Edge rank vector /////
        vector<vector<int>> edge_rank_vect(len_rows, vector<int>(len_cols, INT_MAX));

        ///// Directions vector /////
        vector<vector<int>> direct_vect = {{0, (-1)}, {(-1), 0}, {0, 1}, {1, 0}};

        ///// Record heap, priority-queue /////
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> record_pq;


        /*Dijkstras' based loop traversal with recorded heap, priority-queue*/
        record_pq.push({0, 0, 0}); (edge_rank_vect[0])[0] = 0; //Update, Record

        while (! record_pq.empty()) //Cycled-times
        {
            int record_times = (record_pq.top())[0]; //Record times

            int record_rows_idx = (record_pq.top())[1]; int record_cols_idx = (record_pq.top())[2]; //Record rows, columns index

            record_pq.pop(); //Keep updating, popped

            ///// Check if the current position information matched conditions or not /////
            if (record_times != (edge_rank_vect[record_rows_idx])[record_cols_idx]) { continue; }

            ///// Check if the current position reached target or not /////
            if ((record_rows_idx == (len_rows - 1)) && (record_cols_idx == (len_cols - 1))) { return record_times; }

            for (int direct_idx = 0; (direct_idx < 4); (direct_idx++)) //4-Sider directions
            {
                int next_rows_idx = (record_rows_idx + (direct_vect[direct_idx])[0]); //Next rows index
                int next_cols_idx = (record_cols_idx + (direct_vect[direct_idx])[1]); //Next columns index

                ///// Check if the next position exceed boundary or not /////
                if (((next_rows_idx < 0) || (next_rows_idx >= len_rows)) || ((next_cols_idx < 0) || (next_cols_idx >= len_cols)))
                {
                    continue;
                }

                int next_times = (record_times + 1); //Next times

                ///// Check if the next times matched conditions or not /////
                if (next_times >= (grid[next_rows_idx])[next_cols_idx])
                {
                    ///// Check if the next times matched conditions or not /////
                    if ((edge_rank_vect[next_rows_idx])[next_cols_idx] > next_times)
                    {
                        (edge_rank_vect[next_rows_idx])[next_cols_idx] = next_times; //Keep updating, recording

                        record_pq.push({next_times, next_rows_idx, next_cols_idx}); //Keep updating, recording
                    }
                    else { ; }
                }
                else
                {
                    int cycle_times = ((grid[next_rows_idx])[next_cols_idx] - next_times); //Cycle times

                    ///// Check if the cycle times is odd or even /////
                    if ((cycle_times & 1)) { (cycle_times++); } //Keep updating, accumulating
                    else { ; }

                    next_times += cycle_times; //Keep updating, accumulating

                    ///// Check if the next times matched conditions or not /////
                    if ((edge_rank_vect[next_rows_idx])[next_cols_idx] > next_times)
                    {
                        (edge_rank_vect[next_rows_idx])[next_cols_idx] = next_times; //Keep updating, recording

                        record_pq.push({next_times, next_rows_idx, next_cols_idx}); //Keep updating, recording
                    }
                    else { ; }
                }

            } //4-Sider directions

        } //Cycled-times

        return (-1);
    }
};
