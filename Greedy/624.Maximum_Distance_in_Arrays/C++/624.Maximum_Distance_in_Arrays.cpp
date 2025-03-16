class Solution {
public:
    int maxDistance(vector<vector<int>> & arrays) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (arrays vector) //
        // Return type:                                 //
        //   - int (result maximun distance)            //
        //==============================================//

        /*Initialize*/
        ///// Length of arrays vector /////
        int len_arrays = arrays.size();

        ///// Record value (i.e. maximun, minimun) /////
        int record_max_val = ((-1) * 1e4 - 1), record_min_val = (1e4 + 1);

        ///// Record index (i.e. maximun, minimun) /////
        int record_max_idx, record_min_idx;


        /*Greedy-based loop traversal*/
        ///// Step 1: Looped-traversal for the first-round /////
        for (int arrays_idx = 0; (arrays_idx < len_arrays); (arrays_idx++)) //Whole
        {
            ///// Check if the current indexed-value is minimun or not /////
            if ((arrays[arrays_idx]).front() < record_min_val)
            {
                record_min_idx = arrays_idx; record_min_val = (arrays[arrays_idx]).front(); //Keep updating, overwriting
            }
            else { ; }

            ///// Check if the current indexed-value is maximun or not /////
            if ((arrays[arrays_idx]).back() > record_max_val)
            {
                record_max_idx = arrays_idx; record_max_val = (arrays[arrays_idx]).back(); //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        if (record_max_idx != record_min_idx) { return (record_max_val - record_min_val); } //Issue, Boundary-case handling

        ///// Step 2: Looped-traversal for the final-round /////
        int next_max_val = ((-1) * 1e4 - 1), next_min_val = (1e4 + 1); //Next value (i.e. maximun, minimun) /////

        for (int arrays_idx = 0; (arrays_idx < len_arrays); (arrays_idx++)) //Whole
        {
            ///// Check if the current index matched conditions or not /////
            if (arrays_idx == record_max_idx) { continue; }

            next_max_val = max(next_max_val, (arrays[arrays_idx]).back()); //Keep updating, overwriting
            next_min_val = min(next_min_val, (arrays[arrays_idx]).front()); //Keep updating, overwriting

        } //Whole

        int res_dist1 = (next_max_val - record_min_val), res_dist2 = (record_max_val - next_min_val); //Result distances (i.e. 1st, 2nd)

        return (res_dist1 > res_dist2) ? res_dist1 : res_dist2;
    }
};
