class Solution {
public:
    int mincostTickets(vector<int> & days, vector<int> & costs) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (days vector)  //
        //   - vector<int> ref. (costs vector) //
        // Return type:                        //
        //   - int (result minimun costs)      //
        //=====================================//

        /*Initialize*/
        ///// Maximun of days vector /////
        int max_days = *max_element(days.begin(), days.end());

        (max_days++);

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp_vect(max_days, 0);


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int record_dp_idx = 1; (record_dp_idx < max_days); (record_dp_idx++)) //Whole
        {
            ///// Check if the current days existed or not /////
            if (find(days.begin(), days.end(), record_dp_idx) != days.end())
            {
                record_dp_vect[record_dp_idx] = (record_dp_vect[(record_dp_idx - 1)] + costs[0]); //Keep updating, overwriting

                ///// Check if the current days matched conditions or not /////
                if (record_dp_idx >= 7)
                {
                    record_dp_vect[record_dp_idx] = min(record_dp_vect[record_dp_idx], (record_dp_vect[(record_dp_idx - 7)] + costs[1])); //Keep updating, overwriting
                }
                else { record_dp_vect[record_dp_idx] = min(record_dp_vect[record_dp_idx], (record_dp_vect[0] + costs[1])); } //Keep updating, overwriting

                if (record_dp_idx >= 30)
                {
                    record_dp_vect[record_dp_idx] = min(record_dp_vect[record_dp_idx], (record_dp_vect[(record_dp_idx - 30)] + costs[2])); //Keep updating, overwriting
                }
                else { record_dp_vect[record_dp_idx] = min(record_dp_vect[record_dp_idx], (record_dp_vect[0] + costs[2])); } //Keep updating, overwriting
            }

            else { record_dp_vect[record_dp_idx] = record_dp_vect[(record_dp_idx - 1)]; } //Keep updating, overwriting

        } //Whole

        return record_dp_vect[(max_days - 1)];
    }
};
