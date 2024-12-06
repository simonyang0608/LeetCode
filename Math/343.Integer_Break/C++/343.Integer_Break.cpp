class Solution {
public:
    int integerBreak(int n) 
    {
        //==================================//
        // Input type:                      //
        //   - int (n-th value)             //
        // Return type:                     //
        //   - int (result maximun product) //
        //==================================//

        /*Initialize*/
        ///// Record maximun groups /////
        int record_max_group = (n / 2);

        ///// Record product /////
        int record_prod;

        ///// Record remainings /////
        int record_remains; 

        ///// Result maximun product /////
        int res_max_prod = 0;


        /*Math-based loop traversal*/
        for (int group_idx = 1; (group_idx <= record_max_group); (group_idx++)) //Groups
        {
            record_prod = group_idx; //Record product
            record_remains = (n - group_idx); //Record remainings

            while (record_remains > 0) //Remainings
            {
                res_max_prod = max(res_max_prod, (record_prod * record_remains)); //Keep updating, overwriting

                record_prod *= group_idx; //Keep updating, overwriting
                record_remains -= group_idx; //Keep updating, overwriting

            } //Remainings

        } //Groups

        return res_max_prod;
    }
};
