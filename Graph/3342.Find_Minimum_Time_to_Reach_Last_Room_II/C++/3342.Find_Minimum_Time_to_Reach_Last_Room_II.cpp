class Solution {
public:
    int minTimeToReach(vector<vector<int>> & moveTime) 
    {
        //================================================//
        // Input type:                                    //
        //   - vector<vector<int>> ref. (moveTime vector) //
        // Return type:                                   //
        //   - int (result minimun times)                 //
        //================================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = moveTime.size(), len_cols = (moveTime[0]).size();

        ///// Edge rank vector /////
        vector<vector<int>> edge_rank_vect(len_rows, vector<int>(len_cols, INT_MAX));

        ///// Directions vector /////
        vector<vector<int>> direct_vect = {{0, (-1)}, {(-1), 0}, {0, 1}, {1, 0}};

        ///// Record heap, priority-queue /////
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> record_pq;


        /*Dijkstras' based loop traversal with recorded heap, priority-queue*/
        record_pq.push({0, 0, 0, 1}); //Update, Record

        (edge_rank_vect[0])[0] = 0; //Update, Record

        while (! record_pq.empty()) //Cycled-times
        {
            int record_times = (record_pq.top())[0]; //Record times

            int record_rows_idx = (record_pq.top())[1]; int record_cols_idx = (record_pq.top())[2]; //Record rows, columns index

            int record_moves = (record_pq.top())[3]; record_pq.pop(); //Keep updating, popped

            ///// Check if the current times matched conditions or not /////
            if (record_times != (edge_rank_vect[record_rows_idx])[record_cols_idx]) { continue; }

            ///// Check if the current position reached target or not /////
            if ((record_rows_idx == (len_rows - 1)) && (record_cols_idx == (len_cols - 1))) { return record_times; }

            for (int direct_idx = 0; (direct_idx < 4); (direct_idx++)) //4-Sider directions
            {
                int next_rows_idx = (record_rows_idx + (direct_vect[direct_idx])[0]); //Next rows index
                int next_cols_idx = (record_cols_idx + (direct_vect[direct_idx])[1]); //Next columns index

                ///// Check if the next position exceed boundary or not /////
                if (((next_rows_idx < 0) || (next_rows_idx >= len_rows)) || ((next_cols_idx < 0) || (next_cols_idx >= len_cols))) { continue; }

                int next_times = (record_times > (moveTime[next_rows_idx])[next_cols_idx]) ? 
                                 (record_times + record_moves) : ((moveTime[next_rows_idx])[next_cols_idx] + record_moves); //Next times

                ///// Check if the next times information matched conditions or not /////
                if ((edge_rank_vect[next_rows_idx])[next_cols_idx] > next_times)
                {
                    (edge_rank_vect[next_rows_idx])[next_cols_idx] = next_times; //Keep updating, recording

                    record_pq.push({next_times, next_rows_idx, next_cols_idx, (record_moves == 1) ? 2 : 1}); //Keep updating, recording
                }
                else { ; }

            } //4-Sider directions

        } //Cycled-times

        return (-1);
    }
};
