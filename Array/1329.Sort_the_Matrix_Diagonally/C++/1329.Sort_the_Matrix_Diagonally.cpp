class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> & mat) 
    {
        //===========================================//
        // Input type:                               //
        //   - vector<vector<int>> ref. (mat vector) //
        // Return type:                              //
        //   - vector<vector<int>> (result vector)   //
        //===========================================//

        /*Initialize*/
        ///// Length of rows, columns /////
        int len_rows = mat.size(), len_columns = (mat[0]).size();

        ///// Record hashmap, dictionary /////
        unordered_map<int, vector<int>> record_map;

        ///// Record differences /////
        int record_diff;


        /*Greedy-based loop traversal with recorded hashmap, dictionary*/
        ///// Step 1: Record indexed-value with hashmap, dictionary /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Row
        {
            for (int columns_idx = 0; (columns_idx < len_columns); (columns_idx++)) //Column
            {
                (record_map[(rows_idx - columns_idx)]).push_back((mat[rows_idx])[columns_idx]); //Keep updating, recording

            } //Column

        } //Row

        ///// Step 2: Sorted operations /////
        for (auto sub_item = record_map.begin(); (sub_item != record_map.end()); (sub_item++)) //Whole
        {
            sort((sub_item->second).begin(), (sub_item->second).end(), std::greater<int>()); //Keep updating, overwriting 

        } //Whole

        ///// Step 3: Looped-traversal with recorded hashmap /////
        for (int rows_idx = 0; (rows_idx < len_rows); (rows_idx++)) //Row
        {
            for (int columns_idx = 0; (columns_idx < len_columns); (columns_idx++)) //Column
            {
                record_diff = (rows_idx - columns_idx); //Record differences

                (mat[rows_idx])[columns_idx] = (record_map[record_diff]).back(); //Keep updating, overwriting
                (record_map[record_diff]).pop_back(); //Keep updating, popped

            } //Column

        } //Row

        return mat;
    }
};
