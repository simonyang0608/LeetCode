class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) 
    {
        //==================================//
        // Input type:                      //
        //   - string (croakOfFrogs string) //
        // Return type:                     //
        //   - int (result minimun frogs)   //
        //==================================//

        /*Initialize*/
        ///// Length of croakOfFrogs string /////
        int len_croakOfFrogs = croakOfFrogs.size();

        ///// Record dictionary, hashmap (i.e. char) /////
        unordered_map<char, int> record_map;

        ///// Record dictionary, hashmap (i.e. summary counter) /////
        unordered_map<int, int> record_map_cnter;

        ///// Record frogs /////
        int record_frog = 0;

        ///// Result minimun summary counter /////
        int res_min_cnter = 0;


        /*Hashmap-based loop traversal*/
        record_map['c'] = 0; record_map['r'] = 1; record_map['o'] = 2;
        record_map['a'] = 3; record_map['k'] = 4; //Update, Record

        for (int croakOfFrogs_idx = 0; (croakOfFrogs_idx < len_croakOfFrogs); (croakOfFrogs_idx++)) //Whole
        {
            ///// Check if the current indexed-char matched conditions or not /////
            if (croakOfFrogs[croakOfFrogs_idx] == 'c')
            {
                ((record_map_cnter[record_map[croakOfFrogs[croakOfFrogs_idx]]])++); //Keep updating, recording

                (record_frog++); res_min_cnter = max(res_min_cnter, record_frog); //Keep updating, overwriting
            }

            else if (croakOfFrogs[croakOfFrogs_idx] == 'k')
            {
                ///// Check if the previous summary counter is less than 0 or not /////
                if ((--(record_map_cnter[(record_map[croakOfFrogs[croakOfFrogs_idx]] - 1)])) < 0) { return (-1); }

                (record_frog--); //Keep updating, reducing
            }

            else
            {
                ///// Check if the previous summary counter is less than 0 or not /////
                if ((--(record_map_cnter[(record_map[croakOfFrogs[croakOfFrogs_idx]] - 1)])) < 0) { return (-1); }

                ((record_map_cnter[record_map[croakOfFrogs[croakOfFrogs_idx]]])++); //Keep updating, recording
            }

        } //Whole

        return (! record_frog) ? res_min_cnter : (-1);
    }
};
