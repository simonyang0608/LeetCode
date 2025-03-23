class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>> & grid) 
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

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<vector<int>> record_dp(len_rows, vector<int>(len_cols, 0));

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 399;


        /*Binary-search based loop traversal with recorded dynamic-programming vector*/
        ///// Step 1: Record distances to thief with dynamic-programming vector /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows (top-down)
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns (top-down)
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((grid[rows_idx])[cols_idx]) { continue; }

                (record_dp[rows_idx])[cols_idx] = 401; //Keep updating, overwriting

                ///// Check if the current rows index exceed boundary or not /////
                if ((rows_idx - 1) >= 0) { (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], 
                                                                                ((record_dp[(rows_idx - 1)])[cols_idx] + 1)); } //Keep updating, overwriting
                else { ; }

                if ((cols_idx - 1) >= 0) { (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], 
                                                                                ((record_dp[rows_idx])[(cols_idx - 1)] + 1)); } //Keep updating, overwriting
                else { ; }

            } //Columns (top-down)

        } //Rows (top-down)

        for (int rows_idx = (len_rows - 1); (rows_idx >= 0); (rows_idx--)) //Rows (bottom-up)
        {
            for (int cols_idx = (len_cols - 1); (cols_idx >= 0); (cols_idx--)) //Columns (bottom-up)
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((grid[rows_idx])[cols_idx]) { continue; }

                if ((rows_idx + 1) < len_rows) { (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], 
                                                                                      ((record_dp[(rows_idx + 1)])[cols_idx] + 1)); } //Keep updating, overwriting
                else { ; }

                if ((cols_idx + 1) < len_cols) { (record_dp[rows_idx])[cols_idx] = min((record_dp[rows_idx])[cols_idx], 
                                                                                      ((record_dp[rows_idx])[(cols_idx + 1)] + 1)); } //Keep updating, overwriting
                else { ; }

            } //Columns (bottom-up)

        } //Rows (bottom-up)

        ///// Step 2: Looped-traversal with recorded dynamic-programming vector /////
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) / 2); //Record middle pointer

            bool record_flag = bfsTraversal(len_rows, len_cols, record_dp, record_mid_ptr); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (record_flag) { record_left_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }


    bool bfsTraversal(const int & len_rows, const int & len_cols, const vector<vector<int>> & record_dp, const int & record_val)
    {
        //========================================================================//
        // Input type:                                                            //
        //   - const int ref. (length of rows)                                    //
        //   - const int ref. (length of columns)                                 //
        //   - const vector<vector<int>> ref. (record dynamic-programming vector) //
        //   - const int ref. (record value)                                      //
        // Return type:                                                           //
        //   - bool (result flag)                                                 //
        //========================================================================//

        /*Initialize*/
        ///// Record queue /////
        queue<pair<int, int>> record_queue;

        ///// Visit vector /////
        vector<vector<bool>> visit_vect(len_rows, vector<bool>(len_cols, false));

        ///// Directions vector /////
        vector<vector<int>> direc_vect = {{0, (-1)}, {(-1), 0}, {0, 1}, {1, 0}};

        /*Whole process, flow*/
        ///// Check if the current indexed-value matched conditions or not /////
        if ((record_dp[0])[0] >= record_val)
        {
            record_queue.emplace(0, 0); //Update, Record

            (visit_vect[0])[0] = true; //Update, Overwrite

            while (! record_queue.empty()) //Cycled-times
            {
                for (int queue_idx = record_queue.size(); queue_idx > 0; (queue_idx--)) //Queue-size
                {
                    int record_rows_idx = (record_queue.front()).first; int record_cols_idx = (record_queue.front()).second; //Record rows, columns index

                    record_queue.pop(); //Keep updating, popped

                    ///// Check if the current position reached target or not /////
                    if ((record_rows_idx >= (len_rows - 1)) && (record_cols_idx >= (len_cols - 1))) { return true; }

                    for (int direc_idx = 0; (direc_idx < 4); (direc_idx++)) //Directions
                    {
                        int next_rows_idx = (record_rows_idx + (direc_vect[direc_idx])[0]); //Next rows index
                        int next_cols_idx = (record_cols_idx + (direc_vect[direc_idx])[1]); //Next columns index

                        ///// Check if the next position exceed boundary or not /////
                        if (((next_rows_idx < 0) || (next_rows_idx >= len_rows)) || ((next_cols_idx < 0) || (next_cols_idx >= len_cols))) { continue; }

                        ///// Check if the next position is visited or not /////
                        if ((visit_vect[next_rows_idx])[next_cols_idx]) { continue; }

                        (visit_vect[next_rows_idx])[next_cols_idx] = true; //Keep updating, recording

                        ///// Check if the current indexed-value matched conditions or not /////
                        if ((record_dp[next_rows_idx])[next_cols_idx] >= record_val) { record_queue.emplace(next_rows_idx, next_cols_idx); } //Keep updating, recording
                        else { ; }

                    } //Directions

                } //Queue-size

            } //Cycled-times
        }
        else { ; }

        return false;
    }
};
