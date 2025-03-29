class Solution {
public:
    int getMaximumConsecutive(vector<int> & coins) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (coins vector) //
        // Return type:                        //
        //   - int (result maximun length)     //
        //=====================================//

        /*Initialize*/
        ///// Length of coins vector /////
        int len_coins = coins.size();

        ///// Record summary counter /////
        int record_cnter = 1;


        /*Greedy-based loop traversal with sorted-operations*/
        sort(coins.begin(), coins.end()); //Sorted-operations

        for (int coins_idx = 0; (coins_idx < len_coins); (coins_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (coins[coins_idx] <= record_cnter) { record_cnter += coins[coins_idx]; } //Keep updating, accumulating
            else { return record_cnter; }
        }

        return record_cnter;
    }
};
