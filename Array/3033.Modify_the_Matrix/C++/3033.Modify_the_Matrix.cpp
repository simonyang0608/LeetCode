class Solution {
public:
    vector<vector<int>> modifiedMatrix(vector<vector<int>> & matrix) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (matrix vector) //
        // Return type:                                 //
        //   - vector<vector<int>> (result vector)      //
        //==============================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = matrix.size(), len_cols = (matrix[0]).size();

        /*Greedy-based loop traversal*/
        for (int cols_idx = 0; (cols_idx < len_cols); (cols_idx++)) //Columns
        {
            int record_max_val = (-2); //Record maximun value

            vector<int> record_vect; //Record vector

            for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if ((matrix[rows_idx])[cols_idx] == (-1))
                {
                    record_vect.emplace_back(rows_idx); continue;
                }

                record_max_val = max(record_max_val, (matrix[rows_idx])[cols_idx]); //Keep updating, overwriting

            } //Rows

            for (const int & record_val: record_vect) //Whole
            {
                (matrix[record_val])[cols_idx] = record_max_val; //Keep updating, overwriting

            } //Whole

        } //Columns

        return matrix;
    }
};
