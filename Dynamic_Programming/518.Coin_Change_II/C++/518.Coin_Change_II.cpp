class Solution {
public:
    int change(int amount, vector<int> & coins) 
    {
        //=====================================//
        // Input type:                         //
        //   - int (total amounts)             //
        //   - vector<int> ref. (coins vector) //
        // Return type:                        //
        //   - int (result summary counter)    //
        //=====================================//

        /*Initialize*/
        ///// Length of coins vector /////
        int len_coins = coins.size();

        ///// Total amounts /////
        (amount++);

        ///// Record dynamic-programming (i.e. DP) vector /////
        vector<unsigned long long> record_dp_vect(amount, 0);
        record_dp_vect[0] = 1;

        ///// Record coin /////
        int record_coin;


        /*Dynamic-programming based loop traversal*/
        for (int coins_idx = 0; (coins_idx < len_coins); (coins_idx++)) //Whole
        {
            record_coin = coins[coins_idx]; //Record coin

            for (int amount_idx = record_coin; (amount_idx < amount); (amount_idx++)) //Part
            {
                ///// Check if the current combinations matched conditions or not /////
                if (record_dp_vect[(amount_idx - record_coin)]) { record_dp_vect[amount_idx] += record_dp_vect[(amount_idx - record_coin)]; } //Keep updating, accumulating
                else { ; }

            } //Part

        } //Whole

        return (int)(record_dp_vect[(--amount)]);
    }
};
