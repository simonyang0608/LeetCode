class Solution {
public:
    int equalPairs(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - int (result summary counter)           //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record dictionary, hashmap /////
        map<vector<int>, int> record_map;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Hashmap-based loop traversal*/
        ///// Step 1: Record rows vectors informations with dictionary, hashmap /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            ((record_map[grid[rows_idx]])++); //Keep updating, recording

        } //Rows

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
        {
            vector<int> record_vect; //Record vector

            for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
            {
                record_vect.emplace_back((grid[rows_idx])[cols_idx]); //Keep updating, recording

            } //Rows

            res_cnter += record_map[record_vect];

        } //Columns

        return res_cnter;
    }
};
