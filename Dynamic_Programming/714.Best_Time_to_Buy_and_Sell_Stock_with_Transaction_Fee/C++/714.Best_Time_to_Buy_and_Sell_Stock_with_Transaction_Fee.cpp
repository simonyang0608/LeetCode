class Solution {
public:
    int maxProfit(vector<int> & prices, int fee) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (prices vector) //
        //   - int (fee-value)                  //
        // Return type:                         //
        //   - int (result maximun profit)      //
        //======================================//

        /*Initialize*/
        ///// Length of prices vector /////
        int len_prices = prices.size();

        ///// Record dynamic-programming vectors (i.e. earned, cost) /////
        vector<int> record_dp_earned(len_prices, 0), record_dp_cost(len_prices, 0);


        /*Dynamic-programming based loop traversal*/
        record_dp_cost[0] = ((-1) * prices[0]); //Update, Overwrite

        for (int prices_idx = 1; (prices_idx < len_prices); (prices_idx++)) //Whole
        {
            record_dp_earned[prices_idx] = max(record_dp_earned[(prices_idx - 1)], 
                                              (prices[prices_idx] + record_dp_cost[(prices_idx - 1)] - fee)); //Keep updating, overwriting

            record_dp_cost[prices_idx] = max(record_dp_cost[(prices_idx - 1)], (record_dp_earned[prices_idx] - 
                                             prices[prices_idx])); //Keep updating, overwriting

        } //Whole

        return record_dp_earned.back();
    }
};
