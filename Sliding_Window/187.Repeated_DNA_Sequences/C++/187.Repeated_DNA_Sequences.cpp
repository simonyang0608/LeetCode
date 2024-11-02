class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        //====================================//
        // Input type:                        //
        //   - string (s string)              //
        // Return type:                       //
        //   - vector<string> (result vector) //
        //====================================//

        /*Initialize*/
        ///// Length of string /////
        int len_s = s.size();
        len_s -= 10;

        ///// Record sub-string /////
        string record_str;

        ///// Record dictionary, hashmap /////
        unordered_map<string, int> record_map;

        ///// Result vector /////
        vector<string> res_vect;


        /*Sliding-window based loop traversal*/
        for (int s_idx = 0; (s_idx <= len_s); (s_idx++)) //Whole
        {
            record_str = s.substr(s_idx, 10); //Record sub-string

            ///// Check if the current sub-string exists or not /////
            if (record_map.find(record_str) == record_map.end())
            {
                record_map[record_str] = 1; //Keep updating, recording
            }

            else
            {
                if (record_map[record_str] < 2)
                {
                    res_vect.emplace_back(record_str); //Keep updating, recording

                    record_map[record_str] += 1; //Keep updating, accumulating
                }
                else { ; }
            }

        } //Whole

        return res_vect;
    }
};
