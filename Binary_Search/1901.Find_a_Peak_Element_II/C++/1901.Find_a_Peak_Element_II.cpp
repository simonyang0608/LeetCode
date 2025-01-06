class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>> & mat) 
    {
        //===========================================//
        // Input type:                               //
        //   - vector<vector<int>> ref. (mat vector) //
        // Return type:                              //
        //   - vector<int> (result vector)           //
        //===========================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = mat.size(), len_cols = (mat[0]).size();

        ///// Record pointers (i.e. middle, left, right) /////
        int record_mid_ptr, record_left_ptr = 0, record_right_ptr = (len_cols - 1);

        ///// Fixed row index /////
        int fixed_row_idx = 0;

        ///// Record flags (i.e left, right) /////
        bool record_lflag = false, record_rflag = false;


        /*Binary-search based loop traversal*/
        while (record_left_ptr <= record_right_ptr)
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            for (int record_row_idx = 0; (record_row_idx < len_rows); (record_row_idx++)) //Rows
            {
                ///// Check if the current indexed-value is maximun or not /////
                if ((mat[record_row_idx])[record_mid_ptr] > (mat[fixed_row_idx])[record_mid_ptr]) { fixed_row_idx = record_row_idx; } //Keep updating, overwriting
                else { ; }

            } //Rows

            ///// Check if the current right-half value matched conditions or not /////
            if (((record_mid_ptr + 1) >= len_cols) || (((mat[fixed_row_idx])[(record_mid_ptr)] > (mat[fixed_row_idx])[(record_mid_ptr + 1)])))
            {
                record_rflag |= true; //Keep updating, overwriting
            }
            else { ; }

            ///// Check if the current left-half value matched conditions or not /////
            if (((record_mid_ptr - 1) < 0) || (((mat[fixed_row_idx])[record_mid_ptr] > (mat[fixed_row_idx])[(record_mid_ptr - 1)])))
            {
                record_lflag |= true; //Keep updating, overwriting
            }
            else { ; }

            ///// Check if the current left, right-half value matched conditions or not /////
            if ((record_lflag && record_rflag)) { return {fixed_row_idx, record_mid_ptr}; }

            else if (! record_lflag) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

            else if (! record_rflag) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

            ///// Check if the current flag needs to be reset or not /////
            if (record_lflag) { record_lflag &= false; } //Keep updating, reset
            else  { ; }

            if (record_rflag) { record_rflag &= false; } //Keep updating, reset
            else  { ; }
        }

        return {(-1), (-1)};
    }
};
