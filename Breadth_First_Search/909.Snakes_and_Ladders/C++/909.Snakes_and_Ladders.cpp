class Solution {
public:
    int snakesAndLadders(vector<vector<int>> & board)
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (board vector) //
        // Return type:                                //
        //   - int (result minimun step)               //
        //=============================================//

        /*Initialize*/
        ///// Length of board vector /////
        int len_board = board.size();

        ///// Record, Next, Total steps /////
        int record_step, next_step, total_step = (len_board * len_board);

        ///// Record queue /////
        queue<int> record_queue;

        ///// Record pair /////
        pair<int, int> record_pair;

        ///// Record vector /////
        vector<bool> record_vect((total_step + 1), 0);

        ///// Result minimun step /////
        int res_min_step = 0;


        /*Breath-first-search based loop traversal with recorded vector*/
        record_vect[1] = 1; //Update, Overwrite

        record_queue.push(1); //Update, Record

        while (! record_queue.empty()) //Whole
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                record_step = record_queue.front(); record_queue.pop(); //Keep updating, overwriting

                ///// Check if the current step reaches destinations or not /////
                if (record_step == total_step) { return res_min_step; }

                for (int record_idx = 1; (((record_step + record_idx) <= total_step) && (record_idx <= 6)); (record_idx++)) //6-step
                {
                    record_pair = getPosition((record_step + record_idx), len_board); //Keep updating, overwriting

                    next_step = ((board[record_pair.first])[record_pair.second] == (-1)) ? (record_step + record_idx) : (board[record_pair.first])[record_pair.second]; //Keep updating, overwriting

                    ///// Check if the current step is visited or not /////
                    if (record_vect[next_step]) { continue; }

                    record_vect[next_step] = 1; //Keep updating, overwriting

                    record_queue.push(next_step); //Keep updating, recording

                } //6-step

            } //Queue-size

            (res_min_step++); //Keep updating, accumulating

        } //Whole

        return (-1);
    }


    pair<int, int> getPosition(int next_step, int & len_board)
    {
        //=======================================//
        // Input type:                           //
        //   - int (next-step)                   //
        //   - int ref. (length of board vector) //
        // Return type:                          //
        //   - pair<int, int> (result positions) //
        //=======================================//

        /*Initialize*/
        ///// Record quotient, remainings /////
        int record_quot = (next_step / len_board), record_remain = (next_step % len_board);

        ///// Result indexes (i.e. row, columns) /////
        int res_row_idx, res_col_idx;


        /*Whole process, flow*/
        res_row_idx = (record_remain) ? (len_board - (record_quot + 1)) : (len_board - record_quot); //Update, Overwirte

        ///// Check if the current remainings matched conditions or not /////
        if (! record_remain) { res_col_idx = (record_quot % 2) ? (len_board - 1) : 0; } //Update, Overwirte
        else { res_col_idx = ((len_board - res_row_idx) % 2) ? (record_remain - 1) : (len_board - record_remain); } //Update, Overwirte

        return make_pair(res_row_idx, res_col_idx);
    }
};
