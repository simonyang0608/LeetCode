class Solution {
public:
    vector<int> grayCode(int n) 
    {
        //=================================//
        // Input type:                     //
        //   - int (n-th bits)             //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// Result vector /////
        vector<int> res_vect = {0, 1};

        /*Bit-manipulations based loop traversal*/
        for (int n_idx = 2; (n_idx <= n); (n_idx++)) //N-th bits
        {
            vector<int> reverse_vect(res_vect.begin(), res_vect.end()); //Reverse vector

            reverse(reverse_vect.begin(), reverse_vect.end()); //Reversed-operations

            res_vect.insert(res_vect.end(), reverse_vect.begin(), reverse_vect.end()); //Keep updating, concatenating

            for (int record_idx = (res_vect.size() - 1); (record_idx >= ((1 << n_idx) >> 1)); (record_idx--)) //Post-part
            {
                res_vect[record_idx] = ((1 << (n_idx - 1)) | res_vect[record_idx]); //Keep updating overwriting

            } //Post-part

        } //N-th bits

        return res_vect;
    }
};
