class TopVotedCandidate 
{
    /*Initialize*/
    ///// Record, Lead vectors /////
    vector<int> record_vect, lead_vect;

public:
    TopVotedCandidate(vector<int> & persons, vector<int> & times) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (persons vector) //
        //   - vector<int> ref. (times vector)   //
        // Return type:                          //
        //   - void (no return)                  //
        //=======================================//

        /*Initialize*/
        ///// Total length /////
        int total_length = persons.size();

        ///// Record dictionary, hashmap /////
        unordered_map<int, int> record_map;

        ///// Record maximun summary counter /////
        int record_max_cnter;


        /*Whole process, flow*/
        (this->lead_vect).emplace_back(persons[0]); //Update, Record

        ((record_map[persons[0]])++); //Update, Record

        record_max_cnter = 1; //Update, Overwrite

        for (int persons_idx = 1; (persons_idx < total_length); (persons_idx++)) //Whole
        {
            (this->lead_vect).emplace_back((this->lead_vect).back()); //Keep updating, recording

            ((record_map[persons[persons_idx]])++); //Keep updating, recording

            ///// Check if the current summary counter mathced conditions or not /////
            if (record_map[persons[persons_idx]] >= record_max_cnter)
            {
                record_max_cnter = record_map[persons[persons_idx]]; //Keep updating, overwriting

                (this->lead_vect).back() = persons[persons_idx]; //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        (this->record_vect) = vector<int>(times.begin(), times.end()); //Keep updating, overwriting
    }

    ~TopVotedCandidate()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }
    
    int q(int t) 
    {
        //=========================//
        // Input type:             //
        //   - int (t-times value) //
        // Return type:            //
        //   - int (result id)     //
        //=========================//

        /*Initialize*/
        ///// Record pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = ((this->record_vect).size() - 1);

        /*Whole process, flow*/
        while (record_left_ptr < record_right_ptr) //Binary-search
        {
            int record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) / 2); //Record middle pointer

            ///// Check if the current times matched conditions or not /////
            if ((this->record_vect)[record_mid_ptr] > t) { record_right_ptr = (record_mid_ptr - 1); } //Keep updating, overwriting
            else { record_left_ptr = record_mid_ptr; } //Keep updating, overwriting

        } //Binary-search

        return (this->lead_vect)[record_left_ptr];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
