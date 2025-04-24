class Solution {
public:
    long long maxRunTime(int n, vector<int> & batteries) 
    {
        //=========================================//
        // Input type:                             //
        //   - int (n-th value)                    //
        //   - vector<int> ref. (batteries vector) //
        // Return type:                            //
        //   - long long (result maximun times)    //
        //=========================================//

        /*Initialize*/
        ///// Length of batteries vector /////
        int len_batteries = batteries.size();

        ///// Result summary value /////
        long long res_sum_val = 0;


        /*Greedy-based loop traversal*/
        for (int batteries_idx = 0; (batteries_idx < len_batteries); (batteries_idx++)) //Whole
        {
            res_sum_val += static_cast<long long>(batteries[batteries_idx]); //Keep updating, accumulating

        } //Whole

        sort(batteries.rbegin(), batteries.rend()); //Sorted operations

        for (int batteries_idx = 0; (batteries_idx < len_batteries); (batteries_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (batteries[batteries_idx] <= (res_sum_val / n)) { break; }

            res_sum_val -= batteries[batteries_idx]; //Keep updating, reducing

            (n--); //Keep updating, reducing

        } //Whole

        return (res_sum_val / n);
    }
};
