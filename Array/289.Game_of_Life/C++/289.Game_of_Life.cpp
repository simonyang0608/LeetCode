class Solution {
public:
    void gameOfLife(vector<vector<int>> & board) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (board vector) //
        // Return type:                                //
        //   - void (no return)                        //
        //=============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = board.size(), len_cols = (board[0]).size();

        ///// Record board vector /////
        vector<vector<int>> record_board(len_rows, vector<int>(len_cols, (-1)));

        ///// Record queue /////
        queue<pair<int, int>> record_queue;

        ///// Record indexes (i.e. rows, columns) /////
        int record_row_idx, record_col_idx;

        ///// Record position vector /////
        vector<pair<int, int>> record_pos_vect;


        /*Breath-first search based loop traversal*/
        record_queue.push(make_pair(0, 0)); //Update, Record

        ///// Step 1: Record cell positions with queue, dictionary, hashmap /////
        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Times
            {
                record_row_idx = (record_queue.front()).first; record_col_idx = (record_queue.front()).second; //Keep updating, overwriting

                record_queue.pop(); //Keep updating, popped

                ///// Check if the current position is valid or not /////
                if (((record_row_idx < 0) || (record_row_idx >= len_rows)) || ((record_col_idx < 0) || (record_col_idx >= len_cols))) { continue; }
                if ((record_board[record_row_idx])[record_col_idx] != (-1)) { continue; }

                (record_board[record_row_idx])[record_col_idx] = 2; //Keep updating, overwriting

                boardTransform(board, len_rows, len_cols, record_row_idx, record_col_idx, record_pos_vect); //Transform function call

                ///// Record next stage positions /////
                record_queue.push(make_pair((record_row_idx - 1), record_col_idx)); 
                record_queue.push(make_pair((record_row_idx + 1), record_col_idx));
                record_queue.push(make_pair(record_row_idx, (record_col_idx - 1)));
                record_queue.push(make_pair(record_row_idx, (record_col_idx + 1)));
                record_queue.push(make_pair((record_row_idx - 1), (record_col_idx - 1)));
                record_queue.push(make_pair((record_row_idx + 1), (record_col_idx + 1)));
                record_queue.push(make_pair((record_row_idx + 1), (record_col_idx - 1)));
                record_queue.push(make_pair((record_row_idx - 1), (record_col_idx + 1)));

            } //Times

        } //Cycled-times

        ///// Step 2: Post-process, Final completions /////
        for (int record_idx = 0; (record_idx < record_pos_vect.size()); (record_idx++)) //Whole
        {
            record_row_idx = (record_pos_vect[record_idx]).first; record_col_idx = (record_pos_vect[record_idx]).second; //Keep updating, overwriting

            ///// Check if the current cell is live or dead /////
            if ((board[record_row_idx])[record_col_idx]) { (board[record_row_idx])[record_col_idx] = 0; } //Keep updating, overwriting
            else { (board[record_row_idx])[record_col_idx] = 1; } //Keep updating, overwriting

        } //Whole
    }


    void boardTransform(vector<vector<int>> & board, int & len_rows, int & len_cols, int & record_row_idx, int & record_col_idx, vector<pair<int, int>> & record_pos_vect)
    {
        //==========================================================//
        // Input type:                                              //
        //   - vector<vector<int>> ref. (board vector)              //
        //   - int ref. (length of rows)                            //
        //   - int ref. (length of columns)                         //
        //   - int ref. (record row index)                          //
        //   - int ref. (record column index)                       //
        //   - vector<pair<int, int>> ref. (record position vector) //
        // Return type:                                             //
        //   - void (no return)                                     //
        //==========================================================//

        /*Initialize*/
        ///// Record lives summary counter /////
        int record_lives_cnter = 0;

        /*Whole process, flow*/
        ///// Update, Accumulate for the neighbor lives /////
        record_lives_cnter += (((record_row_idx - 1) >= 0) && ((board[(record_row_idx - 1)])[record_col_idx])) ? 1 : 0;
        record_lives_cnter += (((record_row_idx + 1) < len_rows) && ((board[(record_row_idx + 1)])[record_col_idx])) ? 1 : 0;
        record_lives_cnter += (((record_col_idx - 1) >= 0) && ((board[record_row_idx])[(record_col_idx - 1)])) ? 1 : 0;
        record_lives_cnter += (((record_col_idx + 1) < len_cols) && ((board[record_row_idx])[(record_col_idx + 1)])) ? 1 : 0;

        record_lives_cnter += ((((record_row_idx - 1) >= 0) && (record_col_idx - 1) >= 0) && ((board[(record_row_idx - 1)])[(record_col_idx - 1)])) ? 1 : 0;
        record_lives_cnter += ((((record_row_idx + 1) < len_rows) && ((record_col_idx + 1) < len_cols)) && ((board[(record_row_idx + 1)])[(record_col_idx + 1)])) ? 1 : 0;
        record_lives_cnter += ((((record_row_idx - 1) >= 0) && ((record_col_idx + 1) < len_cols)) && ((board[(record_row_idx - 1)])[(record_col_idx + 1)])) ? 1 : 0;
        record_lives_cnter += ((((record_row_idx + 1) < len_rows) && ((record_col_idx - 1) >= 0)) && ((board[(record_row_idx + 1)])[(record_col_idx - 1)])) ? 1 : 0;

        ///// Check if the current cell needs to be transform or not /////
        if ((board[record_row_idx])[record_col_idx])
        {
            ///// Check if the current summary counter matched conditions or not /////
            if (record_lives_cnter < 2) { record_pos_vect.push_back(make_pair(record_row_idx, record_col_idx)); } //Update, Record

            else if ((record_lives_cnter == 2) || (record_lives_cnter == 3)) { ; }
            else if (record_lives_cnter > 3) { record_pos_vect.push_back(make_pair(record_row_idx, record_col_idx)); } //Update, Record
        }
        else
        {
            ///// Check if the current summary counter matched conditions or not /////
            if (record_lives_cnter == 3) { record_pos_vect.push_back(make_pair(record_row_idx, record_col_idx)); } //Update, Record
            else { ; }  
        }
    }
};
