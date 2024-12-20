class Solution {
public:
    int canCompleteCircuit(vector<int> & gas, vector<int> & cost) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (gas vector)  //
        //   - vector<int> ref. (cost vector) //
        // Return type:                       //
        //   - int (result index)             //
        //====================================//

        /*Initialize*/
        ///// Length of gas vector /////
        int len_gas = gas.size();

        ///// Record fuel /////
        int record_fuel = 0;

        ///// Record fee /////
        int record_fee = 0;

        ///// Result index /////
        int res_idx = 0;


        /*Greedy-based loop traversal*/
        for (int record_idx = 0; (record_idx < len_gas); (record_idx++)) //Whole
        {
            record_fuel += (gas[record_idx] - cost[record_idx]); //Keep updating, accumulating

            ///// Check if the current fuel matched conditions or not /////
            if (record_fuel < 0)
            {
                res_idx = (record_idx + 1); //Keep updating, overwriting

                record_fee += record_fuel; //Keep updating, accumulating

                record_fuel &= 0; //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return ((record_fuel + record_fee) >= 0) ? res_idx : (-1);
    }
};
