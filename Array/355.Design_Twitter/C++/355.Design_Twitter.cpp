class Twitter 
{
    /*Initialize*/
    ///// Record time /////
    int record_time;

    ///// Record dictionary, hashmaps (i.e. friends, news) /////
    unordered_map<int, unordered_map<int, bool>> friends_map;
    unordered_map<int, vector<pair<int, int>>> news_map;


public:
    Twitter() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Initialize*/
        ///// Record time /////
        (this->record_time) = 0;
    }

    ~Twitter()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }
    
    void postTweet(int userId, int tweetId) 
    {
        //======================//
        // Input type:          //
        //   - int (user Id)    //
        //   - int (tweet Id)   //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Whole process, flow*/
        ((this->news_map)[userId]).emplace_back(((this->record_time)++), tweetId); //Update, Record
    }
    
    vector<int> getNewsFeed(int userId) 
    {
        //=================================//
        // Input type:                     //
        //   - int (user Id)               //
        // Return type:                    //
        //   - vector<int> (result vector) //
        //=================================//

        /*Initialize*/
        ///// Record heap, priority-queue /////
        priority_queue<pair<int, int>> record_pq;

        ///// Result vector /////
        vector<int> res_vect;


        /*Heap, Priority-queue based loop traversal*/
        ///// Step 1: Looped-traversal for the self user-Id informations /////
        for (pair<int, int> & record_pair: (this->news_map)[userId]) //Whole
        {
            record_pq.emplace(record_pair); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the remaining informations /////
        for (auto record_ele_friend: (this->friends_map)[userId]) //Whole
        {
            int friend_Id = (record_ele_friend.first); //Friend-Id

            for (pair<int, int> & record_pair: (this->news_map)[friend_Id]) //Whole
            {
                record_pq.emplace(record_pair); //Keep updating, recording

            } //Whole

        } //Whole

        for (int record_idx = (record_pq.size() < 10) ? record_pq.size() : 10; (record_idx > 0); (record_idx--)) //Fixed-size
        {
            res_vect.emplace_back((record_pq.top()).second); record_pq.pop(); //Keep updating, recording

        } //Fixed-size

        return res_vect;
    }
    
    void follow(int followerId, int followeeId) 
    {
        //=======================//
        // Input type:           //
        //   - int (follower Id) //
        //   - int (followee Id) //
        // Return type:          //
        //   - void (no return)  //
        //=======================//

        /*Whole process, flow*/
        ((this->friends_map)[followerId])[followeeId] = true; //Update, Record
    }
    
    void unfollow(int followerId, int followeeId) 
    {
        //=======================//
        // Input type:           //
        //   - int (follower Id) //
        //   - int (followee Id) //
        // Return type:          //
        //   - void (no return)  //
        //=======================//

        /*Whole process, flow*/
        ((this->friends_map)[followerId]).erase(followeeId); //Update, Record
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
