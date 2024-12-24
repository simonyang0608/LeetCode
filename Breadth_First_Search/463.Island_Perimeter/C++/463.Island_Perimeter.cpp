class Solution {
public:
    int islandPerimeter(vector<vector<int>> & grid) 
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

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Breath-first-search based loop traversal*/
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((grid[rows_idx])[cols_idx])
                {
                    res_cnter += 4; //Keep updating, accumulating

                    ///// Check if the current border indexed-value matched conditions or not /////
                    if (((cols_idx - 1) >= 0) && ((grid[rows_idx])[(cols_idx - 1)])) { res_cnter -= 1; } //Left
                    else { ; }

                    if (((rows_idx - 1) >= 0) && ((grid[(rows_idx - 1)])[cols_idx])) { res_cnter -= 1; } //Up
                    else { ; }

                    if (((cols_idx + 1) < len_cols) && ((grid[rows_idx])[(cols_idx + 1)])) { res_cnter -= 1; } //Right
                    else { ; }

                    if (((rows_idx + 1) < len_rows) && ((grid[(rows_idx + 1)])[cols_idx])) { res_cnter -= 1; } //Down
                    else { ; }
                }
                else { ; }

            } //Columns

        } //Rows

        return res_cnter;
    }
};
