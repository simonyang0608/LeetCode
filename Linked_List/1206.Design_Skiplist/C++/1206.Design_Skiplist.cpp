class Skiplist 
{
    /*Initialize*/
    ///// Record dictionary, hashmap /////
    map<int, int> record_map;

public:
    Skiplist() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }


    ~Skiplist()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }
    

    bool search(int target) 
    {
        //========================//
        // Input type:            //
        //   - int (target value) //
        // Return type:           //
        //   - bool (result flag) //
        //========================//

        /*Whole process, flow*/
        ///// Check if the current target existed or not /////
        if (((this->record_map)[target]) > 0) { return true; }

        return false;
    }
    

    void add(int num) 
    {
        //======================//
        // Input type:          //
        //   - int (num value)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Whole process, flow*/
        (((this->record_map)[num])++); //Update, Accumulate
    }
    

    bool erase(int num) 
    {
        //========================//
        // Input type:            //
        //   - int (num value)    //
        // Return type:           //
        //   - bool (result flag) //
        //========================//

        /*Whole process, flow*/
        ///// Check if the current target existed or not /////
        if (((this->record_map)[num]) <= 0) { return false; }

        (((this->record_map)[num])--); //Update, Reduce

        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
