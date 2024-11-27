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

        ///// Record traversal pointer /////
        int record_trav_ptr = 1;

        ///// Result, Record maximun profit /////
        int res_max_profit = 0, record_max_profit = 0;


        /*Greedy-based loop traversal*/
        while (record_trav_ptr < len_prices) //Whole
        {
            while ((record_trav_ptr < len_prices) && (prices[record_trav_ptr] >= prices[(record_trav_ptr - 1)])) //Part
            {
                record_max_profit += (prices[record_trav_ptr] - prices[(record_trav_ptr - 1)]); //Keep updating, accumulating

                (record_trav_ptr++); //Keep updating, traversing

            } //Part

            res_max_profit += record_max_profit; //Keep updating, accumulating

            ///// Check if the current profit needs to be reset or not /////
            if (record_max_profit) { record_max_profit &= 0; }
            else { ; }

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_max_profit;
    }
};
