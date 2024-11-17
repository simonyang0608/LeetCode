class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
        //====================================//
        // Input type:                        //
        //   - string (digits)                //
        // Return type:                       //
        //   - vector<string> (result vector) //
        //====================================//

        /*Initialize*/
        ///// Length of digits /////
        int len_digits = digits.size();

        ///// Record hashmap, dictionary /////
        map<char, vector<char>> record_map;

        record_map['2'] = {'a', 'b', 'c'};
        record_map['3'] = {'d', 'e', 'f'};
        record_map['4'] = {'g', 'h', 'i'};
        record_map['5'] = {'j', 'k', 'l'};
        record_map['6'] = {'m', 'n', 'o'};
        record_map['7'] = {'p', 'q', 'r', 's'};
        record_map['8'] = {'t', 'u', 'v'};
        record_map['9'] = {'w', 'x', 'y', 'z'};

        ///// Record string /////
        string record_str;

        ///// Result vector /////
        vector<string> res_vect;


        /*Back-track based loop traversal with recorded hashmap, dictionary*/
        if (! len_digits) { return res_vect; } //Issue, Boundary-case handling

        for (char record_char: record_map[digits[0]]) //Indexed
        {
            backtrackTraversal(len_digits, digits, 1, record_map, (record_str + record_char), res_vect); //Recursion function call

        } //Indexed

        return res_vect;
    }

    void backtrackTraversal(int & len_digits, string & digits, int digits_idx, map<char, vector<char>> & record_map, string record_str, vector<string> & res_vect)
    {
        //===============================================================//
        // Input type:                                                   //
        //   - int ref. (length of digits)                               //
        //   - string ref. (digits)                                      //
        //   - int (index of digits)                                     //
        //   - map<char, vector<char>> ref. (record hashmap, dictionary) //
        //   - string (record string)                                    //
        //   - vector<string> ref. (result vector)                       //
        // Return type:                                                  //
        //   - void (no return)                                          //
        //===============================================================//
        if (digits_idx >= len_digits) //Issue, Boundary-case handling
        {
            res_vect.emplace_back(record_str); //Update, Record

            return;
        }

        /*Whole process, flow*/
        for (char record_char: record_map[digits[digits_idx]]) //Indexed
        {
            backtrackTraversal(len_digits, digits, (digits_idx + 1), record_map, (record_str + record_char), res_vect); //Recursion function call

        } //Indexed
    }
};
