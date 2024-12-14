class Solution {
public:
    int countVowelSubstrings(string word) 
    {
        //==================================//
        // Input type:                      //
        //   - string (word string)         //
        // Return type:                     //
        //   - int (result summary counter) //
        //==================================//
        if (word.size() < 5) { return 0; } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Length of word string /////
        int len_word = word.size();

        ///// Record set /////
        set<char> record_set;

        record_set.insert('a');
        record_set.insert('e');
        record_set.insert('i');
        record_set.insert('o');
        record_set.insert('u');

        ///// Record dictionary, hashmap /////
        unordered_map<char, int> record_map;

        ///// Record pointers, boundary (i.e. left, right) /////
        int record_lbound, record_left_ptr = 0, record_right_ptr = 0;

        ///// Record summary counter /////
        int res_cnter = 0;


        /*Sliding-window based loop traversal with recorded dictionary, hashmap*/
        while (record_right_ptr < len_word) //Whole
        {
            ///// Check if the current indexed-char is vowel or not /////
            if (record_set.find(word[record_right_ptr]) != record_set.end())
            {
                record_lbound = record_left_ptr; //Record left boundary

                while ((record_right_ptr < len_word) && (record_set.find(word[record_right_ptr]) != record_set.end())) //Part
                {
                    record_map[word[record_right_ptr]] += 1; //Keep updating, recording

                    while (record_map.size() >= 5) //Part
                    {
                        record_map[word[record_left_ptr]] -= 1; //Keep updating, reducing

                        ///// Check if the current indexed-char existed or not /////
                        if (! record_map[word[record_left_ptr]]) { record_map.erase(word[record_left_ptr]); } //Keep updating, delete
                        else { ; }

                        (record_left_ptr++); //Keep updating, traversing

                    } //Part

                    res_cnter += (record_left_ptr - record_lbound); //Keep updating, accumulating

                    (record_right_ptr++); //Keep updating, traversing

                } //Part

                record_map.clear(); //Update, Reset

                record_left_ptr = record_right_ptr; //Keep updating, overwriting
            }

            else { (record_left_ptr++); (record_right_ptr++); } //Keep updating, traversing

        } //Whole

        return res_cnter;
    }   
};
