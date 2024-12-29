class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> & heights) 
    {
        //===============================================//
        // Input type:                                   //
        //   - vector<vector<int>> ref. (heights vector) //
        // Return type:                                  //
        //   - vector<vector<int>> (result vector)       //
        //===============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = heights.size(), len_cols = (heights[0]).size();

        ///// Record vectors (i.e. pacific, altelantic) /////
        vector<vector<int>> record_pac_vect(len_rows, vector<int>(len_cols, 0));
        vector<vector<int>> record_alt_vect(len_rows, vector<int>(len_cols, 0));

        ///// Result vector /////
        vector<vector<int>> res_vect;


        /*Recursion-based DFS loop traversal with recorded vectors*/
        ///// Step 1: Record valis cells with vectors /////
        for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
        {
            dfsTraversal(heights, len_rows, len_cols, 0, cols_idx, (heights[0])[cols_idx], record_pac_vect); //Recursion function call (i.e. first row)
            dfsTraversal(heights, len_rows, len_cols, (len_rows - 1), cols_idx, (heights[(len_rows - 1)])[cols_idx], record_alt_vect); //Recursion function call (i.e. last row)

        }//Columns

        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            dfsTraversal(heights, len_rows, len_cols, rows_idx, 0, (heights[rows_idx])[0], record_pac_vect); //Recursion function call (i.e. first column)
            dfsTraversal(heights, len_rows, len_cols, rows_idx, (len_cols - 1), (heights[rows_idx])[(len_cols - 1)], record_alt_vect); //Recursion function call (i.e. last column)

        } //Rows

        ///// Step 2: Looped-traversal with recorded vectors /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value matched conditiosn or not /////
                if ((record_pac_vect[rows_idx])[cols_idx] && (record_alt_vect[rows_idx])[cols_idx])
                {
                    res_vect.push_back({rows_idx, cols_idx}); //Keep updating, recording
                }
                else { ; }

            } //Columns

        } //Rows

        return res_vect;
    }


    void dfsTraversal(vector<vector<int>> & heights, int & len_rows, int & len_cols, int rows_idx, int cols_idx, int & prev_val, vector<vector<int>> & record_vect)
    {
        //===============================================//
        // Input type:                                   //
        //   - vector<vector<int>> ref. (heights vector) //
        //   - int ref. (length of rows)                 //
        //   - int ref. (length of columns)              //
        //   - int (index of rows)                       //
        //   - int (index of columns)                    //
        //   - int ref. (previous height value)          //
        //   - vector<vector<int>> ref. (record vector)  //
        // Return type:                                  //
        //   - void (no return)                          //
        //===============================================//
        if (((rows_idx < 0) || (rows_idx >= len_rows)) || ((cols_idx < 0) || (cols_idx >= len_cols))) { return; } //Issue, Boundary-case handling

        if ((heights[rows_idx])[cols_idx] < prev_val) { return; } //Issue, Boundary-case handling

        if ((record_vect[rows_idx])[cols_idx]) { return; } //Issue, Boundary-case handling


        /*Whole process, flow*/
        (record_vect[rows_idx])[cols_idx] = 1; //Update, Overwrite

        dfsTraversal(heights, len_rows, len_cols, rows_idx, (cols_idx - 1), (heights[rows_idx])[cols_idx], record_vect); //Recursion function call (i.e. left)
        dfsTraversal(heights, len_rows, len_cols, (rows_idx - 1), cols_idx, (heights[rows_idx])[cols_idx], record_vect); //Recursion function call (i.e. up)
        dfsTraversal(heights, len_rows, len_cols, rows_idx, (cols_idx + 1), (heights[rows_idx])[cols_idx], record_vect); //Recursion function call (i.e. right)
        dfsTraversal(heights, len_rows, len_cols, (rows_idx + 1), cols_idx, (heights[rows_idx])[cols_idx], record_vect); //Recursion function call (i.e. down)
    }
};
