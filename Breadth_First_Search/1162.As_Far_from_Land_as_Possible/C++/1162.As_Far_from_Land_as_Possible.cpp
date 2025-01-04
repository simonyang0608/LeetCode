class Solution {
public:
    int maxDistance(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result maximun distance)          //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record queue /////
        queue<pair<int, int>> record_queue;

        ///// Visit vector /////
        vector<vector<int>> visit_vect(len_rows, vector<int>(len_cols, 0));

        ///// Result steps /////
        int res_step = 0;


        /*Breath-first search based loop traversal*/
        ///// Step 1: Record land informations with queue /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current cell is land or not /////
                if ((grid[rows_idx])[cols_idx]) { record_queue.push(make_pair(rows_idx, cols_idx)); } //Keep updating, recording
                else { ; }

            } //Columns

        } //Rows

        ///// Step 2:Looped-traversal with recorded queue /////
        if (record_queue.empty() || (record_queue.size() == (len_rows * len_cols))) { return (-1); } //Issue, Boundary-case handling

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int record_rows = (record_queue.front()).first; int record_cols = (record_queue.front()).second; //Record rows, columns

                record_queue.pop(); //Updste, Popped

                ///// Check if the current position exceed boundary or not /////
                if (((record_rows < 0) || (record_rows >= len_rows)) || ((record_cols < 0) || (record_cols >= len_cols))) { continue; }

                ///// Check if the current position is visited or not /////
                if ((visit_vect[record_rows])[record_cols]) { continue; }

                (visit_vect[record_rows])[record_cols] = 1; //Keep updating, overwriting

                record_queue.push(make_pair(record_rows, (record_cols - 1))); record_queue.push(make_pair((record_rows - 1), record_cols)); //Keep updating, recording
                record_queue.push(make_pair(record_rows, (record_cols + 1))); record_queue.push(make_pair((record_rows + 1), record_cols)); //Keep updating, recording

            } //Queue-size

            (res_step++); //Keep updating, accumulating

        } //Cycled-times

        return (res_step - 2);
    }
};
