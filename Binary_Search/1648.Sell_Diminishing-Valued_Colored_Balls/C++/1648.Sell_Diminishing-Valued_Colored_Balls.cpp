class Solution {
public:
    int maxProfit(vector<int> & inventory, int orders) 
    {
        //=========================================//
        // Input type:                             //
        //   - vector<int> ref. (inventory vector) //
        //   - int (orders value)                  //
        // Return type:                            //
        //   - int (result maximun summary value)  //
        //=========================================//

        /*Initialize*/
        ///// Length of inventory vector /////
        int len_inventory = inventory.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record module /////
        int record_module = (1e9 + 7);

        ///// Result maximun summary value /////
        long long res_max_sum = 0;


        /*Binary-search based loop traversal*/
        ///// Step 1: Looped-traversal for searching for the critical value point /////
        sort(inventory.rbegin(), inventory.rend()); //Sorted operations

        record_right_ptr = inventory.front(); //Update, Overwrite

        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            bool record_flag = isValid(len_inventory, inventory, orders, record_mid_ptr); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (record_flag) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
             
        } //Binary-search

        ///// Step 2: Looped-traversal for the remainings /////
        for (int inventory_idx = 0; (inventory_idx < len_inventory); (inventory_idx++)) //Whole
        {
            ///// Check if the current indexed-value exceed boundary or not /////
            if (inventory[inventory_idx] <= record_right_ptr) { break; }

            orders -= (inventory[inventory_idx] - record_right_ptr); //Keep updating, reducing

            res_max_sum += (((static_cast<long long>(inventory[inventory_idx]) * (static_cast<long long>(inventory[inventory_idx]) + 1)) / 2) - 
                            ((static_cast<long long>(record_right_ptr) * (static_cast<long long>(record_right_ptr) + 1)) / 2)); //Keep updating, accumulating

            res_max_sum %= record_module; //Keep updating, moduling

        } //Whole

        res_max_sum += (static_cast<long long>(orders) * static_cast<long long>(record_right_ptr)); //Update, Accumulate
        
        res_max_sum %= record_module; //Update, Module

        return res_max_sum;
    }


    bool isValid(const int & len_inventory, const vector<int> & inventory, const int & orders, 
                 const int & record_val)
    {
        //=================================================//
        // Input type:                                     //
        //   - const int ref. (length of inventory vector) //
        //   - const vector<int> ref. (inventory vector)   //
        //   - cosnt int ref. (orders value)               //
        //   - const int ref. (record value)               //
        // Return type:                                    //
        //   - bool (result flag)                          //
        //=================================================//

        /*Initialize*/
        ///// Result summary counter /////
        long long res_cnter = 0;

        /*Whole process, flow*/
        for (int inventory_idx = 0; (inventory_idx < len_inventory); (inventory_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (inventory[inventory_idx] < record_val) { break; }

            res_cnter += (inventory[inventory_idx] - record_val + 1); //Keep updating, accumulating

            ///// Check if the current summary counter matched conditions or not /////
            if (res_cnter > orders) { return false; }

        } //Whole

        return true;
    }
};
