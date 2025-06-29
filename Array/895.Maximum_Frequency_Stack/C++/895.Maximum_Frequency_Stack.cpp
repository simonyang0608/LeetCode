class FreqStack {
private:
    /*Initialize*/
    ///// Record dictionary, hashmap /////
    unordered_map<int, int> record_map;

    ///// Record heap, priority-queue /////
    priority_queue<vector<int>> record_pq;

    ///// Record index /////
    int record_idx;

public:
    FreqStack() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Initialize*/
        ///// Record index /////
        (this->record_idx) = 0;
    }

    ~FreqStack()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }
    
    void push(int val) 
    {
        //=======================//
        // Input type:           //
        //   - int (input value) //
        // Return type:          //
        //   - void (no return)  //
        //=======================//

        /*Whole process, flow*/
        (((this->record_map)[val])++); //Update, Accumulate

        (this->record_pq).push({(this->record_map)[val], (this->record_idx), val}); //Update, Record

        ((this->record_idx)++); //Update, Accumulate
    }
    
    int pop() 
    {
        //========================//
        // Input type:            //
        //   - void (no input)    //
        // Return type:           //
        //   - int (result value) //
        //========================//

        /*Whole process, flow*/
        int res_val = (this->record_pq.top())[2]; //Result value

        (this->record_pq).pop(); //Update, Popped

        (((this->record_map)[res_val])--); //Update, Reduce

        return res_val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
