class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - vector<vector<int>> (result vector)    //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Result vector /////
        vector<vector<int>> res_vect(len_rows, vector<int>(len_cols, 0));

        ///// Record dictionary, hashmaps (i.e. 1th-rows, 1th-columns, 0th-rows, 0th-columns) /////
        unordered_map<int, int> record_map_1rows, record_map_1cols, record_map_0rows, record_map_0cols;


        /*Hashmap-based loop traversal*/
        ///// Step 1: Record indexed-value positions with dictionary, hashmap /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// check if the current indexed-value is 1 or 0 /////
                if ((grid[rows_idx])[cols_idx]) { ((record_map_1rows[rows_idx])++); ((record_map_1cols[cols_idx])++); } //Keep updating, recording
                else { ((record_map_0rows[rows_idx])++); ((record_map_0cols[cols_idx])++); } //Keep updating, recording

            } //Columns

        } //Rows

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                (res_vect[rows_idx])[cols_idx] = ((record_map_1rows[rows_idx] + record_map_1cols[cols_idx]) - (record_map_0rows[rows_idx] + record_map_0cols[cols_idx])); //Keep updating, overwriting

            } //Columns

        } //Rows

        return res_vect;
    }
};
