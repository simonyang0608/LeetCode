class Twitter(object):
    def __init__(self):
        """
        :type None, void
        :rtype: None, void
        """

        ############
        #Initialize
        ##### Record times #####
        self.record_times = 0

        ##### Record dictionary/hashmaps (i.e. friends, news) #####
        self.friends_dict, self.news_dict = {}, {}


    def postTweet(self, userId, tweetId):
        """
        :type userId: int
        :type tweetId: int
        :rtype: None
        """

        ####################
        #Whole process/flow
        ##### Check if the current user-Id existed or not #####
        if (userId not in self.news_dict):
            (self.news_dict)[userId] = [[(self.record_times * (-1)), tweetId]] #Update/Record
        else:
            ((self.news_dict)[userId]).append([(self.record_times * (-1)), tweetId]) #Update/Record

        self.record_times += 1 #Update/Accumulate
        

    def getNewsFeed(self, userId):
        """
        :type userId: int
        :rtype: List[int]
        """

        ############
        #Initialize
        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Result array #####
        res_arry = []


        ####################
        #Whole process/flow
        heapify(record_pq) #Update/Heapify

        ##### Check if the current user-Id existed or not #####
        if (userId in self.news_dict):
            for main_news in (self.news_dict)[userId]:
                heappush(record_pq, main_news) #Keep updating/recording
        else:
            pass

        ##### Check if the current user-Id existed or not #####
        if (userId in self.friends_dict):
            for minor_friend in (self.friends_dict)[userId]:

                ##### Check if the current minor-friend existed or not #####
                if (minor_friend in self.news_dict):
                    for minor_news in (self.news_dict)[minor_friend]:
                        heappush(record_pq, minor_news) #Keep updating/recording
                else:
                    pass
        else:
            pass

        min_size = (len(record_pq) if (len(record_pq) < 10) else 10) #Minimun-size

        for record_idx in range(min_size, 0, (-1)):
            res_arry.append((record_pq[0])[1]) #Keep updating/recording

            heappop(record_pq) #Keep updating/popped

        return res_arry
        

    def follow(self, followerId, followeeId):
        """
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """

        ####################
        #Whole process/flow
        ##### Check if the current follower-Id existed or not #####
        if (followerId not in self.friends_dict):
            (self.friends_dict)[followerId] = {followeeId: True} #Update/Record
        else:
            ((self.friends_dict)[followerId])[followeeId] = True #Update/Record
        

    def unfollow(self, followerId, followeeId):
        """
        :type followerId: int
        :type followeeId: int
        :rtype: None
        """

        ####################
        #Whole process/flow
        ##### Check if the current follower-Id existed or not #####
        if (followerId in self.friends_dict):

            ##### Check if the current followee-Id existed or not #####
            if (followeeId in (self.friends_dict)[followerId]):
                del ((self.friends_dict)[followerId])[followeeId] #Update/Delete
            else:
                pass
        else:
            pass


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)
