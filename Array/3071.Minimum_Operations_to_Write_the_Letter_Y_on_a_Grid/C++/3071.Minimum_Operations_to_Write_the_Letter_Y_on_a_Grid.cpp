class Solution {
public:
    int minimumOperationsToWriteY(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result minimun operations)        //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record y-internal summary counter /////
        int record_y_cnter = (len_rows + ((len_rows - 1) * 2));

        ///// Record y-external summary counter /////
        int record_ext_cnter = ((len_rows * len_cols) - record_y_cnter);

        ///// Record dictionary, hashmap (i.e. y-internal, y-external) /////
        unordered_map<int, int> record_map_y, record_map_ext;

        record_map_y[0] = 0; record_map_y[1] = 0; record_map_y[2] = 0;
        record_map_ext[0] = 0; record_map_ext[1] = 0; record_map_ext[2] = 0;


        /*Dictionary, Hash-map based loop traversal*/
        ///// Step 1: Record indexed-value for Y-th with dictionary, hashmap /////
        for (int record_idx = 0; (record_idx < (len_rows / 2));(record_idx++)) //Y-th
        {
            ((record_map_y[(grid[record_idx])[record_idx]])++); //Keep updating, recording
            ((record_map_y[(grid[record_idx])[((len_cols - 1) - record_idx)]])++); //Keep updating, recording

            (grid[record_idx])[record_idx] = 3; //Keep updating, overwriting
            (grid[record_idx])[((len_cols - 1) - record_idx)] = 3; //Keep updating, overwriting

        } //Y-th

        ((record_map_y[(grid[(len_rows / 2)])[(len_rows / 2)]])++); //Update, Record

        (grid[(len_rows / 2)])[(len_rows / 2)] = 3; //Update, Overwrite

        for (int record_idx = ((len_rows / 2) + 1); (record_idx < len_rows); (record_idx++)) //Y-th
        {
            ((record_map_y[(grid[record_idx])[(len_rows / 2)]])++); //Keep updating, recording

            (grid[record_idx])[(len_rows / 2)] = 3; //Keep updating, overwriting

        } //Y-th

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if (((grid[rows_idx])[cols_idx]) == 3) { continue; }

                ((record_map_ext[(grid[rows_idx])[cols_idx]])++); //Keep updating, recording

            } //Columns

        } //Rows

        return min({((record_y_cnter - record_map_y[0]) + (record_ext_cnter - max(record_map_ext[1], record_map_ext[2]))), ((record_y_cnter - record_map_y[1]) + (record_ext_cnter - max(record_map_ext[0], record_map_ext[2]))), ((record_y_cnter - record_map_y[2]) + (record_ext_cnter - max(record_map_ext[0], record_map_ext[1])))});
    }
};
