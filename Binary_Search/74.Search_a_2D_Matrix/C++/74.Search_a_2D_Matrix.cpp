class Solution {
public:
    bool searchMatrix(vector<vector<int>> & matrix, int target) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (matrix vector) //
        //   - int (target value)                       //
        // Return type:                                 //
        //   - bool (result flag)                       //
        //==============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = matrix.size(), len_cols = (matrix[0]).size();

        ///// Record pointers (i.e. rows-left, right, columns-left, right)
        int record_left_rows = 0, record_right_rows = (len_rows - 1);
        int record_left_cols = 0, record_right_cols = (len_cols - 1);


        /*Binary-search based loop traversal*/
        while (record_left_rows < record_right_rows) //Binary-search (i.e. rows)
        {
            int record_mid_rows = (record_left_rows + ((record_right_rows - record_left_rows) / 2)); //Record middle pointer (i.e. rows)

            ///// Check if the current indexed-value is larger than target or not /////
            if ((matrix[record_mid_rows]).back() >= target) { record_right_rows = record_mid_rows; } //Keep updating, overwriting
            else { record_left_rows = (record_mid_rows + 1); } //Keep updating, overwriting

        } //Binary-search (i.e. rows)

        while (record_left_cols <= record_right_cols) //Binary-search (i.e. columns)
        {
            int record_mid_cols = (record_left_cols + ((record_right_cols - record_left_cols) / 2)); //Record middle pointer (i.e. columns)

            ///// Check if the current indexed-value is larger than target or not /////
            if ((matrix[record_left_rows])[record_mid_cols] == target) { return true; }

            else if ((matrix[record_left_rows])[record_mid_cols] < target) { record_left_cols = (record_mid_cols + 1); } //Keep updating, overwriting
            else if ((matrix[record_left_rows])[record_mid_cols] > target) { record_right_cols = (record_mid_cols - 1); } //Keep updating, overwriting

        } //Binary-search (i.e. columns)

        return false;
    }
};
