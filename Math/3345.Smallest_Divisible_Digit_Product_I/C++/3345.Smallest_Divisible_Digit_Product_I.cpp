class Solution {
public:
    int smallestNumber(int n, int t) 
    {
        //================================//
        // Input type:                    //
        //   - int (n-th value)           //
        //   - int (t factor)             //
        // Return type:                   //
        //   - int (result minimun value) //
        //================================//

        /*Greedy-based loop traversal*/
        while (n) //Search
        {
            ///// Check if the current product matched conditions or not ///// 
            if (! (digit2prod(n) % t)) { return n; }

            (n++); //Keep updating, accumulating

        } //Search

        return (-1);
    }


    int digit2prod(int n)
    {
        //==========================//
        // Input type:              //
        //   - int (n-th value)     //
        // Return type:             //
        //   - int (result product) //
        //==========================//

        /*Initialize*/
        ///// Record string /////
        string record_s = to_string(n);

        ///// Result product /////
        int res_prod = 1;


        /*Whole process, flow*/
        for (int s_idx = 0; (s_idx < record_s.size()); (s_idx++)) //Whole
        {
            res_prod *= (record_s[s_idx] - '0'); //Keep updating, product
             
        } //Whole

        return res_prod;
    }
};
