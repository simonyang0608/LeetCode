class Solution {
public:
    int orangesRotting(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result minimun times)             //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record queue /////
        queue<pair<int, int>> record_queue;

        ///// Directions vector /////
        vector<vector<int>> direc_vect = {{0, (-1)}, {(-1), 0}, {0, 1}, {1, 0}};

        ///// Record summary counter /////
        int record_cnter = 0;

        ///// Result minimun times /////
        int res_min_times = 0;


        /*Breath-first search based loop traversal*/
        ///// Step 1: Record indexed-value informations with queue /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((grid[rows_idx])[cols_idx] == 1) { (record_cnter++); } //Keep updating, accumulating

                else if ((grid[rows_idx])[cols_idx] == 2) { record_queue.emplace(rows_idx, cols_idx); } //Keep updating, recording
                else { ; }

            } //Columns

        } //Rows

        ///// Step 2: Looped-traversal with recorded queue /////
        if (record_queue.empty() && record_cnter) { return (-1); } //Issue, Boundary-case handling

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int rows_idx = (record_queue.front()).first; int cols_idx = (record_queue.front()).second; //Rows, Columns index

                record_queue.pop(); //Keep updating, popped

                for (int direc_idx = 0; (direc_idx < 4); (direc_idx++)) //Directions index
                {
                    int next_rows_idx = (rows_idx + (direc_vect[direc_idx])[0]); int next_cols_idx = (cols_idx + (direc_vect[direc_idx])[1]); //Next rows, columns index

                    ///// check if the next positions matched conditions or not /////
                    if (((next_rows_idx < 0) || (next_rows_idx >= len_rows)) || ((next_cols_idx < 0) || (next_cols_idx >= len_cols))) { continue; }

                    if ((grid[next_rows_idx])[next_cols_idx] != 1) { continue; }

                    record_queue.emplace(next_rows_idx, next_cols_idx); //Keep updating, recording

                    (grid[next_rows_idx])[next_cols_idx] = 2; (record_cnter--); //Keep updating, reducing

                } //Directions index

            } //Queue-size

            (res_min_times++); //Keep updating, accumulating

        } //Cycled-times

        if (! res_min_times) { return 0; } //Issue, Boundary-case handling

        return (! record_cnter) ? (res_min_times - 1) : (-1);
    }
};
