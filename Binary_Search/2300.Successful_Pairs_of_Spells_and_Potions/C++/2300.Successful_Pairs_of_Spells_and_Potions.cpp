class Solution {
public:
    vector<int> successfulPairs(vector<int> & spells, vector<int> & potions, long long success) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (spells vector)  //
        //   - vector<int> ref. (potions vector) //
        //   - long long (success value)         //
        // Return type:                          //
        //   - vector<int> (result vector)       //
        //=======================================//

        /*Initialize*/
        ///// Length of vectors (i.e. spells, potions) /////
        int len_spells = spells.size(), len_potions = potions.size();

        ///// Result vector /////
        vector<int> res_vect;


        /*Binary-search based loop traversal with sorted-operations*/
        sort(potions.begin(), potions.end()); //Sorted-operations

        for (int spells_idx = 0; (spells_idx < len_spells); (spells_idx++)) //Whole
        {
            int record_idx = binarySearch(len_potions, potions, spells[spells_idx], success); //Record index

            res_vect.emplace_back((len_potions - record_idx)); //Keep updating, recording

        } //Whole

        return res_vect;
    }


    int binarySearch(const int & len_potions, const vector<int> & potions, const int & spells_val, 
                     const long long & success_val)
    {
        //===============================================//
        // Input type:                                   //
        //   - const int ref. (length of potions vector) //
        //   - const vector<int> ref. (potions vector)   //
        //   - const int ref. (spells value)             //
        //   - const long long ref. (success value)      //
        // Return type:                                  //
        //   - int (result index)                        //
        //===============================================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_potions - 1);

        /*Whole process, flow*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            int record_mid_ptr = (record_left_ptr + ((record_right_ptr - record_left_ptr) / 2)); //Record middle pointer

            long long record_prod = (potions[record_mid_ptr] * static_cast<long long>(spells_val)); //Record product value

            ///// Check if the current product value matched condtions or not /////
            if (record_prod < success_val) { record_left_ptr = (record_mid_ptr + 1); } //Keep updating, overwriting
            else { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting

        } //Binary-search

        return record_left_ptr;
    }
};
