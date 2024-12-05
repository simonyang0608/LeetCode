class Solution {
public:
    int countHousePlacements(int n) 
    {
        //===============================//
        // Input type:                   //
        //   - int (n-th amount)         //
        // Return type:                  //
        //   - int (result combinations) //
        //===============================//

        /*Initialize*/
        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp_vect((++n), 0);

        record_dp_vect[0] = 1;
        record_dp_vect[1] = 2;

        ///// Record module /////
        int record_module = (pow(10, 9) + 7);


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int n_idx = 2; (n_idx < n); (n_idx++)) //Whole
        {
            record_dp_vect[n_idx] += (int)(((long long)(record_dp_vect[(n_idx - 1)]) + (long long)(record_dp_vect[(n_idx - 2)])) % record_module); //Keep updating, overwriting

        } //Whole

        return (int)(((long long)(record_dp_vect[(--n)]) * (long long)(record_dp_vect[n])) % record_module);
    }
};
