class Solution {
public:
    int largestAltitude(vector<int> & gain) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (gain vector) //
        // Return type:                       //
        //   - int (result maximun value)     //
        //====================================//

        /*Initialize*/
        ///// Length of gain vector /////
        int len_gain = gain.size();

        ///// Record vector (i.e. prefix-summary) /////
        vector<int> record_vect((len_gain + 1), 0);

        ///// Result maximun value /////
        int res_max_val = 0;


        /*Prefix-summary based loop traversal with recorded vector*/
        for (int record_idx = 1; (record_idx <= len_gain); (record_idx++)) //Whole
        {
            record_vect[record_idx] = (record_vect[(record_idx - 1)] + gain[(record_idx - 1)]); //Keep updating, overwriting

            res_max_val = (record_vect[record_idx] > res_max_val) ? record_vect[record_idx] : res_max_val; //Keep updating, overwriting

        } //Whole

        return res_max_val;
    }
};
