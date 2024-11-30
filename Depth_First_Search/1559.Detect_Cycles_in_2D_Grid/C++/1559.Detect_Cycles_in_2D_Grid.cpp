class Solution {
public:
    bool containsCycle(vector<vector<char>> & grid) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<char>> ref. (grid vector) //
        // Return type:                                //
        //   - bool (result flag)                      //
        //=============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = grid.size(), len_cols = (grid[0]).size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, unordered_map<int, bool>> record_map;


        /*Recursion-based DFS loop traversal*/
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-char matched consitions or not /////
                if ((grid[rows_idx])[cols_idx] != '0')
                {
                    ///// Check if the current flag matched conditions or not /////
                    if (dfsTraversal(grid, len_rows, len_cols, rows_idx, cols_idx, (grid[rows_idx])[cols_idx], (-1), record_map))
                    {
                        return true;
                    }
                    else { ; }

                    record_map.clear(); //Update, Reset
                }
                else { ; }

            } //Columns

        } //Rows

        return false;
    }


    bool dfsTraversal(vector<vector<char>> & grid, int & len_rows, int & len_cols, int rows_idx, int cols_idx, char record_char, int record_dirc, unordered_map<int, unordered_map<int, bool>> & record_map)
    {
        //====================================================================================//
        // Input type:                                                                        //
        //   - vector<vector<char>> ref. (grid vector)                                        //
        //   - int ref. (length of rows)                                                      //
        //   - int ref. (length of columns)                                                   //
        //   - int (rows index)                                                               //
        //   - int (columns index)                                                            //
        //   - char (record char)                                                             //
        //   - int (record durection)                                                         //
        //   - unordered_map<int, unordered_map<int, bool>> ref. (record dictionary, hashmap) //
        // Return type:                                                                       //
        //   - bool (result flag)                                                             //
        //====================================================================================//
        if (((rows_idx < 0) || (rows_idx >= len_rows)) || ((cols_idx < 0) || (cols_idx >= len_cols))) { return false; } //Issue, Boundary-case handling

        if (record_map.find(rows_idx) != record_map.end()) //Issue, Boundary-case handling
        {
            if ((record_map[rows_idx]).find(cols_idx) != (record_map[rows_idx]).end()) { return true; }
        }

        if ((grid[rows_idx])[cols_idx] != record_char) { return false; } //Issue, Boundary-case handling


        /*Whole process, flow*/
        (record_map[rows_idx])[cols_idx] = true; //Update, Record

        (grid[rows_idx])[cols_idx] = '0'; //Update, Overwrite

        ///// Check if the current directions matched conditions or not /////
        if (record_dirc == (-1)) //Whole
        {
            return (dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_char, 0, record_map) | dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_char, 1, record_map) | dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_char, 2, record_map) | dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_char, 3, record_map)); //Recursion function call
        }

        else if (record_dirc == 0) //Left
        {
            return (dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_char, 0, record_map) | dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_char, 1, record_map) | dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_char, 3, record_map)); //Recursion function call
        }

        else if (record_dirc == 1) //Up
        {
            return (dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_char, 0, record_map) | dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_char, 1, record_map) | dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_char, 2, record_map)); //Recursion function call
        }

        else if (record_dirc == 2) //Right
        {
            return (dfsTraversal(grid, len_rows, len_cols, (rows_idx - 1), cols_idx, record_char, 1, record_map) | dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_char, 2, record_map) | dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_char, 3, record_map)); //Recursion function call
        }

        return (dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx - 1), record_char, 0, record_map) | dfsTraversal(grid, len_rows, len_cols, rows_idx, (cols_idx + 1), record_char, 2, record_map) | dfsTraversal(grid, len_rows, len_cols, (rows_idx + 1), cols_idx, record_char, 3, record_map)); //Recursion function call
    }
};
