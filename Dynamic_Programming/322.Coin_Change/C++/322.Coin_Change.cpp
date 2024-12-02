class Solution {
public:
    int coinChange(vector<int> & coins, int amount) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (coins vector) //
        //   - int (total amount)              //
        // Return type:                        //
        //   - int (result minimun steps)      //
        //=====================================//

        /*Initialize*/
        ///// Length of coins vector /////
        int len_coins = coins.size();

        ///// Total amounts /////
        (amount++);

        ///// Record coin /////
        int record_coin;

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<int> record_dp_vect(amount, (10001));
        record_dp_vect[0] = 0;


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int record_coins_idx = 0; (record_coins_idx < len_coins); (record_coins_idx++)) //Whole
        {
            record_coin = coins[record_coins_idx]; //Record coin

            for (int amount_idx = record_coin; (amount_idx < amount); (amount_idx++)) //Suffix-part, half
            {
                ///// Check if the current indexed-value matched conditions or not /////
                if (record_dp_vect[(amount_idx - record_coin)] != 10001)
                {
                    record_dp_vect[amount_idx] = min(record_dp_vect[amount_idx], (record_dp_vect[(amount_idx - record_coin)] + 1)); //Keep updating, overwriting
                }
                else { ; }

            } //Suffix-part, half

        } //Whole

        return (record_dp_vect[(amount - 1)] == 10001) ? (-1) : record_dp_vect[(amount - 1)];
    }
};
