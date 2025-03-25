class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        //=============================//
        // Input type:                 //
        //   - string (pattern string) //
        //   - string (s string)       //
        // Return type:                //
        //   - bool (result flag)      //
        //=============================//

        /*Initialize*/
        ///// Length of strings (i.e. pattern, s) /////
        int len_pattern = pattern.size(), len_s = s.size();

        ///// Record traversal pointers (i.e. pattern, s) /////
        int record_trav_ptrp = 0, record_trav_ptrs = 0;

        ///// Record dictionary, hashmap (i.e. char-string) /////
        unordered_map<char, string> record_map_cs;

        ///// Record dictionary, hashmap (i.e. string-char) /////
        unordered_map<string, char> record_map_sc;


        /*Hashmap-based loop traversal*/
        while (record_trav_ptrs < len_s) //Whole
        {
            string record_str; //Record string

            while ((record_trav_ptrs < len_s) && (s[record_trav_ptrs] != ' ')) //Part
            {
                record_str += s[(record_trav_ptrs++)]; //Keep updating, recording

            } //Whole

            ///// Check if the current pointer exceed boundary or not /////
            if (record_trav_ptrp < len_pattern)
            {
                ///// Check if the current char existed or not /////
                if (! (record_map_cs[pattern[record_trav_ptrp]]).empty())
                {
                    ///// Check if the current key-value is matched or not /////
                    if (record_map_cs[pattern[record_trav_ptrp]] != record_str) { return false; }
                }
                else { record_map_cs[pattern[record_trav_ptrp]] = record_str; } //Keep updating, recording

                ///// Check if the current string existed or not /////
                if (record_map_sc[record_str])
                {
                    ///// Check if the current key-value is matched or not /////
                    if (record_map_sc[record_str] != pattern[record_trav_ptrp]) { return false; }
                }
                else { record_map_sc[record_str] = pattern[record_trav_ptrp]; } //Keep updating, recording

                (record_trav_ptrp++); //Keep updating, traversing
            }
            else { return false; }

            (record_trav_ptrs++); //Keep updating, traversing
        }

        return (record_trav_ptrp >= len_pattern) ? true : false;
    }
};
