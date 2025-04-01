class Solution {
public:
    vector<string> sortPeople(vector<string> & names, vector<int> & heights) 
    {
        //========================================//
        // Input type:                            //
        //   - vector<string> ref. (names vector) //
        //   - vector<int> ref. (heights vector)  //
        // Return type:                           //
        //   - vector<string> (result vector)     //
        //========================================//

        /*Initialize*/
        ///// Length of names vector /////
        int len_names = names.size();

        ///// Record heap, priority-queue /////
        priority_queue<pair<int, string>> record_pq;

        ///// Result vector /////
        vector<string> res_vect;


        /*Heap, Priority-queue based loop traversal*/
        ///// Step 1: Record personal informations with heap, priority-queue /////
        for (int names_idx = 0; (names_idx < len_names); (names_idx++)) //Whole
        {
            record_pq.emplace(heights[names_idx], names[names_idx]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal with recorded heap, priority-queue /////
        while (! record_pq.empty()) //Cycled-times
        {
            res_vect.emplace_back((record_pq.top()).second); //Keep updating, recording

            record_pq.pop(); //Keep updating, popped

        } //Cycled-times

        return res_vect;
    }
};
