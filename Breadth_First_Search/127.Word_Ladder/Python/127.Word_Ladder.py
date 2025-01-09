class Solution(object):
    def ladderLength(self, beginWord, endWord, wordList):
        """
        :type beginWord: str
        :type endWord: str
        :type wordList: List[str]
        :rtype: int
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of beginWord string, wordList array #####
        len_beginWord, len_wordList = len(beginWord), len(wordList)

        ##### Record visited dictionary/hashmap #####
        visit_dict = {}

        ##### Record visited array #####
        visit_arry = [0 for _ in range(len_wordList)]

        ##### Record queue #####
        record_queue = [[beginWord, 1]]


        ##########################################
        #Breath-first search based loop traversal
        while (record_queue):
            queue_size = len(record_queue) #Queue-size

            for queue_idx in range(queue_size):
                record_str, res_step = (record_queue[0])[0], (record_queue[0])[1] #Record, Result string, steps

                record_queue.pop(0) #Keep updating/popped

                ##### Check if the current string matched conditions or not #####
                if (record_str == endWord):
                    return res_step

                ##### Check if the current string is visited or not #####
                if (record_str in visit_dict):
                    continue

                visit_dict[record_str] = True #Keep updating/recording

                for wordList_idx in range(len_wordList):

                    ##### Check if the current string is visited or not #####
                    if (visit_arry[wordList_idx]):
                        continue

                    ##### Check if the current differences of char matched conditions or not #####
                    if (self.difChar(len_beginWord, record_str, wordList[wordList_idx]) == 1):
                        record_queue.append([wordList[wordList_idx], (res_step + 1)]) #Keep updating/recording

                        visit_arry[wordList_idx] = 1 #Keep updating/overwriting
                    else:
                        pass

        return 0


    def difChar(self, len_beginWord, record_str, word_str):
        """
        :type len_beginWord int
        :type record_str: str
        :type word_str: str
        :rtype: int
        """

        ############
        #Initialize
        ##### Result summary counter #####
        res_cnter = 0

        ####################
        #Whole process/flow
        for record_idx in range(len_beginWord):

            ##### Check if the current char is different or not #####
            if (record_str[record_idx] != word_str[record_idx]):
                res_cnter += 1 #Keep updating/accumulating
            else:
                pass

        return res_cnter
