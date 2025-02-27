class Solution {
public:
    bool findSafeWalk(vector<vector<int>> & grid, int health) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        //   - int (health value)                     //
        // Return type:                               //
        //   - bool (result flag)                     //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record heap, priority-queue /////
        priority_queue<vector<int>> record_pq;

        ///// Visit vector /////
        vector<vector<bool>> visit_vect(len_rows, vector<bool>(len_cols, false));

        ///// Directions vector /////
        vector<vector<int>> direct_vect = {{0, (-1)}, {(-1), 0}, {0, 1}, {1, 0}};


        /*Dijkstra's-based loop traversal with recorded heap, priority-queue*/
        ///// Check if current indexed-value is 1 or 0 /////
        if ((grid[0])[0] == 1) { record_pq.push({(health - 1), 0, 0}); } //Update, Record
        else { record_pq.push({health, 0, 0}); } //Update, Record

        (visit_vect[0])[0] = true; //Update, Overwrite

        while (! record_pq.empty()) //Whole
        {
            int rows_idx = (record_pq.top())[1]; int cols_idx = (record_pq.top())[2]; //Rows, Columns index

            int record_health = (record_pq.top())[0]; record_pq.pop(); //Record health

            ///// Check if the current indexed-value reached destination or not /////
            if ((rows_idx >= (len_rows - 1)) && (cols_idx >= (len_cols - 1))) 
            {
                if (record_health >= 1) { return true; }
            }
    
            for (int direct_idx = 0; (direct_idx < 4); (direct_idx++)) //Directions
            {
                int next_rows_idx = (rows_idx + (direct_vect[direct_idx])[0]); //Next rows index

                int next_cols_idx = (cols_idx + (direct_vect[direct_idx])[1]); //Next columns index

                ///// Check if the current position exceed boundary or not /////
                if (((next_rows_idx < 0) || (next_rows_idx >= len_rows)) || ((next_cols_idx < 0) || (next_cols_idx >= len_cols))) { continue; }

                ///// Check if the current indexed-value is visited or not /////
                if ((visit_vect[next_rows_idx])[next_cols_idx]) { continue; }

                int next_health = ((grid[next_rows_idx])[next_cols_idx] == 1) ? (record_health - 1) : record_health; //Next health

                ///// Check if the next health value matched conditions or not /////
                if (next_health <= 0) { continue; }

                (visit_vect[next_rows_idx])[next_cols_idx] = true; //Keep updating, overwriting

                record_pq.push({next_health, next_rows_idx, next_cols_idx}); //Keep updating, recording

            } //Directions

        } //Whole

        return false;
    }
};
