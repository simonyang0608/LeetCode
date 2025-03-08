class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> & boxGrid) 
    {
        //================================================//
        // Input type:                                    //
        //   - vector<vector<char>> ref. (boxGrid vector) //
        // Return type:                                   //
        //   - vector<vector<char>> (result vector)       //
        //================================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = boxGrid.size(), len_cols = (boxGrid[0]).size();

        ///// Result vector /////
        vector<vector<char>> res_vect(len_cols, vector<char>(len_rows, '.'));


        /*Two-pointers based loop traversal*/
        ///// Step 1: Looped-traversal for modifying the original matrix, grid /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            int record_cols_idx = (-1); //Record columns index

            for (int cols_idx = (len_cols - 1); (cols_idx >= 0); (cols_idx--)) //Columns
            {
                ///// Check if the current char matched conditions or not /////
                if ((boxGrid[rows_idx])[cols_idx] == '.')
                {
                    ///// Check if the current index matched conditions or not /////
                    if (record_cols_idx == (-1)) { record_cols_idx = cols_idx; } //Keep updating, overwriting
                    else { ; }
                }

                else if ((boxGrid[rows_idx])[cols_idx] == '*') { record_cols_idx = (-1); } //Keep updating, reset
                else
                {
                    ///// Check if the current index matched conditions or not /////
                    if (record_cols_idx != (-1)) 
                    { 
                        swap((boxGrid[rows_idx])[cols_idx], (boxGrid[rows_idx])[record_cols_idx]); //Swap operations

                        (record_cols_idx--); //Keep updating, traversing
                    }
                    else { ; }
                }

            } //Columns

        } //Rows

        ///// Step 2: Post-process, Final completions /////
        for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
        {
            for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
            {
                ///// Check if the current indexed-char matched conditions or not /////
                if ((boxGrid[(len_rows - 1 - rows_idx)])[cols_idx] == '.') { continue; }

                (res_vect[cols_idx])[rows_idx] = (boxGrid[(len_rows - 1 - rows_idx)])[cols_idx]; //Keep updating, overwriting

            } //Rows

        } //Columns

        return res_vect;
    }
};
