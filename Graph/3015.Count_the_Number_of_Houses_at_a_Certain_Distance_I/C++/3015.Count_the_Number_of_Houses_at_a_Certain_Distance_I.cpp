class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) 
    {
        //=================================//
        // Input type:                     //
        //   - int (n-th houses)           //
        //   - int (x-th house)            //
        //   - int (y-th house)            //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// X,Y connections /////
        (x--);
        (y--);

        ///// Record houses (i.e. minimun, maximun) /////
        int record_min_house = min(x, y), record_max_house = max(x, y);

        ///// Record minimun path /////
        int record_min_path;

        ///// Result vector /////
        vector<int> res_vect(n, 0);


        /*Minimun path-summary based loop traversal*/
        (n--); //Update, Reduce

        for (int n_idx = 0; (n_idx < n); (n_idx++)) //Whole
        {
            for (int path_idx = (n_idx + 1); (path_idx <= n); (path_idx++)) //Forward
            {
                record_min_path = min((path_idx - n_idx), ((abs(record_min_house - n_idx) + abs(path_idx - record_max_house)) + 1)); //Keep updating, overwriting

                res_vect[(record_min_path - 1)] += 2; //Keep updating, recording

            } //Forward

        } //Whole

        return res_vect;
    }
};
