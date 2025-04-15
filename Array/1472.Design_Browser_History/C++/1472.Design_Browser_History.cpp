class BrowserHistory
{
    /*Initialize*/
    ///// Record vector /////
    vector<string> record_vect;

    ///// Record traversal pointer /////
    int record_trav_ptr;


public:
    BrowserHistory(string homepage) 
    {
        //==============================//
        // Input type:                  //
        //   - string (homepage string) //
        // Return type:                 //
        //   - void (no return)         //
        //==============================//

        /*Whole process, flow*/
        (this->record_vect).emplace_back(homepage); //Update, Record

        (this->record_trav_ptr) = 0; //Update, Overwrite
    }
    

    ~BrowserHistory()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }


    void visit(string url) 
    {
        //=========================//
        // Input type:             //
        //   - string (url string) //
        // Return type:            //
        //   - void (no return)    //
        //=========================//

        /*Whole process, flow*/
        ((this->record_trav_ptr)++); //Update, Traverse

        (this->record_vect).resize((this->record_trav_ptr)); //Update, Resize

        (this->record_vect).emplace_back(url); //Update, Record
    }
    

    string back(int steps) 
    {
        //============================//
        // Input type:                //
        //   - int (steps value)      //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Record updated pointers /////
        int record_upd_ptr = ((this->record_trav_ptr) - steps);

        /*Whole process, flow*/
        (this->record_trav_ptr) = (record_upd_ptr > 0) ? record_upd_ptr : 0; //Update, Overwrite

        return (this->record_vect)[(this->record_trav_ptr)];
    }
    

    string forward(int steps) 
    {
        //============================//
        // Input type:                //
        //   - int (steps value)      //
        // Return type:               //
        //   - string (result string) //
        //============================//

        /*Initialize*/
        ///// Record updated pointers /////
        int record_upd_ptr = ((this->record_trav_ptr) + steps);

        ///// Current length of vector /////
        int curr_length = ((this->record_vect).size() - 1);


        /*Whole process, flow*/
        (this->record_trav_ptr) = (record_upd_ptr < curr_length) ? record_upd_ptr : curr_length; //Update, Overwrite

        return (this->record_vect)[(this->record_trav_ptr)];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
