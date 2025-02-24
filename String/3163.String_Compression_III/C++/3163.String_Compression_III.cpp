class Solution {
public:
    string compressedString(string word) 
    {
        //============================//
        // Input type:                //
        //   - string (word string)   //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Length of word string /////
        int len_word = word.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Result string /////
        string res_str;


        /*Pointer-based loop traversal*/
        while (record_trav_ptr < len_word) //Whole
        {
            int record_cnter = 1; //Record summary counter

            while (((record_trav_ptr + 1) < len_word) && (word[record_trav_ptr] == word[(record_trav_ptr + 1)])) //Part
            {
                (record_cnter++); (record_trav_ptr++); //Keep updating, traversing

                ///// Check if the current summary counter is larger than 9 or not /////
                if (record_cnter >= 9) { break; }

            } //Part

            res_str += (to_string(record_cnter) + word[record_trav_ptr]); //Keep updating, recording

            (record_trav_ptr++); //Keep updating, traversing

        } //Whole

        return res_str;
    }
};
