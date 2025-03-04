class SmallestInfiniteSet 
{
    /*Initialize*/
    ///// Record heap, priority-queue /////
    priority_queue<int, vector<int>, greater<int>> record_pq;

    ///// Record dictionary, hashmap /////
    map<int, bool> record_map;

public:
    SmallestInfiniteSet() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Whole process, flow*/
        for (int num_idx = 1; (num_idx <= 1000); (num_idx++)) //Whole
        {
            (this->record_pq).emplace(num_idx); //Keep updating, recording

            ((this->record_map)[num_idx]) = true; //Keep updating, recording

        } //Whole
    }

    ~ SmallestInfiniteSet()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }
    
    int popSmallest() 
    {
        //========================//
        // Input type:            //
        //   - void (no input)    //
        // Return type:           //
        //   - int (result value) //
        //========================//

        /*Whole process, flow*/
        int res_val = (this->record_pq).top(); (this->record_pq).pop(); //Update, Popped

        (this->record_map).erase(res_val); //Update, Erase

        return res_val;
    }
    
    void addBack(int num) 
    {
        //======================//
        // Input type:          //
        //   - int (num value)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Whole process, flow*/
        ///// Check if the current num existed or not /////
        if (! (this->record_map)[num]) { (this->record_pq).emplace(num); (this->record_map)[num] = true; } //Update, Record
        else { ; }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */
