class Solution {
public:
    int swimInWater(vector<vector<int>> & grid) 
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

        ///// Record values (i.e. minimun, maximun) /////
        int record_min_val = 2500, record_max_val = (-1);

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;


        /*Binary-search based loop traversal*/
        ///// Step 1: Looped-traversal for searching for the min, max values /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                record_max_val = ((grid[rows_idx])[cols_idx] > record_max_val) ? (grid[rows_idx])[cols_idx] : record_max_val; //Keep updating, overwriting
                record_min_val = ((grid[rows_idx])[cols_idx] < record_min_val) ? (grid[rows_idx])[cols_idx] : record_min_val; //Keep updating, overwriting

            } //Columns

        } //Rows

        ///// Step 2: Post-process, Final completions /////
        record_right_ptr = (record_max_val - record_min_val); //Update, Overwrite

        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            bool record_flag = isValid(len_rows, len_cols, grid, record_mid_ptr); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (! record_flag) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }


    bool isValid(const int & len_rows, const int & len_cols, const vector<vector<int>> & grid, 
                 const int & record_val)
    {
        //==================================================//
        // Input type:                                      //
        //   - const int ref. (length of rows)              //
        //   - const int ref. (length of columns)           //
        //   - const vector<vector<int>> ref. (grid vector) //
        //   - const int ref. (record value)                //
        // Return type:                                     //
        //   - bool (result flag)                           //
        //==================================================//

        /*Initialize*/
        ///// Visit vector /////
        vector<vector<bool>> visit_vect(len_rows, vector<bool>(len_cols, false));

        ///// Record queue /////
        queue<pair<int, int>> record_queue;

        ///// Directions vector /////
        vector<vector<int>> direc_vect = {{0, (-1)}, {(-1), 0}, {0, 1}, {1, 0}};


        /*Whole process, flow*/
        if ((grid[0])[0] > record_val) { return false; }

        record_queue.emplace(0, 0); //Update, Record

        (visit_vect[0])[0] = true; //Update, Record

        while (! record_queue.empty()) //Cycled-times (i.e. BFS)
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int record_rows_idx = (record_queue.front()).first; int record_cols_idx = (record_queue.front()).second; //Record rows, columns index

                record_queue.pop(); //Keep updating, popped

                ///// Check if the current position reached target or not /////
                if ((record_rows_idx == (len_rows - 1)) && (record_cols_idx == (len_cols - 1))) { return true; }

                for (int direc_idx = 0; (direc_idx < 4); (direc_idx++)) //4-Sider directions
                {
                    int next_rows_idx = (record_rows_idx + (direc_vect[direc_idx])[0]); //Next rows index
                    int next_cols_idx = (record_cols_idx + (direc_vect[direc_idx])[1]); //Next columns index

                    ///// Check if the next position exceed boundary or not /////
                    if (((next_rows_idx < 0) || (next_rows_idx >= len_rows)) || ((next_cols_idx < 0) || (next_cols_idx >= len_cols))) { continue; }
                    
                    ///// Check if the next position is visited or not /////
                    if ((visit_vect[next_rows_idx])[next_cols_idx]) { continue; }

                    ///// Check if the next indexed-value matched conditions or not /////
                    if ((grid[next_rows_idx])[next_cols_idx] > record_val) { continue; }

                    (visit_vect[next_rows_idx])[next_cols_idx] = true; //Keep updating, recording

                    record_queue.emplace(next_rows_idx, next_cols_idx); //Keep updating, recording

                } //4-Sider directions

            } //Queue-size

        } //Cycled-times (i.e. BFS)

        return false;
    }
};
