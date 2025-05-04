class Solution {
public:
    int minimumCardPickup(vector<int> & cards) 
    {
        //=====================================//
        // Input type:                         //
        //   - vector<int> ref. (cards vector) //
        // Return type:                        //
        //   - int (result minimun length)     //
        //=====================================//

        /*Initialize*/
        ///// Length of cards vector /////
        int len_cards = cards.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record flag /////
        bool record_flag = false;

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Result minimun length /////
        int res_min_length = INT_MAX;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        while (record_right_ptr < len_cards) //Whole
        {
            ((record_map[cards[record_right_ptr]])++); //Keep updating, accumulating

            record_flag |= (record_map[cards[record_right_ptr]] >= 2) ? true : false; //Keep updating, overwriting

            while (record_flag) //Part
            {
                res_min_length = min(res_min_length, (record_right_ptr - record_left_ptr + 1)); //Keep updating, overwriting
                
                ((record_map[cards[record_left_ptr]])--); //Keep updating, reducing

                record_flag &= (record_map[cards[record_left_ptr]] == 1) ? false : true; //Keep updating, overwriting

                (record_left_ptr++); //Keep updating, traversing

            } //Part

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return (res_min_length == INT_MAX) ? (-1) : res_min_length;
    }
};
