class Solution {
public:
    int compress(vector<char> & chars) 
    {
        //======================================//
        // Input type:                          //
        //   - vector<char> ref. (chars vector) //
        // Return type:                         //
        //   - int (result length)              //
        //======================================//

        /*Initialize*/
        ///// Length of chars vector /////
        int len_chars = chars.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result vector /////
        vector<char> res_vect;


        /*Pointer-based loop traversal*/
        while (record_trav_ptr < len_chars) //Whole
        {
            int record_cnter = 1; //Record summary counter

            while (((record_trav_ptr + 1) < len_chars) && (chars[record_trav_ptr] == chars[(record_trav_ptr + 1)])) //Part
            {
                (record_cnter++); (record_trav_ptr++); //Keep updating, traversing

            } //Part

            res_vect.emplace_back(chars[record_trav_ptr]); //Keep updating, recording

            ///// Check if the current summary counter is 1 or not /////
            if (record_cnter == 1) { ; }
            else
            {
                for (const char & record_chr: to_string(record_cnter)) //Whole
                {
                    res_vect.emplace_back(record_chr); //Keep updating, recording

                } //Whole
            }

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        chars = res_vect; //Update, Overwrite

        return chars.size();
    }
};
