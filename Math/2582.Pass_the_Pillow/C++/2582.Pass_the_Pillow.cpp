class Solution {
public:
    int passThePillow(int n, int time) 
    {
        //========================//
        // Input type:            //
        //   - int (n people)     //
        //   - int (time seconds) //
        // Return type:           //
        //   - int (result index) //
        //========================//

        /*Initialize*/
        ///// Record times, remainings /////
        int record_times = (time / (n - 1)), record_remains = (time % (n - 1));

        /*Greedy-based loop traversal with recorded times, remainings*/
        ///// Check if the current times is odd or even /////
        if (! (record_times % 2)) { return (1 + record_remains); }

        return (n - record_remains);
    }
};
