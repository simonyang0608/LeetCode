class Solution {
public:
    int nearestExit(vector<vector<char>> & maze, vector<int> & entrance) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<char>> ref. (maze vector) //
        //   - vector<int> ref. (entrance vector)      //
        // Return type:                                //
        //   - int (result minimun steps)              //
        //=============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = maze.size(), len_cols = (maze[0]).size();

        ///// Record queue /////
        queue<pair<int, int>> record_queue;

        ///// Record direction vector /////
        vector<vector<int>> record_direc = {{0, (-1)}, {(-1), 0}, {0, 1}, {1, 0}};

        ///// Result steps /////
        int res_steps = 0;


        /*Queue-based BFS loop traversal*/
        record_queue.emplace(entrance[0], entrance[1]); //Update, Record

        (maze[entrance[0]])[entrance[1]] = '+'; //Update, Overwrite

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int rows_idx = (record_queue.front()).first; int cols_idx = (record_queue.front()).second; //Rows, Columns index

                record_queue.pop(); //Keep updating, popped

                for (int direc_idx = 0; (direc_idx < 4); (direc_idx++)) //Directions
                {
                    int next_rows_idx = (rows_idx + (record_direc[direc_idx])[0]); int next_cols_idx = (cols_idx + (record_direc[direc_idx])[1]); //Next rows, columns index

                    ///// Check if the next position exceed boundary or not /////
                    if (((next_rows_idx < 0) || (next_rows_idx >= len_rows)) || ((next_cols_idx < 0) || (next_cols_idx >= len_cols))) { continue; }

                    ///// Check if the next position is wall or not /////
                    if ((maze[next_rows_idx])[next_cols_idx] == '+') { continue; }

                    ///// Check if the next position is at boundary or not /////
                    if (((next_rows_idx <= 0) || (next_rows_idx >= (len_rows - 1))) || ((next_cols_idx <= 0) || (next_cols_idx >= (len_cols - 1))))
                    {
                        return (res_steps + 1);
                    }

                    (maze[next_rows_idx])[next_cols_idx] = '+'; //Keep updating, overwriting

                    record_queue.emplace(next_rows_idx, next_cols_idx); //Keep updating, recording

                } //Directions

            } //Queue-size

            (res_steps++); //Keep updating, accumulating

        } //Cycled-times

        return (-1);
    }
};
