class Solution {
public:
    int maxSideLength(vector<vector<int>> & mat, int threshold) 
    {
        //===========================================//
        // Input type:                               //
        //   - vector<vector<int>> ref. (mat vector) //
        //   - int (threshold value)                 //
        // Return type:                              //
        //   - int (result maximun sider)            //
        //===========================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = mat.size(), len_cols = (mat[0]).size();

        ///// Minimun sider /////
        int min_side = (len_rows < len_cols) ? len_rows : len_cols;

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = min_side;


        /*Binary-search based loop traversal*/
        ///// Step 1: Record indexed-value with recorded prefix-summary vector /////
        for (int rows_idx = 1; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            (mat[rows_idx])[0] += (mat[(rows_idx - 1)])[0]; //Keep updating, accumulating

        } //Rows

        for (int cols_idx = 1; (cols_idx < len_cols); (cols_idx++)) //Columns
        {
            (mat[0])[cols_idx] += (mat[0])[(cols_idx - 1)]; //Keep updating, accumulating

        } //Columns

        for (int rows_idx = 1; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = 1; (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                (mat[rows_idx])[cols_idx] += ((mat[(rows_idx - 1)])[cols_idx] + (mat[rows_idx])[(cols_idx - 1)] - 
                                              (mat[(rows_idx - 1)])[(cols_idx - 1)]); //Keep updating, accumulating

            } //Columns

        } //Rows

        ///// Step 2: Looped-traversal with prefix-summary vector /////
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) / 2); //Record middle pointer

            bool record_flag = isLargerSum(len_rows, len_cols, mat, record_mid_ptr, threshold); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (record_flag) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { record_left_ptr = record_mid_ptr; } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }


    bool isLargerSum(const int & len_rows, const int & len_cols, const vector<vector<int>> & mat, 
                     const int & record_val, const int & threshold)
    {
        //=================================================//
        // Input type:                                     //
        //   - const int ref. (length of rows)             //
        //   - const int ref. (length of columns)          //
        //   - const vector<vector<int>> ref. (mat vector) //
        //   - const int ref. (record value)               //
        //   - const int ref. (threshold value)            //
        // Return type:                                    //
        //   - bool (result flag)                          //
        //=================================================//

        /*Whole process, flow*/
        for (int rows_idx = (record_val - 1); (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            for (int cols_idx = (record_val - 1); (cols_idx < len_cols); (cols_idx++)) //Columns
            {
                int record_sum_val = (mat[rows_idx])[cols_idx]; //Record summary value

                ///// Check if the current rows index matched conditions or not /////
                if (rows_idx >= record_val) { record_sum_val -= (mat[(rows_idx - record_val)])[cols_idx]; } //Keep updating, reducing
                else { ; }

                ///// Check if the current columns index matched conditions or not /////
                if (cols_idx >= record_val) { record_sum_val -= (mat[rows_idx])[(cols_idx - record_val)]; } //Keep updating, reducing
                else { ; }

                ///// Check if the current rows, columns index matched conditions or not /////
                if ((rows_idx >= record_val) && (cols_idx >= record_val))
                {
                    record_sum_val += (mat[(rows_idx - record_val)])[(cols_idx - record_val)]; //Keep updating, accumulating
                }
                else { ; }

                ///// Check if the current summary value matched conditions or not /////
                if (record_sum_val <= threshold) { return false; }

            } //Columns

        } //Rows

        return true;
    }
};
