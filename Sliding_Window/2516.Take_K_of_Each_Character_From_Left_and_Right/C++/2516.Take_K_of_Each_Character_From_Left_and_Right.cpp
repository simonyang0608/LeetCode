class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        //================================//
        // Input type:                    //
        //   - string (s string)          //
        //   - int (k-th counter)         //
        // Return type:                   //
        //   - int (result minimun times) //
        //================================//
        if (! k) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of s string /////
        int len_s = s.size();

        ///// Record summary counter vector /////
        vector<int> record_vect_cnter(3, 0);

        ///// Record vector
        vector<bool> record_vect(3, false);

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = 0;

        ///// Record length /////
        int record_length = 0;

        ///// Result maximun length /////
        int res_max_length = 0;


        /*Sliding-window based loop traversal with recorded vectors*/
        ///// Step 1: Record indexed-char informations with vectors /////
        for (int s_idx = 0; (s_idx < len_s); (s_idx++))
        {
            int record_symb = (s[s_idx] - 'a'); //Record symbol

            ((record_vect_cnter[record_symb])++); //Keep updating, accumulating

            ///// Check if the current summary counter matched conditions or not /////
            if (record_vect_cnter[record_symb] >= k)
            {
                ///// Check if the current char is visited or not /////
                if (! record_vect[record_symb])
                {
                    record_vect[record_symb] = true; //Keep updating, recording

                    (record_length++); //Keep updating, accumulating
                }
                else { ; }
            }
            else { ; }
        }

        ///// Step 2: Looped-traversal with recorded vectors /////
        if (record_length < 3) { return (-1); } //Issue, Boundary-case handling

        while (record_right_ptr < len_s) //Whole
        {
            int record_symb = (s[record_right_ptr] - 'a'); //Record symbol

            ((record_vect_cnter[record_symb])--); //Keep updating, reducing

            ///// Check if the current summary counter matched conditions or not /////
            if (record_vect_cnter[record_symb] < k)
            {
                ///// Check if the current char is visited or not /////
                if (record_vect[record_symb]) 
                {
                    record_vect[record_symb] = false; //Keep updating, recording

                    (record_length--); //Keep updating, reducing
                }
                else { ; }
            }

            ///// Check if the current length matched conditions or not /////
            if (record_length >= 3)
            {
                res_max_length = max(res_max_length, (record_right_ptr - record_left_ptr + 1)); //Keep updating, overwriting
            }
            else
            {
                while ((record_left_ptr <= record_right_ptr) && (record_length < 3)) //Part
                {
                    int record_symb = (s[record_left_ptr] - 'a'); //Record symbol

                    ((record_vect_cnter[record_symb])++); //Keep updating, accumulating

                    ///// Check if the current summary counter matched conditions or not /////
                    if (record_vect_cnter[record_symb] >= k)
                    {
                        ///// Check if the current char is visited or not /////
                        if (! record_vect[record_symb])
                        { 
                            record_vect[record_symb] = true; //Keep updating, recording

                            (record_length++); //Keep updating, accumulating
                        }
                        else { ; }
                    }
                    else { ; }

                    (record_left_ptr++); //Keep updating, traversing

                } //Part
            }

            (record_right_ptr++); //Keep updating, traversing

        } //Whole

        return (len_s - res_max_length);
    }
};
