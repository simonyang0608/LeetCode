class Solution {
public:
    void DFS_Traversal(vector<vector<int>> & isConnected, int & len_columns, vector<bool> & record_trav, vector<int> & record_sub_idx)
    {
        //==========================================================//
        // Input type:                                              //
        //   - vector<vector<int>> ref. (isConnected vector)        //
        //   - int ref. (length of columns)                         //
        //   - vector<bool> ref. (record traversed, visited vector) //
        //   - vector<int> ref. (record sub-indexes vector)         //
        // Return type:                                             //
        //   - void (no return)                                     //
        //==========================================================//

        /*Whole process, flow*/
        for (int columns_idx = 0; (columns_idx < len_columns); (columns_idx++)) //Columns
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if ((record_sub_idx[columns_idx]))
            {
                if (! (record_trav[columns_idx]))
                {
                    record_trav[columns_idx] = true; //Keep updating, overwriting

                    DFS_Traversal(isConnected, len_columns, record_trav, isConnected[columns_idx]); //Recursion function call
                }
                else { ; }
            }

            else { ; }

        } //Columns
    }


    int findCircleNum(vector<vector<int>> & isConnected) 
    {
        //===================================================//
        // Input type:                                       //
        //   - vector<vector<int>> ref. (isConnected vector) //
        // Return type:                                      //
        //   - int (result summary counter)                  //
        //===================================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = isConnected.size(), len_columns = (isConnected[0]).size();

        ///// Record traversed, visited vector /////
        vector<bool> record_trav(len_rows, false);

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Recursion-based DFS loop traversal with recorded hashmap, dictionary*/
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (! (record_trav[rows_idx]))
            {
                record_trav[rows_idx] = true; //Keep updating, overwriting

                for (int columns_idx = 0; (columns_idx < len_columns); (columns_idx++)) //Columns
                {
                    ///// Check if the current indexed-value matched conditions or not /////
                    if (((isConnected[rows_idx])[columns_idx]))
                    {
                        (res_cnter++); //Keep updating, accumulating

                        DFS_Traversal(isConnected, len_columns, record_trav, isConnected[rows_idx]); //Recursion function call

                        break;
                    }
                    else { ; }

                } //Columns
            }

            else { ; }

        } //Rows

        return res_cnter;
    }
};
