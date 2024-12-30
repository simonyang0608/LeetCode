class Solution {
public:
    int findRadius(vector<int> & houses, vector<int> & heaters) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (houses vector)  //
        //   - vector<int> ref. (heaters vector) //
        // Return type:                          //
        //   - int (result minimun radius)       //
        //=======================================//

        /*Initialize*/
        ///// Length of vectors (i.e. houses, heaters) /////
        int len_houses = houses.size(), len_heaters = heaters.size();

        ///// Record minimun radius /////
        int record_min_radius = (1e9 + 3);

        ///// Result maximun radius /////
        int res_max_radius = 0;


        /*Binary-search based loop traversal*/
        sort(houses.begin(), houses.end()); //Sorted operations
        sort(heaters.begin(), heaters.end()); //Sorted operations

        for (int houses_idx = 0; (houses_idx < len_houses); (houses_idx++)) //Whole
        {
            binarySearch(heaters, houses[houses_idx], record_min_radius); //Binary-search function call

            res_max_radius = max(res_max_radius, record_min_radius); //Keep updating, overwriting

            record_min_radius = (1e9 + 3); //Keep updating, reset
        }

        return res_max_radius;
    }


    void binarySearch(vector<int> & heaters, int & record_val, int & record_min_radius)
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (heaters vector) //
        //   - int ref. (record value)           //
        //   - int ref. (record minimun radius)  //
        // Return type:                          //
        //   - void (no return)                  //
        //=======================================//

        /*Initialize*/
        ///// Record pointers (i.e. middle, left, right) /////
        int record_mid_ptr, record_left_ptr = 0, record_right_ptr = (heaters.size() - 1);

        /*Whole process, flow*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((record_left_ptr + record_right_ptr) / 2); //Keep updating, overwriting

            ///// Check if the current indexed-value matched conditions or not /////
            if (heaters[record_mid_ptr] < record_val) 
            {
                record_min_radius = min(record_min_radius, (record_val - heaters[record_mid_ptr])); //Keep updating, overwriting

                record_left_ptr = (record_mid_ptr + 1); //Keep updating, overwriting
            }
            else
            {
                record_min_radius = min(record_min_radius, (heaters[record_mid_ptr] - record_val)); //Keep updating, overwriting

                record_right_ptr = (record_mid_ptr - 1); //Keep updating, overwriting
            }

        } //Binary-search
    }
};
