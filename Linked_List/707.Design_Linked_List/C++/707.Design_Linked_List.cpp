class MyLinkedList {
public:

    /*Initialize*/
    ///// Total length index /////
    int length_idx;

    ///// List-nodes (i.e. traversal, record, result) /////
    ListNode * list_node, * record_node, * res_node;


public:
    MyLinkedList() 
    {
        /*Initialize*/
        ///// Total length index /////
        length_idx = (-1);

        ///// List-nodes (i.e. traversal, record, result) /////
        list_node = NULL;
        record_node = NULL;
        res_node = NULL;
    }

    ~ MyLinkedList() { ; }
    
    int get(int index) 
    {
        //==================================//
        // Input type:                      //
        //   - int (target index)           //
        // Return type:                     //
        //   - int (result list-node value) //
        //==================================//
        if (index < 0) { return (-1); } //Issue, Boundary-case handling

        else if (index >= (length_idx + 1)) { return (-1); } //Issue, Boundary-case handling

        /*Initialize*/
        ///// Result list-node /////
        res_node = list_node;

        /*Whole process, flow*/
        for (int index_idx = 0; (index_idx < index); (index_idx++)) //Indexed 
        {
            res_node = (res_node->next); //Keep updating, overwriting

        } //Indexed

        return (res_node->val);
    }
    
    void addAtHead(int val) 
    {
        //==================================//
        // Input type:                      //
        //   - int (target value)           //
        // Return type:                     //
        //   - void (no return)             //
        //==================================//

        /*Whole process, flow*/
        res_node = new ListNode(val); //Result list-node

        (res_node->next) = list_node; //Update, Overwrite

        list_node = res_node; //Update, Overwrite

        (length_idx++); //Update, Accumulate
    }
    
    void addAtTail(int val) 
    {
        //==================================//
        // Input type:                      //
        //   - int (target value)           //
        // Return type:                     //
        //   - void (no return)             //
        //==================================//
        if (! list_node) { addAtHead(val); } //Issue, Boundary-case handling

        else
        {
            /*Initialize*/
            ///// Result list-node /////
            res_node = list_node;

            /*Whole process, flow*/
            while (res_node && (res_node->next)) //Whole
            {
                res_node = (res_node->next); //Keep updating, overwriting

            } //Whole

            (res_node->next) = new ListNode(val); //Update, Overwrite

            (length_idx++); //Update, Accumulate
        }
    }
    
    void addAtIndex(int index, int val) 
    {
        //==================================//
        // Input type:                      //
        //   - int (target index)           //
        //   - int (target value)           //
        // Return type:                     //
        //   - void (no return)             //
        //==================================//
        if (index > (length_idx + 1)) { return; } //Issue, Boundary-case handling

        else if (index < 0) { return; } //Issue, Boundary-case handling

        else if (! index) { addAtHead(val); } //Issue, Boundary-case handling
        else if (index == (length_idx + 1)) { addAtTail(val); } //Issue, Boundary-case handling

        else
        {
            /*Initialize*/
            ///// Result list-node /////
            res_node = list_node;

            /*Whole process, flow*/
            (index--); //Update, Reduce

            for (int index_idx = 0; (index_idx < index); (index_idx++)) //Indexed
            {
                res_node = (res_node->next); //Keep updating, Overwriting

            } //Indexed

            record_node = (res_node->next); //Record list-node

            (res_node->next) = new ListNode(val); //Update, Overwrite

            ((res_node->next)->next) = record_node; //Update, Overwrite

            (length_idx++); //Update, Accumulate
        }
    }
    
    void deleteAtIndex(int index) 
    {
        //========================//
        // Input type:            //
        //   - int (target index) //
        // Return type:           //
        //   - void (no return)   //
        //========================//
        if (index >= (length_idx + 1)) { return; } //Issue, Boundary-case handling

        else if (index < 0) { return; } //Issue, Boundary-case handling

        else if (! index) //Issue, Boundary-case handling
        {
            list_node = (list_node->next); //Update, Overwrite

            (length_idx--); //Update, Reduce
        }

        else
        {
            /*Initialize*/
            ///// Result list-node /////
            res_node = list_node;

            /*Whole process, flow*/
            (index--); //Update, Reduce

            for (int index_idx = 0; (index_idx < index); (index_idx++)) //Indexed
            {
                res_node = (res_node->next); //Keep updating, overwriting

            } //Indexed

            (res_node->next) = ((res_node->next)->next); //Update, Overwrite

            (length_idx--); //Update, Reduce
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
