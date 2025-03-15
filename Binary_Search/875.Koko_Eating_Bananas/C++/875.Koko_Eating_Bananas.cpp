class Solution {
public:
    int minEatingSpeed(vector<int> & piles, int h) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (piles vector) //
        //   - int (h-hours)                   //
        // Return type:                        //
        //   - int (result minimun value)      //
        //=====================================//

        /*Initialize*/
        ///// Length of piles vector /////
        int len_piles = piles.size();

        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 1, record_right_ptr = *max_element(piles.begin(), piles.end());


        /*Binary-search based loop traversal*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            bool record_flag = canEatAll(len_piles, piles, record_mid_ptr, h); //Record flag

            ///// Check if the current flag matched conditions or not /////
            if (record_flag) { record_right_ptr = record_mid_ptr; } //Keep updating, overwriting
            else { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }


    bool canEatAll(const int & len_piles, const vector<int> & piles, const int & record_mid_ptr, const int & h)
    {
        //=============================================//
        // Input type:                                 //
        //   - const int ref. (length of piles vector) //
        //   - const vector<int> ref. (piles vector)   //
        //   - const int ref. (record middle pointer)  //
        //   - const int ref. (h-hours)                //
        // Return type:                                //
        //   - bool (result flag)                      //
        //=============================================//

        /*Initialize*/
        ///// Result suummary hours /////
        int res_sum_hours = 0;

        /*Whole process, flow*/
        for (int piles_idx = 0; (piles_idx < len_piles); (piles_idx++)) //Whole
        {
            int record_quot = (piles[piles_idx] / record_mid_ptr); int record_mod = (piles[piles_idx] % record_mid_ptr); //Record quotient, module

            ///// Check if the current module matched conditions or not /////
            if (record_mod) { res_sum_hours += (record_quot + 1); } //Keep updating, accumulating
            else { res_sum_hours += record_quot; } //Keep updating, accumulating

            ///// Check if the current summary hours matched conditions or not /////
            if (res_sum_hours > h) { return false; }

        } //Whole

        return true;
    }
};
