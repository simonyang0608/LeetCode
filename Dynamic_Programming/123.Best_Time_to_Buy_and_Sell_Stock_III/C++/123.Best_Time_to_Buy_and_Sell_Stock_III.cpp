class Solution {
public:
    int maxProfit(vector<int> & prices) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<int> ref. (prices vector) //
        // Return type:                         //
        //   - int (result maximun profit)      //
        //======================================//

        /*Initialize*/
        ///// Length of prices vector /////
        int len_prices = prices.size();

        ///// Record dynamic-programming vectors (i.e. earn, cost) /////
        vector<int> record_dp_earn(3, 0), record_dp_cost(3, INT_MIN);

        ///// Result maximun value /////
        int res_max_val = 0;


        /*Dynamic-programming (i.e. DP) based loop traversal*/
        for (int prices_idx = 0; (prices_idx < len_prices); (prices_idx++)) //Whole
        {
            for (int record_idx = 1; (record_idx <= 2); (record_idx++)) //Twice
            {
                record_dp_cost[record_idx] = max(record_dp_cost[record_idx], 
                                                (record_dp_earn[(record_idx - 1)] - prices[prices_idx])); //Keep updating, overwriting

                record_dp_earn[record_idx] = max(record_dp_earn[record_idx], 
                                                (record_dp_cost[record_idx] + prices[prices_idx])); //Keep updating, overwriting

                res_max_val = (record_dp_earn[record_idx] > res_max_val) ? record_dp_earn[record_idx] : res_max_val; //Keep updating, overwriting

            } //Twice

        } //Whole

        return res_max_val;
    }
};
