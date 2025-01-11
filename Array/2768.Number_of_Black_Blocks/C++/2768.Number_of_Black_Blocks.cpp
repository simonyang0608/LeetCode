class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>> & coordinates) 
    {
        //===================================================//
        // Input type:                                       //
        //   - int (m-th rows)                               //
        //   - int (n-th columns)                            //
        //   - vector<vector<int>> ref. (coordinates vector) //
        // Return type:                                      //
        //   - vector<long long> (result vector)             //
        //===================================================//

        /*Initialize*/
        ///// Length of coordinates vector /////
        int len_coordinates = coordinates.size();

        ///// Total cells /////
        long long total_cnter = ((static_cast<long long>(m) - 1) * (static_cast<long long>(n) - 1));

        ///// Record dictionary, hashmap /////
        unordered_map<int, map<int, int>> record_map;

        ///// Record vector /////
        vector<vector<int>> record_vect = {{0, 0}, {(-1), 0}, {0, (-1)}, {(-1), (-1)}};

        ///// Result vector /////
        vector<long long> res_vect(5, 0);


        /*Hashmap-based loop traversal*/
        ///// Step 1: Record cells informations with dictionary, hashmap /////
        for (int coordinates_idx = 0; (coordinates_idx < len_coordinates); (coordinates_idx++)) //Whole
        {
            for (int record_idx = 0; (record_idx < 4); (record_idx++)) //Whole
            {
                int rows_idx = ((coordinates[coordinates_idx])[0] + (record_vect[record_idx])[0]); //Rows index
                int cols_idx = ((coordinates[coordinates_idx])[1] + (record_vect[record_idx])[1]); //Columns index

                ///// Check if the current indexed-position exceed boundary or not /////
                if (((rows_idx >= 0) && (rows_idx < (m - 1))) && ((cols_idx >= 0) && (cols_idx < (n - 1))))
                {
                    (((record_map[rows_idx])[cols_idx])++); //Keep updating, recording
                }
                else { ; }

            } //Whole

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (auto record_ele = record_map.begin(); (record_ele != record_map.end()); (record_ele++)) //Main-key
        {
            for (auto sub_ele = (record_ele->second).begin(); (sub_ele != (record_ele->second).end()); (sub_ele++)) //Minor-key
            {
                ((res_vect[(sub_ele->second)])++); (total_cnter--); //Keep updating, counting

            } //Minor-key

        } //Main-key

        res_vect[0] = total_cnter; //Update, Overwrite

        return res_vect;
    }
};
