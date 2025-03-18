class Solution {
public:
    vector<int> countBits(int n) 
    {
        //=================================//
        // Input type:                     //
        //   - int (n-th value)            //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// Result vector /////
        vector<int> res_vect((n + 1), 0);

        /*Bit-manipulation based loop traversal*/
        for (int n_idx = 0; (n_idx <= n); (n_idx++)) //Whole
        {
            int record_cnter = countBit(n_idx); //Record summary counter

            res_vect[n_idx] = record_cnter; //Keep updating, overwriting

        } //Whole

        return res_vect;
    }


    int countBit(int n_idx)
    {
        //==================================//
        // Input type:                      //
        //   - int (n-th index)             //
        // Return type:                     //
        //   - int (result summary counter) //
        //==================================//

        /*Initialize*/
        ///// Result summary counter /////
        int res_cnter = 0;

        /*Whole process, flow*/
        while (n_idx) //N-th
        {
            res_cnter += (n_idx & 1); //Keep updating, accumulating

            n_idx >>= 1; //Keep updating, bit-shifting

        } //N-th

        return res_cnter;
    }
};
