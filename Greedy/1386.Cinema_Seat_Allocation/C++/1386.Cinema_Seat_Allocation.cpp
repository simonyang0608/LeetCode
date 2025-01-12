class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> & reservedSeats) 
    {
        //=====================================================//
        // Input type:                                         //
        //   - int (n-th rows)                                 //
        //   - vector<vector<int>> ref. (reservedSeats vector) //
        // Return type:                                        //
        //   - int (result maximun capacity)                   //
        //=====================================================//

        /*Initialize*/
        ///// Length of reservedSeats vector /////
        int len_reservedSeats = reservedSeats.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, vector<int>> record_map;

        ///// Bit-values (i.e. 2345, 4567, 6789) /////
        int bit_2345 = 60, bit_4567 = 240, bit_6789 = 960;

        ///// Total summary counter /////
        int total_cnter = (2 * n);


        /*Greedy-based loop traversal with bit-manipulations*/
        ///// Step 1: Record indexed-value with dictionary, hashmap /////
        for (int seats_idx = 0; (seats_idx < len_reservedSeats); (seats_idx++)) //Whole
        {
            (record_map[(reservedSeats[seats_idx])[0]]).emplace_back((reservedSeats[seats_idx])[1]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (auto record_ele = record_map.begin(); (record_ele != record_map.end()); (record_ele++)) //Whole
        {
            int record_sum_val = 0; int record_cnter = 0; //Record summary-value, counter /////

            for (const int & record_val: (record_ele->second)) //Part
            {
                record_sum_val |= (1 << record_val); //Keep updating, accumulating
                
            } //Part

            ///// Check if the current summary value matched conditions or not /////
            if ((record_sum_val & bit_2345)) { (record_cnter++); } //Keep updating, accumulating
            else { ; }

            if ((record_sum_val & bit_6789)) { (record_cnter++); } //Keep updating, accumulating
            else { ; }

            if ((! (record_sum_val & bit_4567)) && (record_cnter)) { record_cnter = 1; } //Keep updating, accumulating
            else { ; }

            total_cnter -= record_cnter; //Keep updating, reducing

        } //Whole

        return total_cnter;
    }
};
