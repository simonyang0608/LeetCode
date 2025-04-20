class Solution {
public:
    int numSubmat(vector<vector<int>> & mat) 
    {
        //===========================================//
        // Input type:                               //
        //   - vector<vector<int>> ref. (mat vector) //
        // Return type:                              //
        //   - int (result summary counter)          //
        //===========================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = mat.size(), len_cols = (mat[0]).size();

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Dynamic-programming based loop traversal*/
        ///// Step 1: Looped-traversal for the prefix-summary counter /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 1; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((mat[rows_idx])[cols_idx]) { (mat[rows_idx])[cols_idx] += (mat[rows_idx])[(cols_idx - 1)]; } //Keep updating, accumulating
                else { ; }

            } //Columns

        } //Rows

        ///// Step 2: Post-process, Final completions /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((mat[rows_idx])[cols_idx])
                {
                    int record_cnter = (mat[rows_idx])[cols_idx]; //Record summary counter

                    res_cnter += record_cnter; //Keep updating, accumulating

                    for (int sub_rows_idx = (rows_idx - 1); (sub_rows_idx >= 0); (sub_rows_idx--)) //Part
                    {
                        record_cnter = ((mat[sub_rows_idx])[cols_idx] < record_cnter) ? (mat[sub_rows_idx])[cols_idx] : record_cnter; //Keep updating, overwriting

                        res_cnter += record_cnter; //Keep updating, accumulating

                    } //Part
                }
                else { ; }

            } //Columns

        } //Rows

        return res_cnter;
    }
};
