class Solution {
public:
    bool isPerfectSquare(int num) 
    {
        //========================//
        // Input type:            //
        //   - int (num value)    //
        // Return type:           //
        //   - bool (result flag) //
        //========================//

        /*Initialize*/
        ///// Record powers, num value /////
        unsigned long long record_pow, record_num = (unsigned long long)(num);

        ///// Record pointers (i.e. middle, left, right) /////
        unsigned long long record_mid_ptr, record_left_ptr = 1, record_right_ptr = record_num;


        /*Binary-search based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Binary-search
        {
            record_mid_ptr = ((unsigned long long)(record_left_ptr + record_right_ptr) / 2); //Record middle pointer

            record_pow = ((unsigned long long)(record_mid_ptr) * (unsigned long long)(record_mid_ptr)); //Record powers

            ///// Check if the current powers matched conditions or not /////
            if (record_pow < record_num) { record_left_ptr = (record_mid_ptr + 1); }
            else if (record_pow > record_num) { record_right_ptr = (record_mid_ptr - 1); }

            else { return true; }

        } //Binary-search

        return false;
    }
};
