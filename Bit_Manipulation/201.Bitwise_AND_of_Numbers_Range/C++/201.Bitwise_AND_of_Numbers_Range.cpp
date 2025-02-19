class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        //========================//
        // Input type:            //
        //   - int (left-value)   //
        //   - int (right-value)  //
        // Return type:           //
        //   - int (result value) //
        //========================//

        /*Initialize*/
        ///// Result value /////
        int res_val = 0;

        /*Bit-wise manipulations based loop traversal*/
        for (int record_idx = 31; (record_idx >= 0); (record_idx--)) //Whole
        {
            int record_bit_val = (1 << record_idx); //Record bit-value

            ///// Check if the current bit-value matched conditions or not /////
            if ((record_bit_val & left) == (record_bit_val & right))
            {
                ///// Check if the current bit is one or zero /////
                if (record_bit_val & left) { res_val |= record_bit_val; } //Keep updating, overwriting
                else { ; }
            }
            else { break; }

        } //Whole

        return res_val;
    }
};
