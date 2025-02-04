class MinStack 
{
    /*Initialize*/
    ///// Record stack, min-stack /////
    stack<int> record_stack, record_stack_min;

public:
    MinStack() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }

    ~MinStack()
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
        //======================//
        // Input type:          //
        //   - int (value)      //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Whole process, flow*/
        (this->record_stack).emplace(val); //Update, Record

        ///// Check if the current stack is empty or not /////
        if ((this->record_stack_min).empty()) { (this->record_stack_min).emplace(val); } //Update, Record
        else
        {
            ///// Check if the current value matched conditions or not /////
            if (val <= (this->record_stack_min).top()) { (this->record_stack_min).emplace(val); } //Update, Record
            else { ; }
        }
    }
    
    void pop() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Whole process, flow*/
        int record_val = (this->record_stack).top(); (this->record_stack).pop(); //Record value

        ///// Check if the current value matched conditions or not /////
        if (record_val == (this->record_stack_min).top()) { (this->record_stack_min).pop(); }
        else { ; }  
    }
    
    int top() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        return (this->record_stack).top();    
    }
    
    int getMin() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        
        return (this->record_stack_min).top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
