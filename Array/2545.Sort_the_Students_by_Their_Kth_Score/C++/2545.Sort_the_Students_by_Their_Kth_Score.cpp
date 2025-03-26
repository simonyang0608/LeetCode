class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>> & score, int k) 
    {
        //=============================================//
        // Input type:                                 //
        //   - vector<vector<int>> ref. (score vector) //
        //   - int (k-th index)                        //
        // Return type:                                //
        //   - vector<vector<int>> (result vector)     //
        //=============================================//

        /*Initialize*/
        ///// Length of rows /////
        int len_rows = score.size();

        ///// Record vector /////
        vector<pair<int, int>> record_vect;

        ///// Result vector /////
        vector<vector<int>> res_vect;


        /*Sorted-based loop traversal with recorded vector*/
        ///// Step 1: Record indexed-value informations with vector /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            record_vect.emplace_back((score[rows_idx])[k], rows_idx); //Keep updating, recording

        } //Rows

        ///// Step 2: Looped-traversal for the recorded vector /////
        sort(record_vect.begin(), record_vect.end(), [&](const pair<int, int> & pair_1, const pair<int, int> & pair_2)
        {
            return (pair_1.first > pair_2.first);

        }); //Sorted-operations

        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Rows
        {
            res_vect.push_back(score[(record_vect[rows_idx]).second]); //Keep updating, recording

        } //Rows

        return res_vect;
    }
};
