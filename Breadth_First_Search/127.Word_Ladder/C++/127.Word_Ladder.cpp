class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> & wordList) 
    {
        //===========================================//
        // Input type:                               //
        //   - string (beginWord string)             //
        //   - string (endWord string)               //
        //   - vector<string> ref. (wordList vector) //
        // Return type:                              //
        //   - int (result minimun steps)            //
        //===========================================//

        /*Initialize*/
        ///// Length of begin-word string, word-list vector /////
        int len_beginWord = beginWord.size(), len_wordList = wordList.size();

        ///// Record visited dictionary, hashmap /////
        map<string, bool> visit_map;

        ///// Record visited vector /////
        vector<int> visit_vect(len_wordList, 0);

        ///// Record queue /////
        queue<pair<string, int>> record_queue;


        /*Breath-first search based loop traversal*/
        record_queue.push(make_pair(beginWord, 1)); //Update, Record

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_size = record_queue.size(); (queue_size > 0); (queue_size--)) //Queue-size
            {
                string record_str = (record_queue.front()).first; int res_step = (record_queue.front()).second; //Record, Result string, steps

                record_queue.pop(); //Keep updating, popped

                ///// Check if the current string matched conditions or not /////
                if (record_str == endWord) { return res_step; }

                ///// Check if te current string is visited or not /////
                if (visit_map.find(record_str) != visit_map.end()) { continue; }

                visit_map[record_str] = true; //Keep updating, recording

                for (int wordList_idx = 0; (wordList_idx < len_wordList); (wordList_idx++)) //Whole
                {
                    ///// Check if the current string is visited or not /////
                    if (visit_vect[wordList_idx]) { continue; }

                    ///// Check if the current differences of char matched conditions or not /////
                    if (difChar(len_beginWord, record_str, wordList[wordList_idx]) == 1)
                    { 
                        record_queue.push(make_pair(wordList[wordList_idx], (res_step + 1))); //Keep updating, recording

                        visit_vect[wordList_idx] = 1; //Keep updating, overwriting
                    }
                    else { ; }

                } //Whole

            } //Queue-size

        } //Cycled-times

        return 0;
    }


    int difChar(const int & len_beginWord, const string & record_str, const string & word_str)
    {
        //=================================================//
        // Input type:                                     //
        //   - const int ref. (length of beginWord string) //
        //   - const string ref. (record string)           //
        //   - const string ref. (wordList string)         //
        // Return type:                                    //
        //   - int (result summary counter)                //
        //=================================================//

        /*Initialize*/
        ///// Result summary counter /////
        int res_cnter = 0;

        /*Whole process, flow*/
        for (int record_idx = 0; (record_idx < len_beginWord); (record_idx++)) //Whole
        {
            ///// Check if the current char is different or not /////
            if (record_str[record_idx] != word_str[record_idx]) { (res_cnter++); } //Keep updating, accumulating
            else { ; }

        } //Whole

        return res_cnter;
    }
};
