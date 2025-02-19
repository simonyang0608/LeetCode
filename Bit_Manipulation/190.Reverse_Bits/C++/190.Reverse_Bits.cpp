class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        //=============================//
        // Input type:                 //
        //   - uint32_t (n-value)      //
        // Return type:                //
        //   - uint32_t (result value) //
        //=============================//

        /*Initialize*/
        ///// Result value /////
        uint32_t res_val = 0;
    
        /*Bit-wise manipulations based loop traversal*/
        for (int record_idx = 31; (record_idx >= 0); (record_idx--)) //Whole
        {
            res_val |= ((1 << record_idx) & n) ? (1 << (31 - record_idx)) : 0; //Keep updating, overwriting

        } //Whole

        return res_val;
    }
};
