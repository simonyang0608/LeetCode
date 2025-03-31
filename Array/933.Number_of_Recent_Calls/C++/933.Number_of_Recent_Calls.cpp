class RecentCounter 
{
    /*Initialize*/
    ///// Record queue /////
    queue<int> record_queue;

    ///// Record times /////
    int record_times;

    ///// Previous times /////
    int prev_times;

public:
    RecentCounter() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Whole process, flow*/
        (this->prev_times) = 0; //Update, Overwrite

        (this->record_times) = ((-1) * 3000); //Update, Overwrite
    }

    ~RecentCounter()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }
    
    int ping(int t) 
    {
        //==================================//
        // Input type:                      //
        //   - int (t times)                //
        // Return type:                     //
        //   - int (result summary counter) //
        //==================================//

        /*Whole process, flow*/
        (this->record_times) += (t - (this->prev_times)); //Update, Accumulate

        (this->prev_times) = t; //Update, Overwrite

        (this->record_queue).emplace(t); //Update, Record

        while ((! (this->record_queue).empty()) && (this->record_queue).front() < (this->record_times)) //Whole
        {
            (this->record_queue).pop(); //Keep updating, popped

        } //Whole

        return (this->record_queue).size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
