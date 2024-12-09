class Solution {
public:
    bool isNStraightHand(vector<int> & hand, int groupSize) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (hand vector) //
        //   - int (group size)               //
        // Return type:                       //
        //   - bool (result flag)             //
        //====================================//

        /*Initialize*/
        ///// Length of hand vector /////
        int len_hand = hand.size();

        ///// Sorted operations /////
        sort(hand.begin(), hand.end());

        ///// Record traversal pointer /////
        int record_trav_ptr = 0;

        ///// Record heap, priority-queue /////
        priority_queue<pair<int, int>> record_pq;


        /*Heap, Priority-queue based loop traversal*/
        while (record_trav_ptr < len_hand) //Whole
        {
            ///// Step 1: Record indexed-values, summary counters with heap, priority-queue /////
            while ((! record_pq.empty()) && (((((record_pq.top()).first) * (-1)) + 1) < hand[record_trav_ptr])) //Part
            {
                ///// Check if the current summary counter matched conditions or not /////
                if ((((record_pq.top()).second) * (-1)) < groupSize) { return false; }

                record_pq.pop(); //Keep updating, popped

            } //Part

            ///// Check if the current indexed-value matched conditions or not /////
            if ((! record_pq.empty()) && (((((record_pq.top()).first) * (-1)) + 1) == hand[record_trav_ptr]))
            {
                ///// Check if the current summary counter matched conditions or not /////
                if ((((record_pq.top()).second) * (-1)) < groupSize)
                {
                    record_pq.push(make_pair(((-1) * hand[record_trav_ptr]), ((((record_pq.top()).second) - 1)))); //Keep updating, pushed
                    record_pq.pop(); //Keep updating, popped
                }
                else { record_pq.push(make_pair(((-1) * hand[record_trav_ptr]), (-1))); } //Keep updating, pushed
            }

            else { record_pq.push(make_pair(((-1) * hand[record_trav_ptr]), (-1))); } //Keep updating, pushed

            (record_trav_ptr++); //Keep updating, traversing
             
        } //Whole

        ///// Step 2: Looped-traversal with recorded heap, priority-queue /////
        while (! record_pq.empty()) //Whole
        {
            ///// Check if the current summary counter matched conditions or not /////
            if ((((record_pq.top()).second) * (-1)) != groupSize) { return false; }

            record_pq.pop(); //Keep updating, popped

        } //Whole

        return true;
    }
};
