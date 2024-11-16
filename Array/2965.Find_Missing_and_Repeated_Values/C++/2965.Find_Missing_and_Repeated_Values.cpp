class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - vector<int> (result vector)            //
        //============================================//

        /*Initialize*/
        ///// Square, Length of grid vector /////
        int sqre_grid, len_grid = grid.size();

        sqre_grid = (len_grid * len_grid);

        ///// Record hashmap, dictionary /////
        unordered_map<int, bool> record_map;

        ///// Result vector /////
        vector<int> res_vect(2, 0);


        /*One-pass record based loop traversal with recorded hashmap, dictionary*/
        ///// Step 1: Record indexed-value with hashmap, dictionary /////
        for (int row_idx = 0; (row_idx < len_grid); (row_idx++)) //Row
        {
            for (int col_idx = 0; (col_idx < len_grid); (col_idx++)) //Column
            {
                ///// Check if the current indexed-value existed or not /////
                if (record_map.find((grid[row_idx])[col_idx]) != record_map.end())
                {
                    res_vect[0] = (grid[row_idx])[col_idx]; //Keep updating, overwriting
                }
                else { record_map[(grid[row_idx])[col_idx]] = true; } //Keep updating, recording

            } //Column

        } //Row

        ///// Step 2: Looped-traversal with recorded hashmap /////
        for (int sqre_idx = 1; (sqre_idx <= sqre_grid); (sqre_idx++)) //Whole
        {
            ///// Check if the current indexed-value existed or not /////
            if (record_map.find(sqre_idx) == record_map.end())
            {
                res_vect[1] = sqre_idx; //Keep updating, overwriting

                break;
            }
            else { ; }

        } //Whole

        return res_vect;
    }
};
