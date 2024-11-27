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

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 1;

        ///// Record value (i.e. left-part)
        int record_left_val;

        ///// Result maximun profit /////
        int res_max_profit = 0;


        /*Two-pointers based loop traversal*/
        while ((record_right_ptr < len_prices)) //Whole
        {
            record_left_val = prices[record_left_ptr]; //Record value (i.e. left-part)

            while ((record_right_ptr < len_prices) && (prices[record_right_ptr] >= record_left_val)) //Part
            {
                ///// Check if the current difference, window matched conditions or not /////
                if ((prices[record_right_ptr] - record_left_val) > res_max_profit)
                {
                    res_max_profit = (prices[record_right_ptr] - record_left_val); //Keep updating, overwriting
                }

                (record_right_ptr++); //Keep updating, traversing

            } //Part

            record_left_ptr = (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return res_max_profit;
    }
};
