class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int> & profits, vector<int> & capital) 
    {
        //========================================//
        // Input type:                            //
        //   - int (k-th value)                   //
        //   - int (w-th value)                   // 
        //   - vectoor<int> ref. (profits vector) //
        //   - vector<int> ref. (capital vector)  //
        // Return type:                           //
        //   - int (result maximun summary value) //
        //========================================//

        /*Initialize*/
        ///// Length of profits vector /////
        int len_profits = profits.size();

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record vector /////
        vector<pair<int, int>> record_vect;

        ///// Record heap, priority-queue /////
        priority_queue<int> record_pq;


        /*Heap, Priority-queue based loop traversal with recorded vector*/
        ///// Step 1: Record capital=profits informations with vector /////
        for (int profits_idx = 0; (profits_idx < len_profits); (profits_idx++)) //Whole
        {
            record_vect.emplace_back(capital[profits_idx], profits[profits_idx]); //Keep updating, recording

        } //Whole

        ///// Step 2: Looped-traversal for the recorded vector /////
        sort(record_vect.begin(), record_vect.end(), [&](const pair<int, int> pair_1, const pair<int, int> & pair_2)
        {
            return (pair_1.first < pair_2.first);

        }); //Sorted operations

        while ((k--)) //K-th times
        {
            while ((record_trav_ptr < len_profits) && ((record_vect[record_trav_ptr]).first <= w)) //Part
            {
                record_pq.emplace((record_vect[(record_trav_ptr++)]).second); //Keep updating, recording

            } //Part

            ///// Check if the current size is empty or not /////
            if (record_pq.empty()) { break; }

            w += record_pq.top(); record_pq.pop(); //Keep updating, accumulating

        } //K-th times

        return w;
    }
};
