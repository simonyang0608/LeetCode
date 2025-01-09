class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string> & bank) 
    {
        //=======================================//
        // Input type:                           //
        //   - string (startGene string)         //
        //   - string (endGene string)           //
        //   - vector<string> ref. (bank vector) //
        // Return type:                          //
        //   - int (result minimun steps)        //
        //=======================================//

        /*Initiaize*/
        ///// Length of bank vector /////
        int len_bank = bank.size();

        ///// Record visited dictionary, hashmap /////
        map<string, bool> visit_map;

        ///// Record visited vector /////
        vector<int> visit_vect(len_bank, 0);

        ///// Record queue /////
        queue<pair<string, int>> record_queue;


        /*Breath-first search based loop traversal*/
        record_queue.push(make_pair(startGene, 0)); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                string record_str = (record_queue.front()).first; int res_step = (record_queue.front()).second; //Record, Result string, steps

                record_queue.pop(); //Keep updating, popped

                ///// Check if the current string is visited or not /////
                if (visit_map.find(record_str) != visit_map.end()) { continue; }

                ///// Check if the current string matched conditions or not /////
                if (record_str == endGene) { return res_step; }

                visit_map[record_str] = true; //Keep updating, recording

                for (int bank_idx = 0; (bank_idx < len_bank); (bank_idx++)) //Whole
                {
                    ///// Check if the current string is visited or not /////
                    if (visit_vect[bank_idx]) { continue; }

                    ///// Check if the current differences of char matched conditions or not /////
                    if (difChar(record_str, bank[bank_idx]) == 1)
                    { 
                        record_queue.push(make_pair(bank[bank_idx], (res_step + 1))); //Keep updating, recording

                        visit_vect[bank_idx] = 1; //Keep updating, overwriting
                    }
                    else { ; }

                } //Whole

            } //Queue-size

        } //Cycled-times

        return (-1);
    }


    int difChar(const string & record_str, const string & bank_str)
    {
        //=======================================//
        // Input type:                           //
        //   - const string ref. (record string) //
        //   - const string ref. (bank string)   //
        // Return type:                          //
        //   - int (result summary counter)      //
        //=======================================//

        /*Initialize*/
        int res_cnter = 0;

        /*Whole process, flow*/
        for (int str_idx = 0; (str_idx < 8); (str_idx++)) //Whole
        {
            ///// Check if the current char is different or not /////
            if (record_str[str_idx] != bank_str[str_idx]) { (res_cnter++); } //Keep updating, accumulating
            else { ; }

        } //Whole

        return res_cnter;
    }
};
