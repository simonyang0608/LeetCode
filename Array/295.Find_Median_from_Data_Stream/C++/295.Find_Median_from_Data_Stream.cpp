class MedianFinder 
{
    /*Initialize*/
    ///// Record heap, priority-queues (i.e. minimun, maximun) /////
    priority_queue<int> record_pq_max;

    priority_queue<int, vector<int>, greater<int>> record_pq_min;


public:
    MedianFinder() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }

    ~MedianFinder()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }
    
    void addNum(int num) 
    {
        //======================//
        // Input type:          //
        //   - int (num value)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Whole process, flow*/
        (this->record_pq_max).emplace(num); //Update, Record

        (this->record_pq_min).emplace((this->record_pq_max).top()); //Update, Record

        (this->record_pq_max).pop(); //Update, Popped

        ///// Check if the current size is smaller or not /////
        if ((this->record_pq_max).size() < (this->record_pq_min).size())
        {
            (this->record_pq_max).emplace((this->record_pq_min).top()); //Update, Record

            (this->record_pq_min).pop(); //Update, Popped
        }
        else { ; }
    }
    

    double findMedian() 
    {
      //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
      
        return ((this->record_pq_max).size() > (this->record_pq_min).size()) ? static_cast<double>((this->record_pq_max).top()) : 
               (static_cast<double>(((this->record_pq_max).top() + (this->record_pq_min).top())) / 2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
