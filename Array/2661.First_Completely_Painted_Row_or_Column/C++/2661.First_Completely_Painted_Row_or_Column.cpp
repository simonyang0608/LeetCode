class Solution {
public:
    int firstCompleteIndex(vector<int> & arr, vector<vector<int>> & mat) 
    {
        //===========================================//
        // Input type:                               //
        //   - vector<int> ref. (arr vector)         //
        //   - vector<vector<int>> ref. (mat vector) //
        // Return type:                              //
        //   - int (result minimun index)            //
        //===========================================//

        /*Initialize*/
        ///// Length of arr vector /////
        int len_arr = arr.size();

        ///// Length of rows, columns /////
        int len_rows = mat.size(), len_cols = (mat[0]).size();

        ///// Record dictionary, hashmap (i.e. cells position) /////
        map<int, pair<int, int>> record_pos_map;

        ///// Record dictionary, hashmap (i.e. rows, columns) /////
        unordered_map<int, int> record_rows_map, record_cols_map;


        /*Hashmap-based loop traversal*/
        ///// Step 1: Record cells position informations with dictionary, hashmap /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                record_pos_map[(mat[rows_idx])[cols_idx]] = make_pair(rows_idx, cols_idx); //Keep updating, recording

            } //Columns

        } //Rows

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int arr_idx = 0; (arr_idx < len_arr); (arr_idx++)) //Whole
        {
            int record_rows_idx = (record_pos_map[arr[arr_idx]]).first; //Record rows index
            int record_cols_idx = (record_pos_map[arr[arr_idx]]).second; //Record columns index

            ((record_rows_map[record_rows_idx])++); //Keep updating, accumulating
            ((record_cols_map[record_cols_idx])++); //Keep updating, accumulating

            ///// Check if the current cells position is completed or not /////
            if ((record_rows_map[record_rows_idx] >= len_cols) || (record_cols_map[record_cols_idx] >= len_rows))
            {
                return arr_idx;
            }
            else { ; }

        } //Whole

        return (-1);
    }
};
