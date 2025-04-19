class Solution {
public:
    int maxProfit(int k, vector<int> & prices) 
    {
        //======================================//
        // Input type:                          //
        //   - int (k-th times)                 //
        //   - vector<int> ref. (prices vector) //
        // Return type:                         //
        //   - int (result maximun profit)      //
        //======================================//

        /*Initialize*/
        ///// Length of prices vector /////
        int len_prices = prices.size();

        ///// Record dynamic-programming vectors (i.e. earn, cost) /////
        vector<int> record_dp_earn((k + 1), 0), record_dp_cost((k + 1), INT_MIN);

        ///// Result maximun profit /////
        int res_max_profit = 0;


        /*Dynamic-programming based loop traversal*/
        for (int prices_idx = 0; (prices_idx < len_prices); (prices_idx++)) //Whole
        {
            for (int record_idx = 1; (record_idx <= k); (record_idx++)) //Whole
            {
                record_dp_cost[record_idx] = max(record_dp_cost[record_idx], (record_dp_earn[(record_idx - 1)] - 
                                                                              prices[prices_idx])); //Keep updating, overwriting
                
                record_dp_earn[record_idx] = max(record_dp_earn[record_idx], (record_dp_cost[record_idx] +
                                                                              prices[prices_idx])); //Keep updating, overwriting

                res_max_profit = (record_dp_earn[record_idx] > res_max_profit) ? record_dp_earn[record_idx] : res_max_profit; //Keep updating, overwriting

            } //Whole

        } //Whole

        return res_max_profit;
    }
};
