class Solution {
public:
    bool judgeCircle(string moves) 
    {
        //===========================//
        // Input type:               //
        //   - string (moves string) //
        // Return type:              //
        //   - bool (result flag)    //
        //===========================//

        /*Initialize*/
        ///// Length of moves string /////
        int len_moves = moves.size();

        ///// Record hashmap, dictionary /////
        unordered_map<char, int> record_map;

        record_map['L'] = 0;
        record_map['R'] = 0;
        record_map['U'] = 0;
        record_map['D'] = 0;


        /*Simple differences & comparisons based loop traversal with recorded hashmap, dictionary*/
        ///// Step 1: Record indexed-char with hashmap, dictionary /////
        for (int moves_idx = 0; (moves_idx < len_moves); (moves_idx++)) //Whole
        {
            record_map[moves[moves_idx]] += 1; //Keep updating, recording

        } //Whole

        ///// Step 2: Check if the current hashmap matched conditions or not /////
        if ((record_map['L'] == record_map['R']) && (record_map['U'] == record_map['D'])) { return true; }

        return false;
    }
};
