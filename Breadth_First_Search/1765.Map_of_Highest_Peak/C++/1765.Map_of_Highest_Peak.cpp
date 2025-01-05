class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>> & isWater) 
    {
        //===============================================//
        // Input type:                                   //
        //   - vector<vector<int>> ref. (isWater vector) //
        // Return type:                                  //
        //   - vector<vector<int>> (result vector)       //
        //===============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = isWater.size(), len_cols = (isWater[0]).size();

        ///// Record queue /////
        queue<pair<int, int>> record_queue;

        ///// Visit vector /////
        vector<vector<int>> visit_vect(len_rows, vector<int>(len_cols, 0));

        ///// Result vector /////
        vector<vector<int>> res_vect(len_rows, vector<int>(len_cols, 0));

        ///// Record steps /////
        int record_step = 0;


        /*Breath-first search based loop traversal with recorded queue*/
        ///// Step 1: Record water cell position with queue /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current cell position is valid or not /////
                if ((isWater[rows_idx])[cols_idx]) { record_queue.push(make_pair(rows_idx, cols_idx)); } //Keep updating, recording
                else { ; }

            } //Columns

        } //Rows
        
        ///// Step 2: Looped-traversal with recorded queue /////
        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int record_rows_idx = (record_queue.front()).first; int record_cols_idx = (record_queue.front()).second; //Rows, Columns informations

                record_queue.pop(); //Keep updating, popped

                ///// Check if the current cell exceed boundary or not /////
                if (((record_rows_idx < 0) || (record_rows_idx >= len_rows)) || ((record_cols_idx < 0) || (record_cols_idx >= len_cols))) { continue; }

                ///// Check if the current cell is visited or not /////
                if ((visit_vect[record_rows_idx])[record_cols_idx]) { continue; }

                (visit_vect[record_rows_idx])[record_cols_idx] = 1; //Keep updating, overwriting

                (res_vect[record_rows_idx])[record_cols_idx] = record_step; //Keep updating, overwriting

                record_queue.push(make_pair(record_rows_idx, (record_cols_idx - 1))); //Keep updating, recording
                record_queue.push(make_pair((record_rows_idx - 1), record_cols_idx)); //Keep updating, recording
                record_queue.push(make_pair(record_rows_idx, (record_cols_idx + 1))); //Keep updating, recording
                record_queue.push(make_pair((record_rows_idx + 1), record_cols_idx)); //Keep updating, recording

            } //Queue-size

            (record_step++); //Keep updating, accumulating

        } //Cycled-times

        return res_vect;
    }
};
