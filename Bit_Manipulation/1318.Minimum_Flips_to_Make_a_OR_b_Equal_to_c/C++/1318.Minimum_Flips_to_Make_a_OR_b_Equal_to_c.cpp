class Solution {
public:
    int minFlips(int a, int b, int c) 
    {
        //==========================================//
        // Input type:                              //
        //   - int (a-value)                        //
        //   - int (b-value)                        //
        //   - int (c-value)                        //
        // Return type:                             //
        //   - int (result minimun summary counter) //
        //==========================================//

        /*Initialize*/
        ///// Result minimun summary counter
        int res_min_cnter = 0;

        /*Bit-manipulation based loop traversal*/
        for (int bit_idx = 31; (bit_idx >= 0); (bit_idx--)) //Bit-width
        {
            bool record_bit_a = ((a >> bit_idx) & 1); //Record bit-a
            bool record_bit_b = ((b >> bit_idx) & 1); //Record bit-b
            bool record_bit_c = ((c >> bit_idx) & 1); //Record bit-c

            ///// Check if the current bit-a, b matched conditions or not /////
            if (record_bit_a)
            {
                ///// Check if the current bit-b matched conditions or not /////
                if (record_bit_b)
                {
                    ///// Check if the current bit-c matched conditions or not /////
                    if (! record_bit_c) { res_min_cnter += 2; } //Keep updating, accumulating
                    else { ; }
                }
                else
                {
                    ///// Check if the current bit-c matched conditions or not /////
                    if (! record_bit_c) { (res_min_cnter++); } //Keep updating, accumulating
                    else { ; }
                }
            }

            else
            {
                ///// Check if the current bit-b matched conditions or not /////
                if (record_bit_b)
                {
                    ///// Check if the current bit-c matched conditions or not /////
                    if (! record_bit_c) { (res_min_cnter++); } //Keep updating, accumulating
                    else { ; }
                }
                else
                {
                    ///// Check if the current bit-c matched conditions or not /////
                    if (! record_bit_c) { ; }
                    else { res_min_cnter += 1; } //Keep updating, accumulating
                }
            }

        } //Bit-width

        return res_min_cnter;
    }
};
