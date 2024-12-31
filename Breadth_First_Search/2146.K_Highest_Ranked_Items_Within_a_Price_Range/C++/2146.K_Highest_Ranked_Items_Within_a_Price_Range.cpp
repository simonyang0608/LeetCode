class Solution {
public:
    vector<vector<int>> highestRankedKItems(vector<vector<int>> & grid, vector<int> & pricing, vector<int> & start, int k) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        //   - vector<int> ref. (pricing vector)      //
        //   - vector<int> ref. (start vector)        //
        //   - int (k-th order)                       //
        // Return type:                               //
        //   - vector<vector<int>> (result vector)    //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record vector /////
        vector<vector<int>> record_vect(len_rows, vector<int>(len_cols, 0));

        ///// Record queue /////
        queue<pair<int, int>> record_queue;

        ///// Record heap, priority-queue /////
        priority_queue<vector<int>> record_pq;

        ///// Record pair /////
        pair<int, int> record_pair;

        ///// Record row, column /////
        int record_row, record_col;

        ///// Record value, distance /////
        int record_val, record_dist = 0;

        ///// Result vector /////
        vector<vector<int>> res_vect;


        /*Breath-first search based loop traversal with recorded heap, priority-queue*/
        record_queue.push(make_pair(start[0], start[1])); //Update, Record

        ///// Step 1: Record informations with heap, priority-queue /////
        while (! record_queue.empty()) //Whole
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                record_pair = record_queue.front(); record_queue.pop(); //Keep updating, overwriting

                record_row = record_pair.first; record_col = record_pair.second; //Keep updating, overwriting

                ///// Check if the current edge boundary is valid or not /////
                if (((record_row < 0) || (record_row >= len_rows)) || ((record_col < 0) || (record_col >= len_cols))) { continue; }

                ///// Check if the current position is valid or not /////
                if (! (grid[record_row])[record_col]) { continue; }

                ///// Check if the current position is visited or not /////
                if ((record_vect[record_row])[record_col]) { continue; }

                (record_vect[record_row])[record_col] = 1; //Keep updating, overwriting

                record_val = (grid[record_row])[record_col]; //Keep updating, overwriting

                ///// Check if the current value is in range or not /////
                if ((record_val >= pricing[0]) && (record_val <= pricing[1]))
                { 
                    record_pq.push({((-1) * record_dist), ((-1) * record_val), ((-1) * record_row), ((-1) * record_col)}); //Keep updating, recording
                }
                else { ; }

                record_queue.push(make_pair(record_row, (record_col - 1))); record_queue.push(make_pair((record_row - 1), record_col)); //Keep updating, recording
                record_queue.push(make_pair(record_row, (record_col + 1))); record_queue.push(make_pair((record_row + 1), record_col)); //Keep updating, recording

            } //Queue-size

            (record_dist++); //Keep updating, accumulating
        }

        ///// Step 2: Looped-traversal with recorded heap, priority-queue /////
        for (int record_idx = (k < record_pq.size()) ? k : record_pq.size(); (record_idx > 0); (record_idx--)) //Order-size
        {
            res_vect.push_back({((record_pq.top())[2] * (-1)), ((record_pq.top())[3] * (-1))}); //Keep updating, recording

            record_pq.pop(); //Keep updating, popped

        } //Order-size

        return res_vect;
    }
};
