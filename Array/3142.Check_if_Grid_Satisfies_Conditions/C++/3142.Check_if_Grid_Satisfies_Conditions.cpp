class Solution {
public:
    bool satisfiesConditions(vector<vector<int>> & grid) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<vector<int>> ref. (grid vector) //
        // Return type:                               //
        //   - bool (result flag)                     //
        //============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Previous, Current value /////
        int prev_val, curr_val = (-1);


        /*One-pass record based loop traversal*/
        for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
        {
            prev_val = (grid[0])[cols_idx]; //Previous value

            ///// Check if the current value matched conditions or not /////
            if (curr_val != (-1))
            {
                ///// Check if the current value equals to previous value or not /////
                if (prev_val == curr_val) { return false; }
            }
            else { ; }

            for (int rows_idx = 1; (rows_idx < len_rows); (rows_idx++)) //Rows
            {
                ///// Check if the current value matched conditions or not /////
                if ((grid[rows_idx])[cols_idx] != prev_val) { return false; }

            } //Rows

            curr_val = prev_val; //Keep updating, overwriting

        } //Columns

        return true;
    }
};
