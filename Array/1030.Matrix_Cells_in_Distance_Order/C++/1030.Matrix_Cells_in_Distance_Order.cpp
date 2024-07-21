class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) 
    {
        //=============================================================//
        // - Input:                                                    //
        //   int (i.e. matrix rows)                                    //
        //   int (i.e. matrix columns)                                 //
        //   int (i.e. center of matrix rows)                          //
        //   int (i.e. center of matrix columns)                       //
        // - Return:                                                   //
        //   vector<vector<int>> (i.e. coordinates in sorted distance) //
        //=============================================================//

        /*Initialize*/
        ///// Result coordinate vector /////
        vector<vector<int>> res_coordnte_vect;

        ///// Temporal dictionary/hashmap, and its length /////
        map<int, vector<vector<int>>> tmp_map;
        int tmp_map_len;

        for (int tmp_row_idx = 0; tmp_row_idx < rows; tmp_row_idx++) //Rows
        {
            for (int tmp_col_idx = 0; tmp_col_idx < cols; tmp_col_idx++) //Columns
            {
                int tmp_distance = (abs(tmp_row_idx-rCenter) + abs(tmp_col_idx-cCenter)); //Temporal coordinate distances

                ///// Check if existing distances in hashmap or not /////
                if (tmp_map.find(tmp_distance) == tmp_map.end())
                {
                    tmp_map[tmp_distance] = {{tmp_row_idx, tmp_col_idx}}; //Insertion initialize
                }
                else
                {
                    tmp_map[tmp_distance].push_back({tmp_row_idx, tmp_col_idx}); //Insertion resume
                }
            } //Columns

        } //Rows

        res_coordnte_vect = tmp_map[0]; //Query first
        tmp_map_len = (tmp_map.size()); //Get length from hashmap


        /*Greedy-based loop traversal for coordinate with sorted distances*/
        for (int tmp_map_idx = 1; tmp_map_idx < tmp_map_len; tmp_map_idx++) //Whole
        {
            res_coordnte_vect.insert(res_coordnte_vect.end(), tmp_map[tmp_map_idx].begin(), tmp_map[tmp_map_idx].end()); //Insertion resume

        } //Whole

        return res_coordnte_vect;
    }
};
