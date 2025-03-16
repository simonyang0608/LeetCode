class StockSpanner 
{
    /*Initialize*/
    ///// Record stack /////
    stack<pair<int, int>> record_stack;

public:
    StockSpanner() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }

    ~ StockSpanner()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }
    
    int next(int price) 
    {
        //=======================//
        // Input type:           //
        //   - int (price value) //
        // Return type:          //
        //   - int (result span) //
        //=======================//

        /*Initialize*/
        ///// Record span /////
        int record_span = 1;

        /*Whole process, flow*/
        while ((! (this->record_stack.empty())) && (price >= ((this->record_stack).top()).first)) //Part
        {
            record_span += ((this->record_stack).top()).second; //Keep updating, accumulating

            (this->record_stack).pop(); //Keep updating, popped

        } //Part

        (this->record_stack).emplace(price, record_span); //Keep updating, recording

        return record_span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
